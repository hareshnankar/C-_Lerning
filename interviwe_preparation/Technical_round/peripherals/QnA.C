1.J1939-21 standard and transport layer details?
know about it 
----------------------------------------------------------------------
2.How many bytes can be transferred in J1939 communication?
Classical J1939 (Single Frame): Up to 8 bytes per standard CAN frame.
Classical J1939 Transport Protocol (TP): Up to 1,785 bytes. This applies to both 
BAM (broadcast) and RTS/CTS (peer-to-peer) sessions, where data 
is split into 255 packets of 7 bytes each.
--------------------------------------------------------------------
3.What is bitrate? its role in CAN communication?
bitrate refers to the speed at which data is transmitted over the bus, 
measured in bits per second (bps)
Role in CAN Communication
Synchronization: Because CAN has no separate clock line, every node must be pre-configured 
with the exact same bitrate to interpret signals correctly.
Network Throughput:
Classical CAN:  1 Mbps.
CAN FD : 5 to 8 Mbps.
CAN XL : 20 Mbps.
-----------------------------------------------------------------------------
4.What is the physical level difference between UART and CAN?
/**
 * PHYSICAL LEVEL COMPARISON: UART vs. CAN (2026 Standards)
 * --------------------------------------------------------------------------------
 * | Feature        | UART                   | CAN (Classical / FD)       |
 * |----------------|------------------------|----------------------------|
 * | Topology       | Point-to-Point (1:1)   | Multi-Master Bus           |
 * | Signals        | TX, RX, Ground         | CAN_H, CAN_L (Differential)|
 * | Common Use     | Debugging, short-range | Automotive, Industrial     |
 * | Max Nodes      | 2                      | Hundreds                   |
 * | Error Handling | None at physical level | Built-in (ACK, CRC, Retries)|
 * --------------------------------------------------------
--------------------------------------------------------------------------------
5.How do you handle errors occurred in UART communication? 
/**
 * HOW I HANDLE UART ERRORS (SIMPLE STEPS)
 * --------------------------------------
 * 1. DETECTION (The Hardware Flags)
 *    I check the status registers for three main errors:
 *    - Overrun Error: CPU was too slow to read the data.
 *    - Framing Error: Bad timing or noise broke the "Stop Bit."
 *    - Parity Error: The data bits themselves were corrupted.
 * 
 * 2. CLEARING (The Reset)
 *    Hardware flags often "freeze" the UART until they are cleared.
 *    I handle this by:
 *    - Reading the Data Register (to flush the bad byte).
 *    - Clearing the error bits in the Control Register to "unfreeze" the port.
 * 
 * 3. VERIFICATION (The Software Safety)
 *    Since UART doesn't fix its own data, I always add a Checksum 
 *    or CRC to the end of my message. If the math doesn't add up, 
 *    I discard the whole message and wait for a re-transmission.
 */
----------------------------------------------------------------------
7.Where did you use interrupts and polling in your projects?
/**
 * SENIOR EMBEDDED ARCHITECT'S GUIDE: POLLING VS. INTERRUPTS
 * --------------------------------------------------------
 * 
 * USE INTERRUPTS (Asynchronous / Event-Driven)
 * ----------------------------------------------------------------------------
 * 1. HIGH-SPEED SERIAL (UART/CAN/SPI): When data arrives at unpredictable 
 *    times. Missing a frame (Overrun) is a critical failure.
 * 2. REAL-TIME CONSTRAINTS: For emergency stops or safety-critical 
 *    sensor inputs that must be serviced within microseconds.
 * 3. POWER SAVING: To allow the CPU to enter "Sleep Mode." The hardware 
 *    interrupt "wakes up" the core only when there is work to do.
 * 4. PRECISE TIMING: For PWM generation or capturing pulses where 
 *    nanosecond accuracy is required.
 * 
 * USE POLLING (Synchronous / Deterministic)
 * -----------------------------------------
 * 1. SIMPLE STATE MACHINES: During a startup self-test (BIST) where the 
 *    system isn't doing anything else yet.
 * 2. LOW-SPEED SENSORS: Reading an I2C Temperature sensor every 500ms. 
 *    The overhead of setting up an interrupt is more work than just 
 *    reading a register in the main loop.
 * 3. AVOIDING "INTERRUPT STORMS": If a signal is extremely noisy and 
 *    toggling millions of times per second, interrupts will "choke" the 
 *    CPU. Polling at a set interval acts as a natural low-pass filter.
 * 4. DEBUGGING/BRING-UP: When first testing hardware, polling is easier 
 *    to debug because you don't have to worry about "Race Conditions" 
 *    or "Context Switching" issues.
----------------------------------------------------------------------------------
 */
8.What is BAM [Broadcast Announce Message]? 
How would you identify it? 
or differentiate from other messages?

know the answer
