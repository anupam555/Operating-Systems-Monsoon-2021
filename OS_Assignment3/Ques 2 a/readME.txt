Ques 2. 
a)
                                Domain Sockets
Using UNIX Domain Sockets is a technique used in interprocess communications.
A socket is composed of IP Address and ports. 
We make 2 process, one is a socket of type server and other is socket of type client. Both communicate to each other using the System calls.
Using the IP Address, a connection gets formed between the 2 process. Usually a server is ready with its socket and tries to listen to a client.
Once a connection is established between a server and a client, then data can be easily transferred from 1 process to another.

Here we have used a stream socket, which is type of interprocess communications socket or network socket which provides a connection-oriented, sequenced, and unique flow of data.
Some of the system calls used in making a connection between 2 ports(processes) are as follows:

1. Create()	To create a socket
2. Bind()	used for socket identification(like a telephone number to contact)
3. Listen()	receives a connection 
4. Connect()	acts as a sender 
5. Accept()	Confirmation, to accept so as to receive a call from a sender 
6. Write()	To send data 
7. Read()	To receive data 

