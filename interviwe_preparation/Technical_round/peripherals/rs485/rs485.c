/*
 * RS485 Serial Communication Protocol - Detailed Explanation
 *
 * Definition:
 * RS485 is a differential serial communication protocol designed for reliable data transmission
 * over long distances and in electrically noisy environments. It is widely used in industrial automation,
 * embedded systems, and networking applications.
 *
 * Characteristics:
 * - Supports both half-duplex and full-duplex communication.
 * - Uses differential signaling to reduce noise interference.
 * - Allows multiple devices (up to 32 nodes) on a single bus.
 * - Higher data rates compared to RS232 (up to 10 Mbps).
 *
 * Electrical Specifications:
 * - Differential voltage signaling (A and B lines).
 *   Logic HIGH (1):
 *              - Occurs when the voltage on Line A is higher than Line B.
 *              - Differential voltage (V_A - V_B) is typically ≥ +200mV.
 *              - Interpreted as a binary '1' in RS485 communication.
 * 
 *   Logic LOW (0):
 *              - Occurs when the voltage on Line A is lower than Line B.
 *              - Differential voltage (V_A - V_B) is typically ≤ -200mV.
 *              - Interpreted as a binary '0' in RS485 communication.
 * - Common-mode rejection improves noise immunity.
 * - Maximum cable length: ~1200 meters.
 * - Baud rates range from 300 bps to 10 Mbps.
 *
 * Pin Configuration (Typical RS485 Connector):
 * - A (Data Line Positive)
 * - B (Data Line Negative)
 * - GND (Ground)
 *
 * Communication Modes:
 * - Half-Duplex: Devices take turns transmitting and receiving.
 * - Full-Duplex: Simultaneous bidirectional communication using two pairs of wires.
 *
 
 * To interface a UART (TTL level) with an RS-485 system using a transceiver like the MAX485, 
 * you must implement specific hardware and software changes to handle its half-duplex nature. 
 
 * 1. Hardware Changes (Mandatory) Unlike RS-232, which is point-to-point, 
 * RS-485 is a differential bus designed for long distances and multi-device (multi-drop) networks. 
 * Transceiver IC: Use a MAX485 (for 5V logic) or MAX3485 (for 3.3V logic).
 * Direction Control Pins: Unlike UART or RS-232, you must control when the chip is "listening" versus "talking."
 * RE (Receiver Enable): Active Low (0V to receive).
 * DE (Driver Enable): Active High (5V/3.3V to transmit).
 * Common Setup: Tie RE and DE together and connect them to a single GPIO pin on your microcontroller.
 * Termination Resistor: Place a 120 (Omega) resistor across the A and B lines at both extreme ends 
 * of the bus to prevent signal reflections.
 * Twisted Pair Cable: Use shielded twisted pair cabling (A and B lines) for maximum noise immunity over 
 * long distances (up to 1,200 meters). 
 
 * 2. Pin-to-Pin Connection 
 * Microcontroller (UART/GPIO) MAX485 Pin (Logic Side)   MAX485 Pin (Bus Side)  Signal Type
 8 TX                          Pin 4 (DI)                Pin 6 (A)              Non-Inverting (+)
 * RX                          Pin 1 (RO)                Pin 7 (B)              Inverting (-)
 * GPIO (Control)              Pin 2 & 3 (RE/DE)         —                      Direction Toggle
 * VCC (5V/3.3V)               Pin 8 (VCC)               —                      Power
 * GND                         Pin 5 (GND)               —                      Common Ground

 * 3. Software Changes
 * Because RS-485 is typically half-duplex, you cannot send and receive at the same time. Your code must 
 * manage the bus direction:
 * Default State: Set the Control GPIO Low (Receive Mode). This ensures you are always listening for data from other devices.
 * Before Transmitting: Set the Control GPIO High (Transmit Mode).
 * Transmission: Use your standard UART_Transmit() function.
 * Crucial Step (Wait for Flush): After sending data, you must wait for the UART hardware 
 * to finish shifting the very last bit out of the physical wire before switching back to receive mode. 
 * Switching too early will truncate your message.
 * After Transmitting: Set the Control GPIO Low again to return to listening mode.

 * Summary: RS-485 vs RS-232
 * Feature 	           RS-232	                                 RS-485
 * Duplex	             Full-Duplex (can talk/listen at once)	 Half-Duplex (must take turns)
 * Distance	           Short (~15m)	                           Very Long (1,200m)
 * Multi-device	       Point-to-point (2 devices)	             Multi-drop (up to 32 nodes)
 * Signal	             Single-ended (referenced to GND)	       Differential (A vs B)

 * To achieve Full-Duplex communication with RS-485,
 * you must move from a 2-wire system to a 4-wire system (plus a common ground). 
 * This setup allows the Master and Slave to send and receive data at the same time, similar to RS-422. 
 * 1. Hardware Changes Transceiver Selection: You need a specific Full-Duplex Transceiver IC (e.g., MAX491, SN65HVD3086E, or ADM3063E).
 * Alternative: You can use two MAX485 chips per node (one dedicated to TX and one to RX),
 * but a single full-duplex chip is more efficient.
 * Wiring (4-Wire + Ground): You must use two separate twisted pairs:
 * Pair 1: Master TX (Y/Z) connected to all Slave RX (A/B).
 * Pair 2: Slave TX (Y/Z) connected to Master RX (A/B).
 * Termination: You now need two termination resistors (120 Omega ) per pair—one at the Master and one at the most distant Slave.
 * 2. Pin-to-Pin Connection (Typical 14-pin IC like MAX491) 
 * Microcontroller Pin       Full-Duplex IC Pin       Bus Side (Differential)
 * UART TX                   DI (Driver Input)        Y (+) and Z (-) (Transmit Pair)
 * UART RX                   RO (Receiver Output)     A (+) and B (-) (Receive Pair)
 * GPIO (Control)            DE (Driver Enable)       Set High to talk (Master can often stay High)
 * GPIO (Control)            RE (Receiver Enable)     Set Low to always listen

 * 3. Software Changes Continuous Listening: Because you have a dedicated pair for receiving, 
 * you no longer need to switch your transceiver to "Receive Mode" after every transmission. 
 * You can keep RE (Receiver Enable) grounded (permanently enabled).
 * Simplified Timing: You do not need to wait for the UART "Flush" or "TC" (Transmission Complete) 
 * flag before switching modes, as there is no direction switching required in a basic Point-to-Point 
 * full-duplex setup.
 * Collision Handling: While the Master can talk while a Slave is responding, 
 * in a Multi-drop setup (one Master, many Slaves), you still need a protocol to ensure two Slaves 
 * don't try to talk to the Master at the same time on the shared return pair. 

 * Summary: Full-Duplex vs. Half-Duplex 
 * Feature     Half-Duplex (Standard)       Full-Duplex
 * Wires       2 Wires + Ground             4 Wires + Ground
 * IC Pins     8-pin (e.g., MAX485)         14-pin (e.g., MAX491)
 * Data Flow   One way at a time            Both ways simultaneously
 * Complexity  Higher software              Higher hardware (extra wiring/pins)

 * Network Topology:
 * - Multi-drop bus architecture.
 * - Supports master-slave and peer-to-peer communication.
 * - Requires termination resistors to prevent signal reflections.
 *
 * Advantages:
 * - Long-distance communication capability.
 * - High noise immunity due to differential signaling.
 * - Supports multiple devices on a single bus.
 *
 * Limitations:
 * - Requires proper termination to avoid signal degradation.
 * - More complex wiring compared to RS232.
 * - Needs driver ICs for proper voltage level conversion.
 *
 * Applications:
 * - Industrial automation and control systems.
 * - Data acquisition and sensor networks.
 * - Building management systems (BMS).
 * - Modbus RTU communication.
 *
 * Summary:
 * RS485 is a robust and efficient serial communication protocol, ideal for industrial and embedded applications.
 * Its differential signaling and multi-device support make it superior to RS232 for long-distance communication.
 */
