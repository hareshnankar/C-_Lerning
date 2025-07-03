/*
 * Serial Peripheral Interface (SPI) - Detailed Explanation
 *
 * Definition:
 * SPI is a synchronous serial communication protocol used for high-speed data exchange
 * between microcontrollers and peripheral devices such as sensors, displays, and memory chips.
 *
 * SPI Bus Components:
 * - **Master Device**: Controls the communication and generates the clock signal.
 * - **Slave Device(s)**: Responds to the master's commands, multiple slaves can be connected.
 * - **SPI Signals**:
 *   - **MOSI (Master Out Slave In)**: Data sent from master to slave.
 *   - **MISO (Master In Slave Out)**: Data sent from slave to master.
 *   - **SCLK (Serial Clock)**: Synchronizes data transmission.
 *   - **SS (Slave Select)**: Activates a specific slave device.
 *
 * SPI Communication Process:
 * 1. Master pulls SS line LOW to select a slave.
 * 2. Master generates the clock signal (SCLK).
 * 3. Master sends data on MOSI while slave responds via MISO.
 * 4. Master deactivates SS (HIGH) to end communication.
 *
 * SPI Modes (Clock Polarity & Phase):
 * | Mode | CPOL | CPHA | Clock Behavior               |
 * |------|------|------|------------------------------|
 * |  0   |  0 (Clock starts LOW when ideal )   |  0(first transaction of signal(voltage level))    | reciver (recive data) on rising edge and transmitter update(send) on falling edge |
 * |  1   |  0 (Clock starts LOW when ideal )   |  1(second transaction of signal(voltage level))   | reciver (recive data) on falling edge and transmitter update(send) on rising edge  |
 * |  2   |  1 (Clock starts HIGH when ideal)   |  0(first transaction of signal(voltage level))    | reciver (recive data) on falling edge and transmitter update(send) on rising edge  |
 * |  3   |  1 (Clock starts HIGH when ideal)   |  1(second transaction of signal(voltage level))   | reciver (recive data) on rising edge and transmitter update(send) on falling edge |
 *
 * SPI Speed Calculation
 *
 * SPI Speed (bps) = Clock Frequency (Hz) × Bits per Transfer
 *
 * Example:
 * - Clock Frequency = 10 MHz
 * - Bits per Transfer = 8 (Standard SPI Byte)
 * - SPI Speed = 10,000,000 × 8 = 80 Mbps
 *
 * Factors Affecting SPI Speed:
 * - Clock Frequency (SCLK): Higher frequency increases data transfer rate.
 * - SPI Mode (CPOL, CPHA): Defines timing of data sampling and shifting.
 * - Microcontroller Limitations: Some devices have max SPI clock limits.
 * - Bus Length & Noise: Longer cables and interference can reduce effective speed.
 *
/*
 * Typical SPI Speed Ranges
 *
 * SPI (Serial Peripheral Interface) supports different speed levels depending on
 * the hardware capabilities of microcontrollers, sensors, displays, and memory chips.
 *
 * | Speed Category        | Typical Range    | Application Examples                               |
 * |-----------------------|----------------  |------------------------------------------------    |
 * | Low-Speed SPI         | 100 kHz - 1 MHz  | Basic sensors, low-speed peripherals               |
 * | Standard SPI          | 1 MHz - 25 MHz   | Microcontroller communication, ADCs                |
 * | High-Speed SPI        | 25 MHz - 100 MHz | Fast memory chips, TFT/OLED displays               |
 * | Ultra-High-Speed SPI  | 100 MHz+         | Specialized applications, high-speed data transfer |
 *
 * Factors Affecting SPI Speed:
 * - **Microcontroller Limitations**: Each MCU has a max supported SPI clock.
 * - **Peripheral Constraints**: Devices like EEPROMs and sensors have speed limits.
 * - **Bus Length & Noise**: Longer cables and signal interference can degrade speed.
 * - **Clock Configuration**: The SPI clock (SCLK) directly defines data transfer rate.
 *
 * Summary:
 * - SPI speed varies based on hardware capabilities and signal integrity.
 * - Higher speeds enable faster communication but may require optimized wiring.
 * - Selecting the right SPI frequency ensures reliable and efficient data exchange.
 * 
 * Advantages:
 * - High-speed data transfer (faster than I2C).
 * - Full-duplex communication (simultaneous send & receive).
 * - Simple hardware implementation with minimal overhead.
 *
 * Limitations:
 * - Requires separate SS lines for each slave.
 * - No built-in error-checking or arbitration.
 * - Limited scalability for multiple slave devices.
 *
 * Applications:
 * - Communication with sensors (accelerometers, gyroscopes).
 * - Display interfaces (OLED, TFT, LCD).
 * - Storage devices (Flash memory, SD cards).
 * - High-speed data transfer in embedded systems.
 *
 * Summary:
 * SPI is a powerful serial communication protocol ideal for high-speed embedded applications.
 * Proper SPI configuration ensures reliable and efficient data exchange.
 */
