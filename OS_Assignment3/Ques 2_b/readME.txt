Ques 2. 


b) Message Passing Queues

In this technique of IPC, communication between processes takes place in the form of ‘messages’.

The kernel maintains a message queue to which sender processes can pass messages and from which receiver processes can retrieve messages.
The retrieval of messages need not be in a FIFO order and can take place as per a ‘type’ value.
The reading and writing of messages can happen in both blocking and non-blocking manner.
A new message queue can be created using the msgget() call.

We are passing our string in the tokenised form, i.e one token(word) will be sent at a time to the queue and then it will be recieved by the another process which prints each token along
with its type value.

---------------------------------------------------------------------------------------------------------------------------------------------------------
To COMPILE THE PROGRAM:  Use make command to compile both the files.  
To compile the files individually:   gcc -o writer_que writer_que.c 
                                     gcc -o reader_que reader_que.c

TO execute the program:
we can run the process by entering the cmd ./writer_que
In the another terminal, we can read the messages passed by 1st process:  ./reader_que 