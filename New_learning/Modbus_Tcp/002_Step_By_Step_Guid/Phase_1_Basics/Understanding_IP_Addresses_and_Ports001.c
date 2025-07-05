/* 🌐 Understanding IP Addresses and Ports – Networking Fundamentals */

/* 🧭 IP Address
 * - Stands for Internet Protocol Address
 * - Unique identifier for a device on a network
 * - Format:
 *     IPv4: Four numbers separated by dots (e.g., 192.168.1.10)
 *     IPv6: Longer, hexadecimal notation (e.g., 2001:0db8:85a3::8a2e:0370:7334)
 * - Types:
 *     - Public IP: Globally reachable
 *     - Private IP: Used within local networks (e.g., 192.168.x.x, 10.x.x.x)
 */

/* 🎯 Port Number
 * - Logical channel for communication with a service on a device
 * - Range: 0 to 65535
 * - Common examples:
 *     - 80 (HTTP)
 *     - 443 (HTTPS)
 *     - 502 (Modbus TCP)
 *     - 21 (FTP), 22 (SSH)

 * When a device wants to send data to another, it uses:
 *     - Destination IP address (where to go)
 *     - Port number (which service to talk to)
 */

/* 🔄 Example (Modbus TCP):
 * - Device IP: 192.168.0.100
 * - Port: 502
 * - Modbus client sends request to 192.168.0.100:502

 * Behind the scenes:
 *   - TCP/IP stack routes the packet to that IP
 *   - Device listens for connections on port 502
 *   - Response is returned to the sender's IP and port
 */

/* 🔐 Summary
 * IP = Addressing (location of device)
 * Port = Channel for specific service/application
 * Together they form an endpoint like: 192.168.1.10:502
 */
