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
J1939 allows messages up to 1785 bytes by splitting data across multiple CAN frames. It uses two primary methods
Broadcast Announce Message (BAM) : Used to send large data to all nodes. It begins with a BAM message 
(PGN 60416) defining the data length and PGN,followed by Data Transfer (DT) frames (PGN 60160) sent every 10–200ms

RTS/CTS (Connection Mode):
Request to Send (RTS): Sender asks to transmit data.
Clear to Send (CTS): Receiver confirms it is ready for a specific number of packets.
End of Message Acknowledgment (EoMA): Receiver confirms successful reception

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

Imagine your CAN logger captures the following message:
ID: 0CF00401 DLC: 8 DATA: F1 FF AA D0 1D FF FF FF

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
           Engine Torque Mode      Bits 1-4                          0001 (Internal Control)
           Driver Demand Torque    1% per bit, -125 Offset           255 = Not Available






*/
