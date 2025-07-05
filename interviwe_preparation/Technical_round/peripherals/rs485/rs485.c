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
