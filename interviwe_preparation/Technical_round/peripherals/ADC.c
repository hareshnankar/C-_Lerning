/*
 * =================================================================================================
 * Analog to Digital Converter (ADC) - Technical Documentation
 * =================================================================================================
 *
 * 1. DEFINITION
 * ADC is an electronic circuit that converts a continuous analog voltage (real-world signal) 
 * into discrete digital values (binary). It allows MCUs to process physical data.
 *
 * 2. CONVERSION PROCESS
 * - Sampling    : Captures the signal at specific time intervals.
 * - Quantization: Maps continuous voltage to discrete levels based on resolution.
 * - Encoding    : Converts quantized levels into binary format for the CPU.
 *
 * 3. KEY PARAMETERS
 * - Resolution   : Bits per sample (e.g., 8-bit = 256 levels, 12-bit = 4096 levels).
 * - Sampling Rate: Samples per second (Hz). Must follow Nyquist Theorem (Fs > 2 * Fin).
 * - 
 * - importnat explaination about sampling rate :
 * - Nyquist Theorem : To turn an analog wave into a digital signal correctly, 
 * - you must sample it at least 2 times faster than its highest speed (frequency).
 * - Rule: Sampling Speed = 2 × Highest Signal Frequency(changes in tmp for temp sensor
 * - example : 1 sample per second changes in temp so our min sampling rate shoud be 
 * - 2 sample per sec  ).

 * - Ref Voltage  : (Vref) The maximum measurable voltage range.
 * - Accuracy     : Proximity of digital output to actual analog input.
 *
 * 4. TYPES OF ADC
 * - Flash ADC    : Parallel comparators. Fastest speed, high power, high cost.
 * - SAR ADC      : Successive Approximation. Balanced speed/accuracy; standard in MCUs.
 * - Delta-Sigma  : Oversampling architecture. High resolution (24-bit+), used in Audio.
 * - Dual-Slope   : Integrating type. Slow but high precision; used in Multimeters.
 *
 * 5. CONVERSION FORMULA
 * Digital Output = (Analog Input / Reference Voltage) * (2^Resolution - 1)
 *
 * Example (10-bit ADC):
 * - Input: 2.5V, Vref: 5.0V, Resolution: 10-bit (1024 levels)
 * - Result: (2.5 / 5.0) * (1023) = 511
 *
 * 6. APPLICATIONS
 * - Sensor Interfacing: Temperature (LM35), Gas (MQ), Light (LDR).
 * - Audio Systems     : Voice recording and digital signal processing (DSP).
 * - Industrial/Medical: ECG monitors, motor control, and automation.
 *
 * 7. SENIOR-LEVEL DESIGN CONSIDERATIONS
 * - Aliasing        : Signal corruption if sampling rate is too low.
 * - Anti-Aliasing   : Use a Low-Pass Filter (LPF) before ADC input.
 *
 * - important explaination for using low pass filter before adc to reduce noice
 * =================================================================================================
 * Low-Pass Filter (LPF) Technical Summary - Hardware Implementation
 * =================================================================================================
 *
 * 1. BASIC HARDWARE (RC FILTER)
 * The most common LPF implementation uses a Resistor (R) and a Capacitor (C).
 * - The Resistor (R) is placed in series in the signal path.
 * - The Capacitor (C) is connected from the signal path directly to Ground (GND).
 *
 * 2. OPERATIONAL LOGIC
 * Think of the capacitor as a tiny rechargeable battery that requires time to charge.
 *
 * - SLOW SIGNALS (Low Frequency):
 *   The voltage changes slowly. The capacitor has sufficient time to charge and discharge, 
 *   closely following the input voltage. The signal passes to the ADC pin effectively intact.
 *
 * - FAST SIGNALS (High Frequency/Noise):
 *   The voltage cycles up and down so rapidly that the capacitor cannot charge in time. 
 *   Instead of following the "wiggle," the capacitor acts as a low-impedance path, 
 *   "shorting" the fast vibrations to Ground. This "swallows" the noise, leaving a 
 *   smooth, slow-moving signal for sampling.
 *
 * 3. CUTOFF FREQUENCY (fc)
 * Every filter has a "Cutoff Frequency," the threshold where signal attenuation begins.
 *
 * FORMULA: fc = 1 / (2 * PI * R * C)
 *
 * - PASS BAND (Below fc): Signals receive a "Green Light" and pass through to the ADC.
 * - STOP BAND (Above fc): Signals receive a "Red Light" and are blocked or attenuated.
 *
 * 4. DESIGN APPLICATION
 * In ADC systems, the Cutoff Frequency (fc) is typically set below half of the Sampling 
 * Frequency (fs/2) to prevent aliasing and filter out high-frequency electrical interference.
 * -  
 * - Input Impedance : Ensure the source impedance matches the ADC's S&H capacitor.
 * - Grounding       : Separate Analog Ground (AGND) and Digital Ground (DGND).
 * - ENOB            : Effective Number of Bits; accounts for noise and distortion.
 *
 * =================================================================================================
 */
