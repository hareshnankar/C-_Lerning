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
 * Pulse Width Modulation (PWM) - Detailed Explanation
 *
 * Definition:
 * PWM is a technique used to control the power delivered to electrical devices by varying the duty cycle of a periodic signal.
 * It is commonly used in motor control, LED dimming, and signal processing.
 *
 * Characteristics:
 * - Generates a square wave with variable duty cycle.
 * - Controls the average voltage applied to a load.
 * - Used in digital-to-analog conversion.
 *
 * Important Parameters:
 * - Duty Cycle: Percentage of time the signal remains HIGH in one cycle.
 * - Frequency: Number of PWM cycles per second.
 * - Resolution: Number of discrete duty cycle levels available.exm 10 bit 1024 duty cycle 
 * 
 * /*
 * Differences Between PWM Parameters
 *
 * Definition:
 * Pulse Width Modulation (PWM) has several key parameters that define its operation.
 * Each parameter affects the output signal and performance in applications such as
 * motor control, LED dimming, and signal processing.
 *
 * 1. Duty Cycle:
 *    - Definition: Percentage of time the signal is HIGH in one cycle.
 *    - Formula: Duty Cycle (%) = (ON Time / Total Period) * 100
 *    - Impact: Controls the average voltage and power delivered to the load.
 *    - Example: 50% Duty Cycle means equal HIGH and LOW durations.
 *
 * 2. Frequency:
 *    - Definition: Number of PWM cycles per second (Hz).
 *    - Formula: Frequency = 1 / Period
 *    - Impact: Determines switching speed, affecting response time and smoothness.
 *    - Example: Higher frequency results in finer control but may introduce EMI (Electromagnetic Interference).
 *
 * 3. Resolution:
 *    - Definition: Number of discrete duty cycle levels available.
 *    - Formula: Resolution = 2^Bits (where Bits = PWM resolution)
 *    - Impact: Higher resolution provides finer control over output power.
 *    - Example: A 10-bit PWM resolution provides 1024 duty cycle levels.
 *
 * 4. Amplitude:
 *    - Definition: Maximum voltage level of the PWM signal.
 *    - Formula: Amplitude = Supply Voltage
 *    - Impact: Defines the peak voltage applied to the load.
 *    - Example: 5V amplitude means the PWM HIGH level reaches 5V.
 *
 * 5. Period:
 *    - Definition: Time taken for one complete PWM cycle.
 *    - Formula: Period = 1 / Frequency
 *    - Impact: Affects how often the signal repeats.
 *    - Example: Lower period results in a faster signal transition.
 *
 * Summary:
 * - Duty Cycle controls power delivery.
 * - Frequency affects switching speed and responsiveness.
 * - Resolution determines precision in duty cycle adjustments.
 * - Amplitude defines peak voltage levels.
 * - Period governs cycle repetition timing.
 *
 * Proper selection of PWM parameters is essential for optimal performance in different applications.
 * /*
 * Pulse Width Modulation (PWM) - Important Parameters
 *
 * Parameter      | Definition                                                
 * --------------------------------------------------------------------------------------------------
 * Duty Cycle    | Percentage of time the signal is HIGH in one cycle.         
                 |impact: Controls the average voltage and power delivered to the load.
 * Frequency     | Number of PWM cycles per second (Hz).                        
                 |impact : Determines how fast the signal switches, affecting response time and smoothness.
 * Resolution    | Number of discrete duty cycle levels available.              
                 |impact: Higher resolution allows finer control over output power.
 * Amplitude     | Maximum voltage level of the PWM signal.                    
                 |impact: Defines the peak voltage applied to the load.
 * Period        | Time taken for one complete cycle (inverse of frequency).     
                 |impact: Affects how often the signal repeats.
 *
 * Summary:
 * - Duty Cycle controls power delivery.
 * - Frequency affects switching speed and responsiveness.
 * - Resolution determines precision in duty cycle adjustments.
 * - Amplitude defines peak voltage levels.
 * - Period governs cycle repetition timing.
 * 
 * 1. Resolution:
 *    - Definition: Number of discrete duty cycle levels available.
 *    - Formula: Resolution = 2^Bits (where Bits = PWM resolution).
 *    - Impact: Higher resolution allows finer control over output power.
 *    - Example: A 10-bit PWM resolution provides 1024 duty cycle levels.
 *
 * 2. Frequency:
 *    - Definition: Number of PWM cycles per second (Hz).
 *    - Formula: Frequency = 1 / Period.
 *    - Impact: Determines how fast the signal switches, affecting response time and smoothness.
 *    - Example: Higher frequency results in finer control but may introduce EMI (Electromagnetic Interference).
 *
 * Proper PWM configuration ensures efficient and precise control of electrical devices.
 *
 * PWM Signal Representation:
 * - 0% Duty Cycle → Always LOW (0V).
 * - 50% Duty Cycle → Equal HIGH and LOW durations.
 * - 100% Duty Cycle → Always HIGH (Max Voltage).
 *
 * Applications:
 * - Motor speed control.
 * - LED brightness adjustment.
 * - Audio signal processing.
 * - Power regulation in switching circuits.
 *
 * Advantages:
 * - Efficient power control with minimal energy loss.
 * - Smooth analog-like control using digital signals.
 * - Reduces heat dissipation compared to linear control methods.
 *
 * Limitations:
 * - Requires proper filtering for analog applications.
 * - High-frequency PWM may introduce electromagnetic interference (EMI).
 * - Limited resolution in low-cost microcontrollers.
 *
 * Summary:
 * PWM is a versatile technique widely used in embedded systems and power electronics.
 * Proper implementation ensures efficient and precise control of electrical devices.
 *
 * important parameter and example of pwm but before that we need to understand few terms
 * 1. What is a Prescaler? 
 *    A prescaler is a hardware frequency divider that slows down the incoming system clock 
 *    before it reaches the timer.
       
 * 2.Why use it? 
 *    If the system clock is too fast, the timer (often only 16-bit
 *    max 65,535 counts) will overflow too quickly to achieve low frequencies.
    
 * 3.How it works: A prescaler of (N) means the timer only increments once for every (N) system clock cycles.
 *
 *  Step A: Calculate the Prescaler (PSC) To avoid overflow and maintain high resolution,
 * we choose a prescaler that allows the 
 * period to fit into the register. For a 10 MHz clock, a prescaler of 10 is ideal. 
 * Timer Clock = 10MHz/10 (or 1,000,000 ticks per second).
 * Register Setting: PSC = 9 (Hardware often adds +1 automatically, so 9 results in a division by 10)
 
 * Step B: Set the Period / Auto-Reload Register (ARR) 
 * This register defines the total length of one PWM cycle. 
 * Total Counts = Timer ClocK \ Desired Frequency = 1,000,000 Hz \ 1,000 Hz = 1,000 counts 
 * Register Setting: ARR = 999 (The counter resets after counting from 0 to 999, 
 * making 1,000 total steps)

 * Step C: Set the Duty Cycle / Compare Register (CCR)
 * This register determines how long the signal stays "High" during that period. 
 * Pulse Width = Total Counts * Duty Cycle}=1,000 * 0.25=250 counts
 * Register Setting: CCR = 250 

 * 3. Summary of Register Logic
 * Prescaler Register: Sets the "speed" of the timer (Clock ÷ PSC).
 * Period (ARR) Register: Sets the "frequency" (Timer Speed ÷ ARR).
 * Compare (CCR) Register: Sets the "duty cycle" (Pulse Width ÷ ARR).

  </pre>
</div>
</body>
</html>
