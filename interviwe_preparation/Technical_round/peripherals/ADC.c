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
  </pre>
</div>
</body>
</html>
