/*
 * Universal Asynchronous Receiver-Transmitter (UART) - Detailed Explanation
 *
 * Definition:
 * UART is a serial communication protocol that transmits and receives data asynchronously,
 * meaning no clock signal is required for synchronization.
 *
 * UART Frame Structure:
 * | Start | Data (8 bits) | Parity (Optional) | Stop |
 *
 * UART Communication Process:
 * 1. **Start Bit**: Signals the beginning of transmission (low level).
 * 2. **Data Bits**: Typically 8 bits, but can be 5, 6, 7, or 9 bits.
 * 3. **Parity Bit (Optional)**: Used for error detection (Even, Odd, None).
 * 4. **Stop Bit(s)**: Marks the end of transmission (1 or 2 bits).
 *
 * UART Parameters:
 * - **Baud Rate**: Defines the speed of data transmission (e.g., 9600, 115200 bps).
 * - **Data Bits**: Specifies the number of bits in each transmission frame.
 * - **Parity Bit**: Used for basic error checking.
 * - **Stop Bits**: Indicates the end of a UART frame (1 or 2 bits).
 *
 * Advantages:
 * - Simple hardware implementation (only TX and RX lines).
 * - No need for a clock signal (asynchronous communication).
 * - Supports error detection using parity bits.
 *
 * Limitations:
 * - Limited speed compared to SPI or I2C.
 * - Only supports direct two-device communication.
 * - No built-in error correction beyond parity checking.
 *
 * Applications:
 * - Microcontroller-to-PC communication (serial consoles).
 * - Wireless modules (Bluetooth, GPS, Zigbee).
 * - Debugging interfaces in embedded systems.
 * - Data exchange between sensors and processors.
 *
 * Summary:
 * UART is an efficient asynchronous communication protocol widely used in embedded systems.
 * Proper configuration ensures reliable data transfer.
 */
