#include<stdio.h>
#include<string.h>
#include<errno.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>

#include "util.h"

#define MAX_FILENAME_SIZE 512
#define BUFFLEN 2048

int main(int argc, char *argv[])
{   char filename[MAX_FILENAME_SIZE];
    strcpy(filename, "test_fifo");
    if(argc > 1)
    {   strcpy(filename, argv[1]);
    }

    for(int frq=1; frq<=10; frq++)
    {
        int fifo_fd = errcheck(open(filename, O_RDONLY), "Error opening FIFO!\n");
        char buffer[BUFFLEN];
        errcheck(read(fifo_fd, buffer, BUFFLEN), "Error reading from FIFO!\n");
        errcheck(close(fifo_fd), "Error closing FIFO!\n");
        int retrieve[5];
        int struct_size=12;
        for(int i=0; i<5; i++)
        {   retrieve[i]=buffer[i*struct_size];
        }
        char bucket[5][6];
        for(int st=0; st<5; st++)
        {
            for(int it=0; it<6; it++)
            {   if(it == 5)
                {
                    bucket[st][it]='\0';
                }
                else
                {
                    bucket[st][it]=buffer[struct_size*st + it + 4];
                }
            }
        }
        for(int i=0; i<5; i++)
        {
            printf("%d %s ", retrieve[i], bucket[i]);
            printf("\n");
        }
        fifo_fd= errcheck(open(filename, O_WRONLY), "Error opening FIFO!\n");
        write(fifo_fd, (void*)&retrieve[4], sizeof(retrieve[4]));
        errcheck(close(fifo_fd), "Error closing FIFO!\n");
    }
    exit(EXIT_SUCCESS);
}
