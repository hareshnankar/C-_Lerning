
/*
The Open Systems Interconnection (OSI) Model is a conceptual framework that standardizes the functions
of a communication system into seven distinct layers. Developed by the International Organization for 
Standardization (ISO), it helps different vendors and technologies communicate by defining how data
moves from a physical wire all the way to a software application.

The Seven Layers of the OSI Model:
Layer 7: Application Layer
This is the only layer that directly interacts with data from the user. Software applications 
like web browsers and email clients rely on this layer to initiate communications. Common protocols 
include HTTP for web browsing, SMTP for email, and FTP for file transfers.

Layer 6: Presentation Layer
This layer acts as a translator. It is responsible for formatting, encrypting, and compressing 
data so that it is presented correctly to the application layer. It ensures that data sent from 
one system can be understood by the application on another system.

Layer 5: Session Layer
This layer is responsible for opening, closing, and managing communication sessions between 
two devices. It ensures that the session stays open long enough to transfer all data and includes 
checkpoints so that if a connection is interrupted, the transfer can resume from the last known good point.

Layer 4: Transport Layer
This layer handles end-to-end communication, flow control, and error correction. It takes data 
from the session layer and breaks it into smaller "segments." On the receiving end, it reassembles 
these segments. Common protocols here are TCP (which ensures delivery) and UDP (which prioritizes speed).

Layer 3: Network Layer
The network layer is responsible for moving data between different networks. It breaks segments
into smaller units called "packets." It uses logical addressing, such as IP addresses, to find 
the best physical path for the data to reach its destination, a process known as routing.

Layer 2: Data Link Layer
This layer facilitates data transfer between two devices on the same network. It takes packets 
from the network layer and breaks them into "frames." It uses physical addresses, known as 
MAC addresses, to ensure data reaches the correct hardware on a local network. 
It also performs basic error checking for the physical layer.

Layer 1: Physical Layer
This is the lowest layer, consisting of the actual physical equipment involved in data transfer, 
such as cables, switches, and radio waves. This layer converts the data into a bitstream of 1s
and 0s and transmits the electrical, light, or radio signals across the medium.


TCP/IP PROTOCOL OVERVIEW
TCP/IP (Transmission Control Protocol/Internet Protocol) is the fundamental suite of communication protocols 
used to interconnect network devices on the internet and private networks. It specifies how data is broken 
into packets, addressed, transmitted, routed, and reassembled at its destination.

THE FOUR FUNCTIONAL LAYERS
Application Layer: This is the top layer where users and software applications interact with 
network services. It utilizes well-known protocols such as HTTP for web browsing, 
SMTP for sending emails, and FTP for file transfers to prepare data for network transmission.

Transport Layer: This layer is responsible for end-to-end communication, reliability, and flow control. 
It primarily uses TCP (Transmission Control Protocol) for guaranteed, error-checked delivery or
UDP (User Datagram Protocol) for faster, non-guaranteed transmission.

Internet Layer: Often called the Network Layer, it handles the routing and addressing of data packets. 
It uses IP addresses to ensure that each packet reaches the correct destination across different 
interconnected networks and routers.

Network Access Layer: The lowest layer of the stack, managing the physical transmission of data over
hardware. This includes the protocols required to send bits over physical media like Ethernet cables, 
fiber optics, or Wi-Fi signals.

THE DATA TRANSMISSION PROCESS
Step 1: Connection Establishment (Three-Way Handshake)
Before any data is sent, the sender and receiver must synchronize. The sender sends a synchronization 
request (SYN), the receiver responds with a synchronization-acknowledgment (SYN-ACK), and the sender 
confirms with an acknowledgment (ACK) to establish the session.

Step 2: Data Transfer
The message is broken into small, manageable segments, each assigned a specific sequence number.
As the receiver collects these segments, it sends an acknowledgment back to the sender to 
verify that the information arrived safely.

Step 3: Error Handling
TCP is designed to be "self-healing." If a packet is lost, damaged, or arrives out of order, 
the protocol automatically requests a retransmission of the missing data or rearranges the 
segments into the correct order based on their sequence numbers.

Step 4: Connection Termination (Four-Way Handshake)
Once all data has been successfully transmitted and confirmed, a final four-way handshake is 
used to close the session. This ensures that both the sender and the receiver have finished 
their communication and that no data is left in transit.
*/

