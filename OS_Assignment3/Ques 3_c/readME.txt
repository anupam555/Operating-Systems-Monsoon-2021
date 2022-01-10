Ques 2. 

a) 
                  #################  FIFO PIPE IPC  ##################
To implement the interprocess communication via linux terminal using the Named Pipes(FIFO) technique.

There are 2 processes within the system, one is exe1.c and other is exe2.c with a FIFO pipe(file) attached within the two.

For the pipe(acts as a file), first process behaves as input file(to read) and second process acts as output(to write), similar to a sender and reciever transmission.

Both the processes communicate with each other via the FIFO file,and no data is actually written to the file system while communicating to each other.
(Kernel passes all the data from source to destination, without keeping any information with them).

This communication lasts as long as the processes are working, once exit the connection gets over.


We need to compile both the processes in the terminal and then start executing them in the different terminals, until one of the process get over.
------------------------------------------------------------------------------------------------------------------------------------------------------------------------

TO COMPILE THE PROGRAM:       gcc -o fileobj filename.c 

FOR RUNNING THE PROGRAM

1. Run the make command on the terminal.
2. Run the following commands:
	./exe1
3. Now open another terminal and run the following command:
	./exe2