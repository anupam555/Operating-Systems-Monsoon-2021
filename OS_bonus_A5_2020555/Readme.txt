			PROCESS SYNCHRONISATION USING SEMAPHORES
Using Semaphores for solving shared data resource problems like the famous Dining Philosophers.
It can be initialised using sem_init().

i) All the philosopher only think and eats without talking to each other.
When a philosopher gets hungry, he tries to pick 2 forks on his/her left and right, but not if it is already occured by the neighbour.

A philosopher tries to grab a fork using wait() on Semaphores.
Only releases the fork after he has finished eating and calls the signal() for the Semaphores.

The shared data resource is acquired/released with the help of the 2 operations between the threads created for each of the philosopher using pthread_create.
Also all the chopsticks/forks are initialised to 1 as a binary semaphore, which is a mutex lock ranging between 0 and 1.

To avoid the deadlock condition, where each member holds the left fork thereby waiting indefinitely for the right fork,
it is suggested to first check if both the forks are present on the table and afterwards picking up both until finishes.

ii) Now there are 4 sauce bowls present on the table, and each member can use the left fork to eat. The situation now is at max 4 philosopher can eat at a time, thereby creating 
a semaphore on the no of bowls present, where if the count reaches zero, then the thread goes to a waiting state, until one of the bowl gets placed back on the table.
In this scenario, every philospher will eat only after he gets a bowl and a fork, and therefore only a single person would be waiting at a time,thus there will not be any
deadlock/starvation.

iii) The situation overlaps both the above 2 conditions, to have 2 forks and a bowl to eat. In that case too, we would take a semaphore storing the values for the number of bowls and forks
   and also passing the thread as an argument for each philosopher. There might be deadlock, if we allow every philosopher to take the left fork first, but because we are using 
   the semaphores, it makes the concurrent processes synchronised and if one thread is busy, other thread will wait until the others get free.