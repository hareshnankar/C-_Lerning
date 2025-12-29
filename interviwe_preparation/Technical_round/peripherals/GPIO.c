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
