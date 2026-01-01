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
    </pre>
</div>
</body>
</html>
