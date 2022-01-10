#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include<errno.h>

#define PROJECT_PATHNAME "writer_que.c"
#define PROJECT_ID 57
#define MSG_SIZE 512

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

struct msg_struct
{
    long type;
    char msge[4];
}message;

int main()
{   int msg_type = 1;
    struct msg_struct msg[50]; 
    for (int j = 0; j <50; j++) {
        msg[j].type = j;
        strcpy(msg[j].msge, randstring(4));
    }  	
    for(int j = 0; j < 50; j+=5) {
    char buff[512];
    for(int k=0; k<5; k++)
    {  strcat(buff, msg[j+k].msge);
       strcat(buff," ");
    }
    key_t key = ftok(PROJECT_PATHNAME, PROJECT_ID);
    if(key==-1)
    {
      printf("Error generating msg key!\n%s", strerror(errno));
      return -1;
    }

    int qid = msgget(key, 0666|IPC_CREAT); // to create a message queue
    if(qid==-1)
    {
       printf("Error retrieving queue id!\n%s", strerror(errno));
       return -1;
    }
    char token[4];
    int index=0;
	
    for(int i=0; buff[i]!='\0'; i++)
    {	if(buff[i]==' '|| buff[i]=='\n')   //space or newline
        { token[index++]='\0';             // null terminator
          strcpy(message.msge, token);     //send data
          message.type = msg_type++;       // Change the message type field
          if(msgsnd(qid, &message, MSG_SIZE, 0)==-1)
          {   printf("Error sending message!\n%s", strerror(errno));
              return -1;
          }
          index=0;
        }
        else
        {	token[index++] = buff[i];
          }
     }
   }
  return 0;    
}
    
