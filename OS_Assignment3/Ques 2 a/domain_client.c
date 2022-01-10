// Client side C/C++ program to demonstrate Socket programming

#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include<stdlib.h>
#define PORT 8080

struct msg_packet
{   int id;
    char msgstr[5];
}message;

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
	int sock = 0, valread;
	struct sockaddr_in serv_addr;
	struct msg_packet msg[50]; 
	for (int j = 0; j < 50; j++){
        msg[j].id = j+1;
        strcpy(msg[j].msgstr, randstring(5));
        }
        for(int j = 0; j < 50; j+=5) 
   	{ 
   	char buffer[512];
	if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
	printf("\n Socket creation error \n");
	return -1;
	}
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(PORT);
	
	// Convert IPv4 and IPv6 addresses from text to binary form
	if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0)
	{
		printf("\nInvalid address/ Address not supported \n");
		return -1;
	}

	if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
	{
		printf("\nConnection Failed \n");
		return -1;
	}
	struct msg_packet container[5];
    	for(int k=0; k<5; k++)
    	{    container[k]=msg[j+k];
    	   }
	send(sock ,&container, sizeof(container), 0 );
	valread=read(sock,buffer,512);
	}
	return 0;
}	

