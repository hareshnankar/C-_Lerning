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
 * Parameter      | Definition                                                  | Impact
 * -----------------------------------------------------------------------------------------------------------------------------------------
 * Duty Cycle    | Percentage of time the signal is HIGH in one cycle.          | Controls the average voltage and power delivered to the load.
 * Frequency     | Number of PWM cycles per second (Hz).                        | Determines how fast the signal switches, affecting response time and smoothness.
 * Resolution    | Number of discrete duty cycle levels available.              | Higher resolution allows finer control over output power.
 * Amplitude     | Maximum voltage level of the PWM signal.                     | Defines the peak voltage applied to the load.
 * Period       | Time taken for one complete cycle (inverse of frequency).     | Affects how often the signal repeats.
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
 */
