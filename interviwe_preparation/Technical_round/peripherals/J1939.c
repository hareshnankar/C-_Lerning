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

*/
