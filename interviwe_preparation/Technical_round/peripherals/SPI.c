<!doctype html>
<html lang="en">
<head>
<meta charset="utf-8">
<meta name="viewport" content="width=device-width,initial-scale=1">
<title>adc.c — A4 printable (larger font)</title>
<style>
  html,body { height:100%; margin:0; padding:0; background:#fff; color:#000; }
  /* A4 print area and margins */
  @page { size: A4; margin: 15mm; }
  body { padding: 0; margin: 0; }

  /* The content area equals printable width: 210mm - 2*15mm = 180mm */
  .sheet {
    box-sizing: border-box;
    width: 180mm;               /* printable content width */
    min-height: 297mm;
    padding: 0;
    margin: 0 auto;
    background: white;
  }

  /* Title and source (non-file content) */
  .title { font-family: sans-serif; font-size: 16pt; margin: 6mm 0 4mm 0; }
  .sourceurl { font-family: sans-serif; font-size: 9pt; color:#444; margin-bottom:6mm; }

  /* Larger, readable monospace font for multiple pages */
  pre {
    font-family: "Courier New", Courier, monospace;
    font-size: 14pt;           /* BIGGER font as requested */
    line-height: 1.28;
    white-space: pre;          /* preserve spaces and line breaks exactly */
    overflow-wrap: anywhere;   /* allow breaking long sequences to fit the printable width */
    word-break: break-all;     /* ensures long repeated characters won't create horizontal overflow */
    margin: 0;
    padding: 0;
    tab-size: 4;
  }

  @media print {
    .sheet { box-shadow: none; margin: 0; }
    .title, .sourceurl { color: #000; }
  }
</style>
</head>
<body>
  <pre>

/*
 * Serial Peripheral Interface (SPI) - Detailed Explanation (Single master in standerd way but can be 
 * multimaster using software and hardware 1master at time)
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
 * =================================================================================
 * SPI MODES: THE SIMPLE MEMORY RULE
 * =================================================================================
 *
 * RULE 1 (CPOL): "Where does the clock start?"
 * - CPOL 0: Starts LOW (Idle is 0)
 * - CPOL 1: Starts HIGH (Idle is 1)
 *
 * RULE 2 (CPHA): "Which edge do I Read (Sample) on?"
 * - CPHA 0: Read on the FIRST transition (the first move from idle)
 * - CPHA 1: Read on the SECOND transition (the return move)
 *
 * ---------------------------------------------------------------------------------
 * | MODE | CPOL | CPHA | IDLE LEVEL | SAMPLE (READ) EDGE | SHIFT (WRITE) EDGE |
 * |------|------|------|------------|--------------------|--------------------|
 * |  0   |  0   |  0   |   LOW      |   Rising (1st)     |   Falling (2nd)    |
 * |  1   |  0   |  1   |   LOW      |   Falling (2nd)    |   Rising (1st)     |
 * |  2   |  1   |  0   |   HIGH     |   Falling (1st)    |   Rising (2nd)     |
 * |  3   |  1   |  1   |   HIGH     |   Rising (2nd)     |   Falling (1st)    |
 * ---------------------------------------------------------------------------------
 *
 * MEMORY TRICK:
 * - If CPOL == CPHA (Mode 0 & 3): You always sample on a RISING edge.
 * - If CPOL != CPHA (Mode 1 & 2): You always sample on a FALLING edge.
 * =================================================================================
 */
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

/*
 * ===========================================================================
 * I2C VS. SPI PROTOCOL COMPARISON (ARCHITECTURAL DIFFERENCES)
 * ===========================================================================
 *
 * | Feature          | I2C Protocol                 | SPI Protocol          |
 * |------------------|------------------------------|-----------------------|
 * | Communication    | Half-Duplex                  | Full-Duplex           |
 * | Flow Control     | Supported (Clock Stretching) | Not Standard          |
 * | Device Selection | Software Addressing          | Hardware Selection    |
 * | Verification     | ACK/NACK after every byte    | No Inherent Check     |
 * | Bus Topology     | Multi-master Capable         | Single-master Only    |
 * | Drive Type       | Open-drain (needs pull-ups)  | Push-pull             |
 *
 * ---------------------------------------------------------------------------
 * Note: This comparison excludes physical pin counts and maximum clock speeds.
 * For 2025 high-reliability embedded designs, choose I2C for complex bus 
 * networks and SPI for high-throughput sensor/memory data streams.
 * ===========================================================================
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
    </pre>
</div>
</body>
</html>
