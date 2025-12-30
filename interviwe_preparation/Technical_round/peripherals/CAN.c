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
there are no "edges" (voltage transitions). Receivers rely on these edges to synchronize 
their internal clocks with the transmitter. Without edges, the receiver's clock might "drift,"
leading it to miscount bits or lose the frame entirely(synchromisation is done using voltage 
level changes )

2. Bit Stuffing: The Solution
To fix the lack of transitions in NRZ, CAN uses bit stuffing. 
This process ensures that the signal "toggles" often enough for receivers to stay in sync

The Rule: Whenever the transmitter detects five consecutive bits of the same polarity 
(five 0s or five 1s) in the data stream, it automatically inserts a sixth bit of the opposite polarity

Example:
Original Data: 1 1 1 1 1
Stuffed Stream: 1 1 1 1 1 0 (the 0 is the "stuff bit")

Syncing on the Edge: This extra bit creates a forced voltage transition (a rising or falling edge). 
Every receiver on the bus sees this transition and resets its internal clock, ensuring it stays 
perfectly aligned with the transmitter.

3. Key Details
De-stuffing: The receiving node’s CAN controller automatically identifies and removes these extra bits 
after every five identical bits. The user software only sees the original, correct data

Where it applies: Bit stuffing is used in the Arbitration, Control, Data, and CRC fields. 
It is not used in fixed-format parts like the CRC Delimiter, ACK Slot, or End of Frame (EOF), 
which rely on specific fixed patterns

Stuff Errors: If a node detects six consecutive bits of the same polarity where stuffing should have occurred, 
it flags a "Stuff Error," sends an Error Frame, and the message must be retransmitted.
*/
