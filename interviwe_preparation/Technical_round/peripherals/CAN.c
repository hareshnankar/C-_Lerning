/*
The Controller Area Network (CAN) is a robust serial communication protocol
that allows microcontrollers and electronic devices (nodes) to communicate with each other 
without a central host computer. 
Originally developed by Bosch for automotive applications to reduce wiring complexity, 
it is now a global standard used in industrial automation, medical equipment, and aerospace

3 Imporatant points 
Priority-Based (Arbitration): 
Not all messages are equal. CAN uses "Arbitration" to ensure that critical messages 
(like "Apply Brakes") always get through before less important ones (like "Temperature Update") 
without any data collisions.

Noise Immunity (Differential Signaling): Because it uses two wires (CAN High and Low),
it is extremely resistant to electrical noise, which is why it’s the standard 
for harsh environments like cars and factories.

Broadcast System: It works like a radio station. 
One node "broadcasts" a message, and every other node hears it. 
Each node then uses filters to decide, "Is this message meant for me?

The "Why" (The Benefit)
Reduces Wiring: Instead of running miles of point-to-point wires between every sensor, 
you just connect everything to a single "bus" (the two wires).
Reliability: It has built-in error detection. If a message is corrupted, 
the node automatically knows and tries to send it again

Interview Tip: If they ask for a real-world analogy, say:
"It’s like a group of people in a dark room. Anyone can speak when it’s quiet,
but if two people start at once, the one with the most important news keeps talking while 
the other stops to listen. Everyone hears the message, 
but only the person it concerns takes action.

Layers of CAN 
------------------------------------------------
                3 application layer
------------------------------------------------
                2 Object layer
CAN message  -> Massage Filtering 
             -> Message and Status Handling
------------------------------------------------
                1 Transfer Layer
             -> faut confinment 
             -> Error Detection and Signalling 
             -> Message Validation
CAN Frame    -> Acknowlegment 
             -> Arbitration
             -> Message Framing
             -> Transfer rate and Timing 
-------------------------------------------------
                0 Physical Layer 
 CAN Signal   -> Signal Level and Bit representation
              -> Transmission Medium 
-------------------------------------------------

Layers of CAN in detail explaination 
CAN Signal : physical layer
CAN uses differential signaling across two wires, CAN_H (High)
and CAN_L (Low), which provides high immunity to electromagnetic 
interference (EMI)

Differential Voltage V_diff: 
voltage difference between CAN_H and CAN_L . ( V_diff=V_CAN_H - V_CAN_L ).

Recessive Bit (Logical 1):
Voltage: Both lines are driven to a common mode voltage, typically 2.5V.
V_diff: Approximately 0V (typically < 0.5V).
Behavior: This is the idle state. If no node is transmitting a dominant bit,
the bus remains recessive

Dominant Bit (Logical 0):
Voltage: CAN_H is driven up to 3.5V, and CAN_L is driven down to 1.5V
V_diff: Approximately 2.0V.
Behavior: A dominant bit physically overrides a recessive bit. If one node sends a '0' 
while another sends a '1', the bus will reflect a '0', which is essential for 
message arbitration (from MSB to LSB )

CAN uses  Non-Return to Zero (NRZ) Coding
NRZ is a binary line code where the signal level stays constant for the entire 
duration of a bit.
Logical 0 (Dominant): The voltage level is at one state (e.g.V_diff approx 2V
for the full bit time.
Logical 1 (Recessive): The voltage level stays at the resting state V_diff approx 0V
for the full bit time.
The Advantage: It is highly efficient because it doesn't require the signal 
to "return to zero" between every bit

The Problem: Because the signal doesn't change for long strings of 0s or 1s, 
there are no "edges" (voltage transitions). Receivers rely on these edges to 
synchronize their internal clocks with the transmitter. Without edges, 
the receiver's clock might "drift,"leading it to miscount bits or lose 
the frame entirely(synchromisation is done using voltage level changes )

2. Bit Stuffing: The Solution
To fix the lack of transitions in NRZ, CAN uses bit stuffing. 
This process ensures that the signal "toggles" often enough for receivers to stay in sync

The Rule: Whenever the transmitter detects five consecutive bits of the same 
polarity (five 0s or five 1s) in the data stream, it automatically inserts
a sixth bit of the opposite polarity

Example:
Original Data: 1 1 1 1 1
Stuffed Stream: 1 1 1 1 1 0 (the 0 is the "stuff bit")

Syncing on the Edge: This extra bit creates a forced voltage transition (a rising or 
falling edge). Every receiver on the bus sees this transition and resets its
internal clock, ensuring it stays perfectly aligned with the transmitter.

3. Key Details
De-stuffing: The receiving node’s CAN controller automatically identifies 
and removes these extra bits after every five identical bits. The user 
software only sees the original, correct data

Where it applies: Bit stuffing is used in the Arbitration, Control, Data,
and CRC fields. It is not used in fixed-format parts like the CRC Delimiter,
ACK Slot, or End of Frame (EOF), which rely on specific fixed patterns

Stuff Errors: If a node detects six consecutive bits of the same polarity
where stuffing should have occurred, it flags a "Stuff Error," 
sends an Error Frame, and the message must be retransmitted.

Jitter: A side effect of bit stuffing is that message length 
can vary slightly based on the data content,which can introduce "jitter" 
(small timing variations) in real-time systems.

2. Transmission Medium
The medium consists of the wiring, connectors, and termination required 
to maintain signal integrity over distance

Twisted-Pair Cable: The standard requires a twisted-pair cable 
(shielded or unshielded) with a nominal characteristic impedance of 120 ohm. 
Twisting the wires ensures that external noise affects both lines equally, 
allowing the differential receiver to cancel the interference

Termination Resistors:
Value: Exactly two 120 ohm resistors must be placed at 
the extreme ends of the main bus line
Purpose: These match the cable's characteristic impedance to prevent 
signal reflections (echoes) that could distort data and cause errors.

Verification: When the network is powered off, the resistance measured 
between CAN_H and CAN_L should be approximately 60 ohm (two 120 ohm) resistors in parallel)

Topology: High-speed CAN typically uses a linear bus topology. 
To minimize reflections, "stubs" (branches from the main bus to individual nodes) 
should be kept as short as possible, typically \(\le \) 0.3 meters at 1 Mbps.

CAN Frame Transfer Layer :
Transfer rate and Timing 

transfer rate :
Classical CAN (CAN 2.0): Supports bit rates up to 1 Mbps. 
Common speeds include 
125 kbps, 250 kbps, and 500 kbps (standard for most automotive networks)

CAN FD (Flexible Data-Rate):arbitration phase remains at 1 Mbps,
the data phase can reach up to 5–8 Mbps

CAN XL: The newest generation supports data rates up to 20 Mbps

Distance Trade-off: Higher bit rates require shorter bus lengths. 
For example, 1 Mbps is limited to roughly 40 meters, 
while 125 kbps can operate over 500 meters

Important term Time Quantum :
the Time Quantum (TQ) remains the fundamental, 
non-divisible unit of time that defines the resolution of a single CAN bit. 
It serves as the "clock tick" for the CAN controller to build and manage the
bit timing segments

Definition and Calculation:
TQ is derived from the peripheral clock of the microcontroller (MCU) by applying a Baud Rate Prescaler (BRP). 
The prescaler slows down the high-frequency system clock to a manageable speed for the CAN protocol.

The standard formula is:
TQ = BRP / System clock freq = 4 / 40 MHz = 100ns
Sigle bit  = 8 to 25 TQs;
1.Sync_Seg: Always exactly 1 TQ.
2.Prop_Seg, Phase_Seg1, and Phase_Seg2: These are programmable and consist of a 
specific number of TQs (e.g., 4 TQ for Prop_Seg, 5 TQ for Phase_Seg1).

FRAM FORMATE 





*/
