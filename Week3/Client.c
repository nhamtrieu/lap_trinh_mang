#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <string.h>
#include <errno.h>

typedef struct sockaddr_in sockaddr_in;

int main(){
    sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    addr.sin_port = htons(9000);
    int socket_value = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if(socket_value!=-1){
        printf("Successfully connected\n");
    }
    else{
        printf("Failed to connect: %d - %s\n",errno,strerror(errno));
        return 1;
    }
    socklen_t addrlen = sizeof(addr);
    int connect_value = connect(socket_value,(struct sockaddr *)&addr, addrlen);
    if(connect_value==-1){
        perror("Failed");
        return 1;
    }
    char buff[1000];
    while (1)
    {
        printf("Input string: ");
        fgets(buff,sizeof(buff),stdin);
        if(!strncmp(buff,"exit",4)){
            printf("Break!\n");
            break;
        }
        send(socket_value,buff,strlen(buff),0);
    }
    close(socket_value);
    close(connect_value);   
}