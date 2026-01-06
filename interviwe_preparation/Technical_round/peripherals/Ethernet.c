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
 * 4. MODERN EVOLUTION (2026 STATUS)
 * --------------------------------------------------------------------------------------
 * Speeds:       Standard 1Gbps/10Gbps; 800Gbps and 1.6Tbps in AI/Data Centers.
 * PoE:          Power over Ethernet (802.3bt) delivers up to 100W to devices.
 * Reliability:  Ethernet is "Best-Effort." It detects errors (FCS) but does NOT
 *               retransmit. Retransmission is handled by Layer 4 (TCP).
 * ======================================================================================
 */
