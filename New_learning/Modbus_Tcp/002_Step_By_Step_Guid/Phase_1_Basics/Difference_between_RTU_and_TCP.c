

/* 🔄 Difference Between Modbus RTU and Modbus TCP */

/* 📡 Modbus RTU (Remote Terminal Unit)
 * - Communication Type: Serial (RS232/RS485)
 * - Data Format: Binary
 * - Frame Structure: Compact (no IP headers)
 * - Speed: Slower compared to Ethernet
 * - Use Case: Local, point-to-point or multi-drop connections
 * - Reliability: Needs strict timing; sensitive to noise
 */

/* 🌐 Modbus TCP (Transmission Control Protocol)
 * - Communication Type: Ethernet/IP based
 * - Data Format: Encapsulated Modbus RTU frame inside TCP/IP packet
 * - Frame Structure: Includes IP/TCP headers
 * - Speed: Faster, supports high data rates
 * - Use Case: LAN/WAN networks, remote access, SCADA systems
 * - Reliability: More robust, uses TCP for error checking and retransmission
 */

/* 🧠 Summary
 * Modbus RTU is best for short-distance, simple setups using serial cables.
 * Modbus TCP is ideal for modern Ethernet-based networks with faster, reliable communication.
 */
/* 📦 Difference Between Modbus RTU Frame and Modbus TCP Frame */

/* 🔗 Modbus RTU Frame Format (Serial Communication)
 * - Protocol: Modbus over RS232/RS485
 * - Frame Structure:
 *     [Slave Address][Function Code][Data][CRC]
 * - CRC: 2-byte Cyclic Redundancy Check for error detection
 * - Timing: Requires silent intervals between frames (inter-frame delay)
 * - Example:
 *     0x01 0x03 0x00 0x00 0x00 0x02 0xC4 0x0B
 */

/* 🌐 Modbus TCP Frame Format (Ethernet Communication)
 * - Protocol: Modbus over TCP/IP (Port 502)
 * - Frame Structure:
 *     [MBAP Header][Function Code][Data]
 * - MBAP Header (7 bytes):
 *     - Transaction ID (2 bytes)
 *     - Protocol ID (2 bytes, always 0)
 *     - Length (2 bytes)
 *     - Unit ID (1 byte, same as Slave Address)
 * - No CRC (TCP handles error checking)
 * - Example:
 *     0x00 0x01 0x00 0x00 0x00 0x06 0x01 0x03 0x00 0x00 0x00 0x02
 */

/* 🧠 Summary:
 * - RTU uses serial lines and includes CRC for error detection.
 * - TCP uses Ethernet/IP and relies on TCP for reliability.
 * - RTU frames are compact and timing-sensitive.
 * - TCP frames include a header for transaction tracking and are easier to scale.
 */
