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

/* In an interview, Direct Memory Access (DMA) should be explained as a specialized hardware 
unit that allows peripherals to transfer data directly to or from the system memory without 
involving the CPU for every byte.

1. Key Details of DMA
Purpose: It offloads "mundane" data movement tasks from the CPU. This reduces CPU overhead, 
lowers power consumption, and improves real-time responsiveness by allowing the processor to
handle complex logic while data transfers happen in the background.

Standard Modes of Transfer:
Burst Mode: The DMA controller takes full control of the system bus and transfers an 
entire block of data in one go.
Cycle Stealing Mode: The DMA "steals" occasional bus cycles from the CPU to transfer 
small chunks (e.g., one byte), allowing the CPU to continue working in between.
Transparent/Interleaved Mode: Data is transferred only when the CPU is idle and not using the bus.
Common Applications: High-speed data handling for ADCs (sensors), UART/SPI communication, and audio/video streaming.

2. How to Implement DMA (Step-by-Step)
Implementing DMA requires a "handshake" between the CPU and the DMA controller. 
Step A: CPU Configuration (Initialization)
The CPU must first program the DMA controller's internal registers: 
Source Address: The memory or peripheral register where data starts (e.g., UART Data Register).
Destination Address: Where the data should be moved (e.g., a RAM buffer).
Transfer Count: The total number of bytes or words to move.
Control Settings: Defining direction (Peripheral-to-Memory, Memory-to-Memory, etc.), data width (8-bit or 16-bit), 
and priority.
Increment Mode: Deciding if the source or destination address should automatically increment 
after each byte (e.g., incrementing the RAM address but keeping the UART register address fixed)

Step B: The Handshake Process
Once enabled, the hardware takes over:
DMA Request (DREQ): A peripheral (like a full UART buffer) sends a signal to the DMA controller indicating it is ready.
Bus Request (HOLD): The DMA controller asks the CPU for control over the data and address buses.
Bus Grant (HLDA): The CPU finishes its current cycle and grants control to the DMA controller.
Data Transfer: The DMA controller moves data directly between source and destination.

Step C: Completion
Interrupt: Once the specified transfer count reaches zero, the DMA controller generates an 
Interrupt to notify the CPU that the task is finished.
Bus Release: The DMA controller releases the system bus back to the CPU

3. Interview Tip: Real-World Example (STM32 UART DMA)
If asked for a specific implementation example, describe a circular buffer for UART:
"In an STM32 environment, I would set the DMA to Circular Mode. This allows the DMA to automatically wrap 
around to the start of the buffer once it is full, enabling continuous data reception without manual CPU restarts. 
I would then use the Half-Transfer and Transfer-Complete interrupts to process data in chunks without missing any incoming bytes.*/

  </pre>
</div>
</body>
</html>
