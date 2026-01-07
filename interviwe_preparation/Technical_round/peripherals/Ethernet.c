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
 * /*
 * ETHERNET FRAME FIELD EXPLANATIONS:
 *
 * Preamble: 
 *   - Purpose: Acts as a "get ready" signal and clock synchronization mechanism.
 *   - Details: A 7-byte alternating pattern of 1s and 0s (10101010...) that helps the 
 *     receiving device lock onto the incoming signal's timing.
 *
 * SFD (Start Frame Delimiter): 
 *   - Purpose: The "starting gun." Marks the end of the preamble and the start of data.
 *   - Details: A specific 1-byte code (10101011) that immediately precedes the destination
       address.
 *
 * Destination MAC: 
 *   - Purpose: Specifies the hardware address of the intended recipient device on 
       the network.
 *   - Details: A unique, 6-byte (48-bit) physical address assigned to every network 
       interface card (NIC).
 *
 * Source MAC: 
 *   - Purpose: Specifies the hardware address of the sender device.
 *   - Details: A unique, 6-byte (48-bit) physical address of the NIC that initiated
       the transmission.
 *
 * EtherType / Length: 
 *   - Purpose: Identifies what kind of data is in the payload or how long the payload is.
 *   - Details: A 2-byte field.
 *     - If value >= 1536 (0x0600): Identifies the Network Layer protocol (e.g., IPv4, IPv6).
 *     - If value <= 1500: Indicates the length of the subsequent data payload in bytes.
 *
 * Payload (Data): 
 *   - Purpose: The actual message or data from an upper-layer protocol.
 *   - Details: 
 *     - Minimum Size (46 bytes): Required to meet the 64-byte minimum frame 
          size (total frame, excluding preamble/SFD) necessary for 
          CSMA/CD collision detection to work reliably. Padding is added if the 
          original data is smaller.
 *     - Maximum Size (1500 bytes): The standard Maximum Transmission Unit (MTU) limit.
 *
 * FCS (Frame Check Sequence): 
 *   - Purpose: Error detection (Cyclic Redundancy Check - CRC).
 *   - Details: A 4-byte mathematical checksum. The sender calculates it, and the
       receiver recalculates it upon arrival. If the results don't match, the frame
       is corrupted and dropped.
 */

 * 3. KEY OPERATIONAL CONCEPTS
 * --------------------------------------------------------------------------------------
 * CSMA/CD:      Carrier Sense Multiple Access with Collision Detection.
 *               Used in Half-Duplex (Legacy). Modern Ethernet uses Full-Duplex.
 * Duplex:       Full-Duplex allows simultaneous Send/Receive (No collisions).
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
