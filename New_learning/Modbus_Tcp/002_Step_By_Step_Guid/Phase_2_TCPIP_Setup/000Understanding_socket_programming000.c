/* 🧠 Why Socket Programming Helps Before Modbus TCP */

/* 🚪 Modbus TCP uses sockets under the hood.
 * - Your client connects to an IP address and port (usually 502).
 * - Data is exchanged in structured frames over that connection.
 * - Sockets are what let computers "talk" over a network.
 */

/* 🛠️ Key Concepts You Should Know:
 * - What is a socket?
 *     → An endpoint for sending/receiving data between computers
 *
 * - Client vs Server roles:
 *     → Client initiates communication, Server listens for requests
 *
 * - TCP protocol:
 *     → Ensures reliable delivery of data, used by Modbus TCP
 *
 * - IP + Port:
 *     → IP identifies the device, port identifies the service (e.g., Modbus is 502)
 *
 * - Basic socket API in C:
 *     → socket(), connect(), send(), recv(), close()
 */

/* ✅ Benefit:
 * If you know socket programming in C, using libmodbus becomes easier to understand.
 * You'll know what’s really happening during modbus_connect() and modbus_read_registers().
 */

