/*
SAE J1939 is a higher-layer protocol (HLP) built on top of the CAN bus. While standard CAN defines the physical
and data link layers (the "highway"), J1939 provides the "language" for communication in heavy-duty vehicles
such as trucks, buses, and agricultural machinery

1. 29-bit Identifier Breakdown
While CAN supports 11-bit or 29-bit IDs, J1939 uses 29-bit Extended Identifiers exclusively. 
The 29 bits are segmented as follows

Field Name                                   Bits          Description

Bits 28–26  Priority           	              3            Determines bus arbitration (0=highest, 7=lowest).
-----------------------------------------PGN-start------------------------------------------------------------------
Bit 25      Extended Data Page (Reserved Bit) 1            Always set to 0 for standard J1939 messages. 
Bit 24      Data Page                         1            Expands the total number of available PGNs. 
Bits 23–16  PDU Format (PF)                   8            Defines message type. Values < 240 indicate 
                                                           point-to-point (PDU1);values ≥ 240 indicate broadcast (PDU2).
Bits 15–8   PDU Specific (PS)                 8            In PDU1, this is the Destination Address. 
                                                           In PDU2, it is a Group Extension to further define the PGN.
Bits 7–0    Source Address                    8            Unique identifier of the ECU sending the message (0–253).
-----------------------------------------PGN-End-----------------------------------------------------------------------

PGNs and SPNs
PGN (Parameter Group Number): An 18-bit value (composed of the Reserved bit, Data Page, PF, and PS) 
that acts as a unique frame identifier
SPN (Suspect Parameter Number): Individual data signals within a PGN.
Example: PGN 61444 (Electronic Engine Controller 1) contains SPN 190 (Engine Speed) 
and SPN 513 (Actual Engine Torque).

In J1939, the Data Page (DP) and Extended Data Page (EDP) bits act as selectors to multiply the number 
of available Parameter Group Numbers (PGNs). Together, they create four possible "pages" of information, 
though most common vehicle data currently resides on Page 0.
1. The Four PGN Pages
The combination of the EDP and DP bits determines which set of PGN definitions to use:

EDP Bit        	DP Bit   Page Name     Primary Usage / Description
0                0         Page0       Most standard SAE J1939 and (ISOBUS) parameters.
0                1         Page1       Expanded range; primarily used for (marine) standards
1                0         Page2       Currently Reserved by SAE for future use
1                1         Page3       Used for ISO 11992 diagnostics (truck-to-trailer communication)

Why is this needed?
Expansion: A single 18-bit PGN space can only hold about 8,672 unique identifiers if only using 
PDU Format and Specific fields. The Data Page bit doubles this, and the Extended Data Page bit
doubles it again, allowing the standard to grow without changing the 29-bit CAN ID structure

Cross-Industry Compatibility: By using different pages, different industries (like Marine with NMEA 2000)
can use the same underlying J1939 framing without overlapping their specific message 
definitions with trucking parameters on Page 0

3. Transport Protocol (TP) for Large Messages
In J1939, the transport layer protocol (defined in J1939-21) is used to send data larger than 8 bytes by 
splitting it into multiple packets. It uses two specialized PGNs to manage the 
communication: 
TP.CM (Connection Management, PGN 60416)     for handshaking 
and 
TP.DT (Data Transfer, PGN 60160)            for the actual data
Communication happens via two primary methods:
1.BAM (Broadcast)
2.RTS/CTS (Peer-to-Peer).

3.1. Broadcast Announce Message (BAM)
This method is used when an ECU needs to send large data (like a VIN or active fault list) to the entire network
Step 1: The Announcement (TP.CM): The sender broadcasts a BAM message (Control Byte = 32) containing 
the total number of bytes and the PGN being sent.

IN DETAIL EXPALINATION WITH EXAMPLE:
Imagine an engine control unit (ECU) needs to send a long text string of diagnostic information 
(e.g., 50 bytes of data) to all other devices on the network. Since a standard CAN frame can 
only hold 8 bytes, the J1939 transport layer uses BAM to "package" and broadcast this data.
1.The Announcement (Control Function):
-->The source ECU sends a single BAM Control Frame.
-->This frame informs the entire network: "I am about to broadcast 50 bytes of 
   data regarding Parameter Group Number (PGN) X, and it will take 7 packets to complete.".


Step 2: Data Transfer (TP.DT): The sender starts transmitting the data packets. 
Each packet contains a 1-byte sequence number followed by 7 bytes of data.

IN DETAIL EXPALINATION WITH EXAMPLE:
Continue from above ...
The Data Transfer (Data Transfer Function):
-->The source ECU then sends the 50 bytes across 7 consecutive CAN frames (Data Transfer Packets).
-->Each packet contains a sequence number (1 through 7) so receiving nodes can reassemble 
   them in the correct order.


Timing: The sender must wait 50–200ms between each packet to ensure other ECUs have time to process the data.
No Handshake: Since it is a broadcast, receivers do not send any acknowledgment; if a packet is missed, it is lost.

IN DETAIL EXPALINATION WITH EXAMPLE:
Continue from above ...
3.No Handshake:
n a BAM session, the sender does not wait for an acknowledgment (ACK) from the receivers. It simply sends 
the data at a regulated interval (typically 50–200 ms between packets) to ensure no receiver is overwhelmed.

Key Characteristics of BAM
1.One-to-Many: Used for broadcasting information to the entire network rather than a specific destination.
2.Connectionless: There is no "Ready to Send" or "Clear to Send" handshake between the sender and receivers.
3.Payload Capacity: It allows for the transmission of messages up to 1,785 bytes in length

J1939 TRANSPORT LAYER BAM EXAMPLE
BAM (Broadcast Announce Message) allows a node to send data larger than 8 bytes to the entire network.

Example Scenario: 20 Bytes of Data
Target PGN: 65260 (Vehicle Identification)
Required frames: 3 CAN frames

Connection Management Frame (TP.CM)
The source node sends an announcement to let all other nodes know a multi-packet message is starting.
CAN ID: 0x18ECFFSA (Priority 6, PGN 60416, Destination 255/Global, Source SA).
Data Field (8 Bytes):
Byte 1 (Control Byte): 32 (0x20) indicates BAM.
Bytes 2-3: Total number of data bytes (20 00 for 20 bytes, LSB first).
Byte 4   : Total number of packets (03 for 3 packets).
Byte 5   : Reserved (always 0xFF).
Bytes 6-8: PGN of the actual message being sent (AC FE 00 for PGN 65260, LSB first).

Data Transfer Packets (TP.DT)
Following the BAM announcement, data is sent in consecutive frames with a delay of 50 to 200ms.
CAN ID: 0x18EBFFSA (Priority 6, PGN 60160, Destination 255/Global, Source SA).
Data Field Structure: Byte 1 is the Sequence Number, and Bytes 2 to 8 are the actual data.
Packet 1
Byte 1: 01 (Sequence Number)
Bytes 2-8: First 7 bytes of data
Packet 2
Byte 1: 02 (Sequence Number)
Bytes 2-8: Next 7 bytes of data
Packet 3
Byte 1: 03 (Sequence Number)
Bytes 2-7: Last 6 bytes of data
Byte 8: 0xFF (Padding byte)
Key Technical Rules:
Unidirectional: BAM is connectionless; the sender does not wait for a "Clear to Send" or acknowledgment from receivers.
Packet Limit: A maximum of 255 packets can be sent in one session, allowing for up to 255 X 7 = 1,785 bytes of data.
Padding: If the final packet does not have enough data to fill the 8-byte CAN frame, the unused bytes are padded with 0xFF.

3.2The Request to Send / Clear to Send (RTS/CTS) mechanism is a peer-to-peer communication method used in J1939
protocols for direct data transfer between two specific Electronic Control Units (ECUs), such as during a software update. 
The process follows these four steps:
Step 1: Request to Send (RTS). The sender initiates the process by sending a Transport Protocol 
        Connection Management (TP.CM) message to a specific destination address to request a data transfer. 
Step 2: Clear to Send (CTS). The receiver responds with a TP.CM message. This message informs
        the sender how many data packets the receiver is ready to accept at once
        and specifies which packet number to start with. 
Step 3: Data Transfer (TP.DT). The sender transmits the data using Transport Protocol Data 
        Transfer messages. Each message is 8 bytes long, consisting of 1 byte for the sequence 
        number and 7 bytes for the actual data. 
Step 4: End of Message Acknowledgment (EoMA). After the receiver successfully collects all 
        the data, it sends an acknowledgment message with a Control Byte set to 19 to
        confirm receipt and close the connection

In a real-world J1939 scenario, the Request to Send / Clear to Send (RTS/CTS) process is
commonly used to transfer data larger than 8 bytes, such as an Engine Configuration or 
Software Update. Below is a technical example of an ECU at address 0x81 sending a 
15-byte message (3 packets) to an ECU at address 0x80.

Request to Send (RTS)
The sender (0x81) initiates the transfer for a specific Parameter Group Number (PGN).
CAN ID: 0x1CEC8081 (Priority 7, PGN 0xEC00, Destination 0x80, Source 0x81)
Data Bytes: 10 0F 00 03 FF 5F EA 00
10: Control Byte for RTS.
0F 00: Total bytes to send (15 decimal).
03: Total number of packets.
FF: Reserved.
5F EA 00: The PGN being sent (PGN 59999 in this example).

Clear to Send (CTS)
The receiver (0x80) confirms it is ready and tells the sender how many packets to transmit.
CAN ID: 0x1CEC8180 (Destination 0x81, Source 0x80)
Data Bytes: 11 03 01 FF FF 5F EA 00
11: Control Byte for CTS.
03: Number of packets the receiver can accept right now.
01: The packet number to start with.
5F EA 00: PGN confirmation.

Data Transfer (TP.DT)
The sender transmits the actual data in segments using the TP.DT PGN (0xEB00).
Packet 1: 0x1CEB8081 | Data: 01 [7 bytes of data]
Packet 2: 0x1CEB8081 | Data: 02 [7 bytes of data]
Packet 3: 0x1CEB8081 | Data: 03 [Remaining 1 byte of data + 6 bytes of 0xFF padding]

End of Message Acknowledgment (EoMA)
Once all 3 packets are received, the receiver closes the session.
CAN ID: 0x1CEC8180
Data Bytes: 13 0F 00 03 FF 5F EA 00
13: Control Byte for End of Message Acknowledgment (decimal 19).
0F 00: Confirms 15 total bytes received.
03: Confirms 3 total packets received.


4. Network Management (Address Claiming)
Every ECU must have a unique address (0–253)
Address Claiming: Upon power-up, an ECU broadcasts an "Address Claim" message 
containing its unique 64-bit NAME

Contention: If two ECUs claim the same address, the one with the higher priority N
AME (numerically lower) keeps the address. The "loser" must claim a different 
address or stop communicating.

5. Diagnostics (J1939/73)
Standardized Diagnostic Messages (DM) simplify vehicle troubleshooting
DM1 (Active DTCs): Periodically broadcasts all currently active fault codes.
DM2 (Previous DTCs): Sends a list of historical fault codes on request.
DTC Structure: A Diagnostic Trouble Code consists of the SPN (what failed), 
an FMI (Failure Mode Identifier, e.g., "voltage too high"), and an Occurrence Count

1. Decoding SPNs (SLOT Definition)
Every SPN is defined by a SLOT (Scaling, Limit, Offset, and Transfer Function), 
which is required to convert raw binary data into human-readable physical values
Formula: Physical Value = (Raw Data * Resolution/Scaling) + Offset.

1.Engine Speed Example (SPN 190).
Data Length: 2 bytes.
Resolution: 0.125 RPM per bit.
Offset: 0.
Calculation: If you receive a raw decimal value of 8000, the speed is 8000 x 0.125=1000 RPM.

2.Engine Torque Example (SPN 513):
Resolution: 1% per bit.
Offset: -125%.
Calculation: A raw value of 130 decimal results in \(130-125=5\%\) torque.

2. Standard Data Ranges and Special Values
Raw Value (Hex)      Description         Meaning
0x00 – 0xFA          Valid Data          	Standard operational range for a 1-byte SPN.
0xFB (251)           Error Indicator      Used to indicate a specific error condition defined by the parameter.
0xFC (252)           Not Defined          Reserved for future use by SAE
0xFE (254)           Error                Sensor failure or data is unreliable (e.g., short circuit).
0xFF (255)           Not Available       The node does not support this parameter or the sensor is not installed


for every parameter there are diff bytes assigned?
Yes, every parameter (SPN) is assigned to specific bytes—and often specific bits—within a message (PGN). 
These assignments are fixed by the SAE J1939 standard to ensure that different manufacturers' 
equipment can "talk" to each other.

Here is how the data is organized
1. Fixed Byte Offsets
In most J1939 messages, each parameter has a reserved home in the 8-byte data field
->Unique Assignment: For a specific PGN, Byte 1 might always be "Temperature," while Bytes 4-5 are "Speed."
->No Overlap: In standard messages, parameters do not overlap. If SPN A uses Byte 2, SPN B will start 
  at Byte 3 or later

2. Bit-Level Packaging
Not all parameters need a full byte. Small data points (like "On/Off" switches 
or "Low/High" states) are packed into bits to save space
->Example: A single byte can hold four different 2-bit parameters.
->Control Bits: Many J1939 parameters are only 2 bits long, allowing 
  one byte to carry multiple status signals.

3. Multiplexing (Same Bytes, Different Data)
In rare cases, the same bytes can carry different parameters depending 
on a "Multiplexer" byte (usually Byte 1).
If Byte 1 = 0, then Bytes 2-8 contain one set of data.
If Byte 1 = 1, then Bytes 2-8 contain a completely different set of data.
This is common in complex messages like VIN (Vehicle Identification Number) or long diagnostic lists


Example in which we can identify PGNs and SNGs 

To identify PGNs and SPNs from a raw J1939 frame, you must break the 29-bit 
identifier and the 8-byte payload into their specific functional components

1. The Raw Data Frame



EXAMPLE 1 : 
Imagine your CAN logger captures the following message:
ID: 0CF00401 DLC: 8 DATA: F1 FF AA D0 1D FF FF FF (PDU2 EXAPLE)

How to Identify PDU1 vs. PDU2
The J1939 standard uses the 8-bit PDU Format field (PF) within the 29-bit identifier
to decide how the message is addressed:
PDU1 --> 0 to 239 (0x00 to 0xEF)   -> Point-to-Point -> PS	Contains the Destination Address
PDU2 --> 240 to 255 (0xF0 to 0xFF) -> Broadcast      -> PS 	Contains a Group Extension

2. Identifying the PGN (The Header)
First, we convert the Hex ID to Binary to see the J1939 fields.
Hex ID: 0C F0 04 01

Step 1: Convert Hex to Binary
Convert the first part of the hex ID (0C) into an 8-bit binary string
0 in binary is 0000
C in binary is 1100
Full Byte 1: 00001100

Step 2: Identify the Bit Positions
In a 29-bit extended CAN ID, the bits are numbered 0 to 28. 
J1939 assigns these bits to specific fields:
1.Bits 0–7: Source Address (Last two hex digits: 01)
2.Bits 8–23: PDU Specific and PDU Format (Middle hex digits: F004)
3.Bits 24–25: Data Page and Extended Data Page
4.Bits 26–28: Priority (The 3 most significant bits of the 29-bit ID)

Step 3: Extract the Priority Bits
When you look at the first two bytes of your ID 0CF00401, they are laid out in a 32-bit register like this:
000(ignored/filler for 32-bit) + 011(Priority) + 00 ( Reserved or EDP / Data Page ) + 11110000 (PDU Format)

Summary of Priority Values
1.000 (0) = Highest Priority
2.011 (3) = Standard Control Message (Your value)
3.111 (7) = Lowest Priority

Priority (3 bits)	        011 (3)
EDP & DP (2 bits)         00  (page 0)
PDU Format (8 bits)       F0  (240)
PDU Specific (8 bits)     04  (04)
Source Address (8 bits)   01  (1)

1.Priority: 3 (High priority).
2.PGN Extraction: Combine the Data Page, PF, and PS
->In Hex: 0x0F004
->In Decimal: PGN 61444 (Electronic Engine Controller 1 - EEC1).
->Source Address: 01 (Typically the Engine Controller).

Identifying the Parameters (SPNs)
Now we look at the 8 Bytes of Data using the "blueprint" for PGN 61444 found in 
the SAE J1939-71 standard.
Data: F1 FF AA D0 1D FF FF FF

Raw Hex    SPN Name   	           Calculation Rule (SLOT)           Physical Value
F1         Engine Torque Mode      Bits 1-4                          0001 (Internal Control)
FF         Driver Demand Torque    1% per bit, -125 Offset           255 = Not Available
AA         Actual Engine Torque    1% per bit, -125 Offset           170-125= 45
D0 1D      Engine Speed            0.125 RPM per bit, 0 Offset       Calculated below
FF...      Various Status          Bit-mapped                        Not Available

EXAMPLE 2 : 

diaganosticmsg fram formate 
trasport protocal formate communication (handshaking)
CAN /J1939 Init speps from scrach in project 

EXAMPLE 2: J1939 PDU1 (Point-to-Point) Decoding
-------------------------------------------------------------------------
Imagine your CAN logger captures the following message:
ID: 18EA0001   DLC: 3   DATA: 04 F0 00

1. How to Identify PDU1 vs. PDU2
-------------------------------------------------------------------------
The J1939 standard uses the 8-bit PDU Format field (PF) to decide 
how the message is addressed:
PDU1 --> 0 to 239 (0x00 to 0xEF) -> Point-to-Point -> PS = Destination Address
PDU2 --> 240 to 255 (0xF0 to 0xFF) -> Broadcast      -> PS = Group Extension

2. Identifying the PGN (The Header)
-------------------------------------------------------------------------
Hex ID: 18 EA 00 01

Step 1: Convert Hex to Binary (First Byte)
Hex 18 -> Binary 00011000

Step 2: Identify the Bit Positions (29-bit Extended ID)
Bits 0-7   : Source Address (Last two hex digits: 01)
Bits 8-23  : PDU Specific and PDU Format (Middle hex digits: EA00)
Bits 24-25 : Data Page and Extended Data Page (EDP/DP)
Bits 26-28 : Priority (The 3 most significant bits)

Step 3: Extract the Priority Bits
Layed out in a 32-bit register:
filler + Priority + EDP/DP + PDU Format

Summary of Fields:
Priority (3 bits)       : 110 (6)
EDP & DP (2 bits)       : 00  (Page 0)
PDU Format (8 bits)     : EA  (234) -> [PDU1 because 234 < 240]
PDU Specific (8 bits)   : 00  (0)   -> [Destination Address = Engine]
Source Address (8 bits) : 01  (1)   -> [Sender = Management Computer]

PGN Extraction:
For PDU1, the Destination Address is masked to 00 for the PGN label.
-> In Hex: 0x0EA00
-> In Decimal: PGN 59904 (Request Message)

3. Identifying the Parameters (SPNs)
-------------------------------------------------------------------------
In a Request Message (PGN 59904), the data bytes indicate the PGN being 
requested from the target ECU.

Data: 04 F0 00

Raw Hex    Parameter Name         Description
--------   --------------------   ---------------------------------------
04 F0 00   Requested PGN          Stored as LSB first (Intel Byte Order)
                                  Reconstructed Hex: 0x00F004
                                  Decimal: PGN 61444 (EEC1)

Summary:
ECU 01 is sending a specific Request (PDU1) to the Engine (ECU 00) 
asking it to broadcast PGN 61444 (Engine Speed/Torque).

*/
