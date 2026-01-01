<!doctype html>
<html lang="en">
<head>
<meta charset="utf-8">
<meta name="viewport" content="width=device-width,initial-scale=1">
<title>adc.c — A4 printable (larger font)</title>
<style>
  html,body { height:100%; margin:0; padding:0; background:#fff; color:#000; }
  /* A4 print area and margins */
  @page { size: A4; margin: 15mm; }
  body { padding: 0; margin: 0; }

  /* The content area equals printable width: 210mm - 2*15mm = 180mm */
  .sheet {
    box-sizing: border-box;
    width: 180mm;               /* printable content width */
    min-height: 297mm;
    padding: 0;
    margin: 0 auto;
    background: white;
  }

  /* Title and source (non-file content) */
  .title { font-family: sans-serif; font-size: 16pt; margin: 6mm 0 4mm 0; }
  .sourceurl { font-family: sans-serif; font-size: 9pt; color:#444; margin-bottom:6mm; }

  /* Larger, readable monospace font for multiple pages */
  pre {
    font-family: "Courier New", Courier, monospace;
    font-size: 14pt;           /* BIGGER font as requested */
    line-height: 1.28;
    white-space: pre;          /* preserve spaces and line breaks exactly */
    overflow-wrap: anywhere;   /* allow breaking long sequences to fit the printable width */
    word-break: break-all;     /* ensures long repeated characters won't create horizontal overflow */
    margin: 0;
    padding: 0;
    tab-size: 4;
  }

  @media print {
    .sheet { box-shadow: none; margin: 0; }
    .title, .sourceurl { color: #000; }
  }
</style>
</head>
<body>
  <pre>
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

TCP/IP SOCKET PROGRAMMING OVERVIEW
----------------------------------------------------------------------------
A socket acts as an endpoint for communication between two devices on a 
network. It uses the TCP/IP protocol to ensure that data is delivered 
reliably to the correct destination.

1. Identification (IP and Port)
A socket is defined by an IP Address and a Port Number. The IP address 
(Internet Protocol) is used to find the specific machine on the network, 
while the Port Number is used to identify the specific application or 
 service running on that machine.
  
 2. Server-Side Setup
 To receive data, a server performs three main actions:
 - Binding: The application binds the socket to a specific IP and Port so 
   the OS knows where to direct incoming traffic.
 - Listening: The server enters a state where it waits for a client to 
   request a connection.
 - Accepting: When a request arrives, the server accepts it, completing 
 the TCP Three-Way Handshake (SYN, SYN-ACK, ACK) to establish a connection.
  
 3. Client-Side Connection
 The client initiates communication by creating a socket and calling a 
 connect function. This sends a request to the server's IP and Port. Once 
 the server accepts, the TCP connection is fully established, and a 
 virtual "pipe" is created between the two applications.
  
 4. Data Transmission (The TCP Role)
 Once connected, data is sent as a continuous stream of bytes. TCP handles:
 - Segmentation: It breaks large data into smaller packets.
 - Acknowledgments: The receiver sends an "ACK" for every packet received. 
 If the sender doesn't get an ACK, it retransmits the data.
 - Sequencing: TCP ensures that packets arriving out of order are 
 rearranged correctly before the application reads them.
  
 5. Reading and Writing
 In socket programming, sending and receiving data is handled like reading 
 or writing to a file. An application "writes" data to the socket to send 
 it and "reads" from the socket to receive data sent by the other side.
 
 6. Closing the Connection
 When the communication is finished, the TCP/IP protocol performs a 
 Four-Way Handshake to close the connection. This ensures that all data in 
 transit has been received and acknowledged before the socket is destroyed 
 and the port is released.
 ----------------------------------------------------------------------------
 */
   </pre>
</div>
</body>
</html>


