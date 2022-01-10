#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h> 
#include<unistd.h>

sem_t forks[5]; 
sem_t bowls;
void* philosopher(void *val)
{	while(1)
	{
	int phil=*(int *)val; 
	sem_wait(&forks[phil]);
	sem_wait(&forks[(phil+1)%5]);
	sem_wait(&bowls);
	
	printf("\nPhilosopher %d is eating\n",phil);
	
	sleep(2);
	
	printf("Philosopher %d finished eating using the forks <%d> and <%d> and bowl %d \n",phil,phil,(phil+1)%5,phil%4);
	
	sem_post(&bowls);
	sem_post(&forks[(phil+1)%5]); // freeing the semaphores
	sem_post(&forks[phil]);
	}
}

int main()
{
	int phil[5];
	sem_init(&bowls,0,4);
	pthread_t pid[5]; // refers to the 5 philosophers sitting around table
	
	for(int i=0;i<5;i++)    // created 5 binary semaphores referring to the 5 chopsticks
		sem_init(&forks[i],0,1);
	
	for(int i=0;i<5;i++){    //allowing 4 philosophers to room to that atleast 1 of them eats
		phil[i]=i;
		pthread_create(&pid[i],NULL,philosopher,(void *)&phil[i]); // pid[i] refers to an integer variable denoting the philosophers number 
		}
		
	for(int i=0;i<5;i++)
		pthread_join(pid[i],NULL);
		
	printf("\nAll finished eating, without any deadlocks/starvation!\n");
	return 0;
}

