/*
 * Modbus Communication Protocol - Detailed Explanation
 *
 * Definition:
 * Modbus is an industrial serial communication protocol developed in 1979 by Modicon.
 * It is widely used for communication between automation devices such as PLCs, sensors, and controllers.
 *
 * Characteristics:
 * - Uses a master-slave architecture.
 * - Supports serial (Modbus RTU, Modbus ASCII) and Ethernet (Modbus TCP) communication.
 * - Simple and efficient protocol for industrial automation.
 *
 * Modbus Communication Types:
 * 1. Modbus RTU - Binary format, efficient for serial communication.
 * 2. Modbus ASCII - Human-readable format, used in older systems.
 * 3. Modbus TCP - Uses Ethernet for faster communication.
 *
 * Modbus Frame Structure:
 * - Address Field: Identifies the slave device.
 * - Function Code: Specifies the operation (read/write).
 * - Data Field: Contains the requested data.
 * - CRC (Cyclic Redundancy Check): Ensures data integrity.
 *
 * Function Codes:
 * - 01: Read Coils
 * - 02: Read Discrete Inputs
 * - 03: Read Holding Registers
 * - 04: Read Input Registers
 * - 05: Write Single Coil
 * - 06: Write Single Register
 * - 15: Write Multiple Coils
 * - 16: Write Multiple Registers
 *
 * Modbus is an application-layer protocol used to exchange data between industrial devices.
 * While RS-232 and RS-485 define the physical electrical signals, 
 * Modbus defines the structure of the message (the "language") sent over those signals. 
 * In an interview, explain that moving from raw serial to Modbus requires adding a software protocol 
 * layer to your existing hardware setup

 * 1. Hardware Requirements 
 * Modbus does not require unique hardware beyond the transceivers (MAX232 or MAX485) you already have. 
 * However, it imposes strict requirements on physical stability: 
 * Termination: You must use 120 ohm termination resistors at both ends of an RS-485 bus 
 * to prevent signal reflections that corrupt Modbus packets.
 * Biasing: For RS-485, you may need pull-up/pull-down resistors on the A and B lines to 
 * ensure the bus stays in a known "Idle" state when no one is talking

 * 2. Software Changes (Protocol Implementation)
 * You must wrap your raw UART data into a Modbus RTU Frame. A standard message looks like this: 
 * Slave ID (1 byte): The unique address of the device (1–247).
 * Function Code (1 byte): Tells the device what to do (e.g., 03 to read registers, 06 to write one).
 * Data (N bytes): Contains the register addresses and the values being sent/requested.
 * CRC (2 bytes): A Cyclic Redundancy Check for error detection. The receiver recalculates this 
 * to ensure no bits were flipped during transmission.

 * 3. Timing Requirements (The "Silent" Interval)
 * This is a critical software change unique to Modbus RTU:
 * 3.5-Character Gap: Modbus identifies the start and end of a message by "silence." 
 * You must ensure no data is sent for at least 3.5 character times (e.g., ~1.75ms at 19200 baud) 
 * before and after a packet.
 * Inter-character Timeout: All bytes within a single message must be sent with a gap no larger 
 * than 1.5 character times, or the receiver will discard the packet as broken.

 * 4. Memory Mapping
 * You must organize your code's data into the four standard Modbus tables: 
 * Coils (0x): Read/Write bits (e.g., turning a relay ON/OFF).
 * Discrete Inputs (1x): Read-only bits (e.g., a limit switch state).
 * Input Registers (3x): Read-only 16-bit values (e.g., temperature sensor data).
 * Holding Registers (4x): Read/Write 16-bit values (e.g., setting a PWM duty cycle).

 * Summary for the Interviewer
 * "To use Modbus, I keep my current UART-to-RS485/232 hardware but implement a software 
 * driver that packs data into frames with a Slave ID and CRC. I then map my internal variables to 
 * Modbus Registers so other industrial equipment can read them using standard function codes"

 * Advantages:
 * - Open protocol, widely supported in industrial automation.
 * - Simple implementation with minimal overhead.
 * - Supports multiple devices on a single network.
 *
 * Limitations:
 * - No built-in security features.
 * - Limited error handling compared to modern protocols.
 * - Requires proper addressing and timing for reliable communication.
 *
 * Applications:
 * - Industrial automation and control systems.
 * - SCADA (Supervisory Control and Data Acquisition).
 * - Communication between sensors, actuators, and controllers.
 *
 * Summary:
 * Modbus remains a widely used protocol in industrial automation due to its simplicity and reliability.
 * Proper implementation ensures efficient data exchange between devices.
 */
