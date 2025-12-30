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

*/
