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
GPIO (General Purpose Input/Output) pins are the most basic and essential interface 
of a microcontroller, allowing software to interact directly with external digital hardware.

1. Basic Working Principle A GPIO pin acts as a programmable digital bridge. 
Internally, each pin is typically controlled by two CMOS transistors: 
a P-MOS (connected to vcc and an N-MOS (connected to Ground).

As Output: Software can drive the pin High (connecting it to VCC via P-MOS) 
or Low (connecting it to GND via N-MOS).

As Input: The output transistors are disabled, and a Schmitt Trigger helps 
clean up the signal before the CPU reads its logic state (0 or 1).

2. Primary GPIO Modes In an interview, you should categorize GPIO functionality into these 
four modes: 

Input Mode:
Floating (High-Impedance): The pin is not connected to VCC or GND internally. 
Its state is undefined and highly sensitive to electrical noise unless driven externally.

Pull-up/Pull-down: Internal resistors (typically 10kOHM to 100kOHM are enabled to ensure 
the pin has a default state (High or Low) when no external device is active.

Output Mode:
Push-Pull (Default): Both transistors are used. The pin can actively "push" current 
out to drive a load high or "pull" current in to drive it low. It is fast and efficient.
Open-Drain: Only the N-MOS is used. The pin can pull to ground (Low), but when it tries to go high, 
it enters a floating state. An external pull-up resistor is required to achieve a High state. 
This is used for shared buses like I2C.
Analog Mode: The digital buffers are disabled, and the pin is connected directly to an internal ADC 
(to read voltages) or DAC (to output voltages).
Alternate Function Mode: Redirects the pin to a specific internal hardware peripheral like UART, SPI, or PWM.

3. Key Registers (The Software Side)
Controlling GPIO involves writing to specific memory-mapped registers:
Direction Register (DDR/DIR): Sets the pin as Input (0) or Output (1).
Data Register (IDR/ODR): Reads current input levels or sets the desired output level.
Pull-up/Pull-down Register: Configures internal resistors.
Alternate Function Register: Selects which peripheral (e.g., UART TX) owns the pin

4. Critical Interview Tip: Volatile Keyword
When programming GPIO in C, always declare the register addresses as volatile. This tells the 
compiler that the value can change unexpectedly (e.g., a physical button press), preventing the compiler 
from "optimizing away" the code that checks the pin state

*/
  </pre>
</div>
</body>
</html>
