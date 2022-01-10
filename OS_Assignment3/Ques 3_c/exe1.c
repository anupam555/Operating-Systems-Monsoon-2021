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

struct msg_packet
{   int id;
    char msgstr[5];
};

char *randstring(size_t len) {
    static char charset[] = "abcdefghijklmnopqrstuvwxyz";        
    char *randomStr = NULL;

    if(len) {
        randomStr = malloc(sizeof(char) * (len +1));

        if (randomStr) {            
            for (int n = 0; n < len; n++) {            
                randomStr[n]= 'a'+ rand() % 26;
            }
            randomStr[len] = '\0';
        }
    }
    return randomStr;
}
int main(int argc, char const *argv[])
{   
    struct msg_packet msg[50]; 
    int wordlen=5; 
    int n;
    for (int j = 0; j < 50; j++) {
        msg[j].id = j;
        strcpy(msg[j].msgstr, randstring(5));
    }
    char fname[MAX_FILENAME_SIZE];
    strcpy(fname, "test_fifo");
    // * if the user gives a name for an existing fifo, use that, else, use the one created by the writer process

    if(argc > 1)
    {   strcpy(fname, argv[1]);
    }
    else
    {   errcheck(mkfifo(fname, 0777), "Error creating FIFO!\n");
    }

    int fifo_file;
    for(int cnt=0; cnt<49; cnt++)
    {
        struct msg_packet container[5];
        for(int k=0; k<5; k++)
        {   container[k]=msg[cnt+k];
        }
        fifo_file=errcheck(open(fname, O_WRONLY), "Error opening FIFO!\n");
        errcheck(write(fifo_file, container, sizeof(container)), "Error writing to FIFO!\n");
        errcheck(close(fifo_file), "Error closing FIFO!\n");
        char buffer[BUFFLEN];
        fifo_file=errcheck(open(fname, O_RDONLY), "Error opening FIFO!\n");
        errcheck(read(fifo_file, buffer, BUFFLEN), "Error reading from FIFO!\n");
        errcheck(close(fifo_file), "Error closing FIFO!\n");
        cnt = buffer[0];
    }
    if(argc <= 1)
    {   errcheck(remove(fname), "Error removing FIFO!\n");
    }
    return 0;
}
