/*
 * Analog to Digital Converter (ADC) - Detailed Explanation
 *
 * Definition:
 * ADC is an electronic circuit that converts an analog signal (continuous voltage) into a digital signal (discrete binary values).
 * It is used in microcontrollers, sensors, and embedded systems to process real-world analog data.
 *
 * ADC Conversion Process:
 * 1. Sampling: Captures the analog signal at discrete time intervals.
 * 2. Quantization: Converts the sampled values into discrete digital levels.
 * 3. Encoding: Represents the quantized values in binary format.
 *
 * ADC Parameters:
 * - Resolution: Number of bits used to represent the digital output (e.g., 8-bit, 10-bit, 12-bit).
 * - Sampling Rate: Number of samples taken per second (Hz).
 * - Reference Voltage: Defines the maximum input voltage range.
 * - Accuracy: Determines how close the digital output is to the actual analog input.
 *
 * Types of ADC:
 * - Flash ADC: Fastest type, uses parallel comparators.
 * - Successive Approximation ADC (SAR): Common in microcontrollers, balances speed and accuracy.
 * - Delta-Sigma ADC: High-resolution, used in audio applications.
 * - Dual-Slope ADC: Used in precision measurement instruments.
 *
 * Applications:
 * - Temperature sensors (LM35, TMP36).
 * - Audio signal processing.
 * - Industrial automation and control systems.
 * - Medical devices (ECG, blood pressure monitors).
 *
* Formula:
 * Digital Output = (Analog Input / Reference Voltage) * (2^Resolution - 1)
 *
 * Parameters:
 * - Analog Input: The voltage being measured.
 * - Reference Voltage: The maximum voltage the ADC can measure.
 * - Resolution: The number of bits used in ADC conversion (e.g., 8-bit, 10-bit, 12-bit).
 *
 * Example Calculation:
 * - Reference Voltage = 5V
 * - Resolution = 10-bit (2^10 = 1024 levels)
 * - Analog Input = 2.5V
 * - Digital Output = (2.5V / 5V) * (1024 - 1) = 511
 *
 * Summary:
 * - Higher resolution provides finer granularity in digital representation.
 * - Proper reference voltage selection ensures accurate conversion.
 * - ADC is widely used in microcontrollers for sensor data acquisition
 */
