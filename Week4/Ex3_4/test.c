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

int main(){
    printf("Input data for student\n");
    while(1){
        fflush(stdin);
        student_info stu;
        printf("Enter id for student: ");
        scanf("%[^\n]%*c",stu.mssv);
        printf("Enter name for student: ");
        scanf("%[^\n]%*c",stu.name);
        printf("Enter birthday for student (yyyy/mm/dd): ");
        char date[20];
        scanf("%s",date);
        stu.date.year = atoi(strtok(date,"/"));
        stu.date.month = atoi(strtok(NULL,"/"));
        stu.date.date = atoi(strtok(NULL,"/"));
        getchar();
        printf("Enter average grade: ");
        scanf("%lf",&stu.average_point);
        getchar();
        printf("Do you want to send to Server (Y/N): ");
        char option;
        scanf("%c",&option);
        strcpy(stu.ip,"123");
        time_t t;
        time(&t);
        strcpy(stu.current_time,ctime(&t));
        getchar();
        if(option=='Y'||option=='y'){

        }
        printf("Do you want to enter data for other student?(Y/N): ");
        scanf("%c",&option);
        getchar();
        if(option=='N'||option=='n'){
            break;
        }
    }
}
