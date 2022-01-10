#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <string.h>
#include<pthread.h>

float marks[6];
float mark[6];
int read_line(int fd, char *buffer, int buffersize) {
    memset(buffer, 0, 100);
    int i=0;
    while(i<buffersize && read(fd, &buffer[i], 1)>=0)
    {   
        if(buffer[i] == '\n') {
            buffer[i] = '\0';
            return 1;
        }
        i++;
    }
    return 0;
}

void printSize(char *str, int size) {
    syscall(1, STDOUT_FILENO, str, size);
}

void print(char *str) {
    int len = strlen(str);
    printSize(str, len);
}

void printInt(int input) {
    char string[20];
    sprintf(string, "%d", input);
    print(string);
}

void printFloat(float input) {
    char str[100];
    sprintf(str, "%f", input);
    print(str);
}

void* func(void * args)
{	
     puts("We are inside the thread.");
     printf("PID in thread: [%d]. Compare to the PID of the process.\n", getpid());
    int fp=open("student_record.csv",O_RDONLY);
    if(fp==-1)
    {   print("failed to open\n");
        exit(0);
    }   
    char buffer[100];
    int count=0;
    for(int i=0; i<6; i++)
    {   marks[i]=0;
    }
    
    read_line(fp, buffer, 100);

    while(read_line(fp, buffer, 100) > 0) {
        char *value=strtok(buffer, ",");  
        value = strtok(NULL, ",");
    if(value[0]=='A')
    {   count+=1;
        for(int i=0; i<6; ++i) {
            value = strtok(NULL, ",");
            marks[i]+= atoi(value);
            }
    }
    }
    close(fp);
    print("Section A average\n");
    for(int i=0; i<6; i++)
    {
      marks[i]=marks[i]/count;
      }
    for(int i=0; i<6; i++)
    {
        print("Assignment ");
        printInt(i+1);
        print(" Average marks ");
        printFloat(marks[i]);
        print("\n");
    }
   pthread_exit(NULL);
}
void* func1(void * args)
{   puts("We are inside the thread.");
    printf("PID in thread: [%d]. Compare to the PID of the process.\n", getpid());
    
    int fd  = open("student_record.csv", O_RDONLY);

    if(fd ==-1) {
        perror("Error opening file!\n");
        exit(0);
    }

    char data[100];
    int count=0;
    for(int i=0; i<6; i++)
    {   mark[i]=0;
    }
    read_line(fd, data, 100);
    while(read_line(fd, data, 100)) {
    char *value;
        
    value = strtok(data, ",");
    value = strtok(NULL, ",");

    if(value[0]=='B')
    {   count+=1;
        for(int i=0; i<6; ++i) {
            value = strtok(NULL, ",");
            mark[i]+= atoi(value);
        }
    }
    }
    close(fd);  
    print("Section B average \n");
    for(int i=0; i<6; i++)
    {
      mark[i]=mark[i]/count;
      }
    for(int i=0; i<6; i++)
    {	
           print("Assignment ");
           printInt(i+1);
           print(" Average marks ");
           printFloat(mark[i]);
           print("\n");
    } 
    pthread_exit(NULL);
}
int main()
{   
    pthread_t thread[2];
    pthread_create(&thread[0],NULL,func,NULL);
    pthread_create(&thread[1],NULL,func1,NULL);

    pthread_join(thread[0],NULL);
    pthread_join(thread[1],NULL);

    for(int i=0; i<6; i++)
    {
    	print("Average of Assignment ");
    	printInt(i+1);
    	print(" Average marks ");
    	printFloat((marks[i]+mark[i])/2);
    	print("\n");
    }
    printf("Printing process is complete");
    return 0;
}
