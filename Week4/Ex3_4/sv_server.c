#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<errno.h>
#include<time.h>
typedef struct sockaddr_in sockaddr_in;


typedef struct birthday
{
    int date;
    int month;
    int year;
}birthday;

typedef struct student_info
{   
    char mssv[1000];
    char name[1000];
    birthday date;
    double average_point;
    char current_time[1000];
    char ip[1000];
}student_info;


int main(int argc,char * argv[]){
    if (argc != 3) {
        printf("Please use this format: tcp_server <server_port> <file_name>\n");
        exit(1);
    }
    sockaddr_in server;
    server.sin_addr.s_addr = htonl(INADDR_ANY);
    server.sin_family = AF_INET;
    server.sin_port = htons(atoi(argv[1]));
    //Create socket
    int sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if(sockfd==-1){
        printf("Error: %d - %s\n",errno, strerror(errno));
        printf("1\n");
        exit(1);
    }
    socklen_t server_len = sizeof(server);
    if(bind(sockfd,(struct sockaddr *)&server, server_len)){
        printf("Error: %d - %s\n",errno, strerror(errno));
        printf("2\n");
        exit(1);
    }
    if(listen(sockfd,5)==-1){
        printf("Failed to listen for incoming connections\n");
        exit(1);
    }
    sockaddr_in client;
    socklen_t client_len = sizeof(client);

    int client_id = accept(sockfd,(struct sockaddr*)&client,&client_len);

    if(client_id==-1){
        printf("Error: %d - %s\n",errno, strerror(errno));
        printf("3\n");
        exit(1);
    }

    char path_client_input_file[1000] = "/media/orind30/D/lap_trinh_mang/Week4/Ex3_4/";
    strcat(path_client_input_file,argv[2]);
    if(strstr(path_client_input_file,"txt")==NULL){
        strcat(path_client_input_file,".txt\0");
    }
    FILE * input = fopen(path_client_input_file,"a");
    while(1){
        student_info stu;
        int data = recv(client_id,&stu,sizeof(student_info),0);
        printf("%d\n",data);
        if(data<=0){
            printf("Connection closed!");
            break;
        }
        else{
            printf("Getting data...\n");
            printf("%s %s %d-%d-%d %lf %s %s",stu.mssv,stu.name,stu.date.year,stu.date.month,stu.date.date,stu.average_point,stu.ip,stu.current_time);
            fprintf(input,"%s %s %d-%d-%d %lf %s %s",stu.mssv,stu.name,stu.date.year,stu.date.month,stu.date.date,stu.average_point,stu.ip,stu.current_time);
        }
    }

    close(client_id);
    close(sockfd);
}
