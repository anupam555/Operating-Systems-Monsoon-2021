#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <string.h>

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

int main()
{   
    pid_t ret_value;
    ret_value=fork();
    if(ret_value==0) // child process
    {   int fp=open("student_record.csv",O_RDONLY);
        if(fp==-1)
        {   print("failed to open\n");
            exit(0);
        }   
        char buffer[100];
        float marks[6];
        int count=0;
        
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
           print("Assignment:");
           printInt(i+1);
           print("Average marks");
           printFloat(marks[i]/count);
           print("\n");
        }
        exit(0);
      }
    else {
    
        waitpid(0, NULL, 0);
        int fd  = open("student_record.csv", O_RDONLY);

        if(fd ==-1) {
            perror("Error opening file!\n");
            return -1;
        }

        char data[100];
        float marks[6];
        int count=0;
        
        read_line(fd, data, 100);
        while(read_line(fd, data, 100)) {
        char *value;
        
        value = strtok(data, ",");
            
        value = strtok(NULL, ",");

        if(value[0]=='B')
        {   count+=1;
            for(int i=0; i<6; ++i) {
                value = strtok(NULL, ",");
                marks[i]+= atoi(value);
            }
         }
    	}
      close(fd);  
      print("Section B average \n");
      for(int i=0; i<6; i++)
       {	
           print("Assignment:");
           printInt(i+1);
           print("Average marks");
           printFloat(marks[i]/count);
           print("\n");
       }
    }
    return 0;
  }
