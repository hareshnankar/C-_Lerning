/*
 * ======================================================================================
 * ETHERNET PROTOCOL (IEEE 802.3) - INTERVIEW PREPARATION CHEAT SHEET
 * ======================================================================================
 * 
 * 1. LAYERS & ENCAPSULATION
 * --------------------------------------------------------------------------------------
 * OSI Layers: Physical (Layer 1) and Data Link (Layer 2).
 * Data Unit: "Frame" (Layer 2) - Encapsulates "Packets" (Layer 3).
 * Addressing: 48-bit MAC Addresses (Hexadecimal format).
 * 
 * 2. ETHERNET II FRAME STRUCTURE
 * --------------------------------------------------------------------------------------
 * | Field            | Size (Bytes) | Purpose                                         |
 * |------------------|--------------|-------------------------------------------------|
 * | Preamble         | 7            | Synchronization                                 |
 * | SFD              | 1            | Start Frame Delimiter (10101011)                |
 * | Destination MAC  | 6            | Target Hardware Address                         |
 * | Source MAC       | 6            | Sender Hardware Address                         |
 * | EtherType/Length | 2            | Protocol type (e.g., IPv4 = 0x0800)             |
 * | Payload (Data)   | 46 - 1500    | Upper layer data (padded if < 46 bytes)         |
 * | FCS (CRC)        | 4            | Error detection (Frame Check Sequence)          |
 * --------------------------------------------------------------------------------------
 * Note: Minimum frame size = 64 bytes | Maximum standard frame (MTU) = 1518 bytes.
 * 
 * 3. KEY OPERATIONAL CONCEPTS
 * --------------------------------------------------------------------------------------
 * CSMA/CD:      Carrier Sense Multiple Access with Collision Detection.
 *               Used in Half-Duplex (Legacy). Modern Ethernet uses Full-Duplex.
 * Duplex:       Full-Duplex allows simultaneous Send/Receive (No collisions).
 * Domains:      Switches break Collision Domains. Routers break Broadcast Domains.
 * MTU:          Maximum Transmission Unit (Standard: 1500 bytes).
 * Jumbo Frames: Frames up to 9000 bytes used in data centers for efficiency.
 * 
 ---------------------------------------------------------------------------------------
CARRIER SENSE MULTIPLE ACCESS WITH COLLISION DETECTION (CSMA/CD)
CSMA/CD is a set of rules used by computers to share a single network wire without 
talking over each other. Think of it like a group of polite people having a conversation.
THE BASIC RULES
Carrier Sense (Listen): Before a computer sends data, it "listens" to the wire. If it 
hears someone else talking, it waits.
Multiple Access (Share): Many computers are connected to the same wire, and they 
all have an equal right to use it.
Collision Detection (Watch): While a computer is talking, it keeps listening. 
If it hears another computer start talking at the same time, it knows a "collision" 
happened.
WHAT HAPPENS DURING A CLASH?
Stop Immediately: If two computers talk at once, the data gets scrambled. Both 
computers stop sending data right away.
Warning Signal: They send out a "Jam Signal" to let every other computer know there
was a crash.
Random Wait: Each computer picks a random amount of time to wait (like one picking
3 seconds and the other picking 5). This prevents them from crashing again by 
starting at the exact same time.
Try Again: Once the wait is over, the computer listens again and tries to send the 
data one more time.
SUMMARY
In short: Listen first, talk if it's quiet, stop if someone else starts, wait a 
random bit, and try again.

 */
