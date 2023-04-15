#include<stdio.h>
# include<string.h>


int main(){
    char command[1000];
    //Input data using fgets
    printf("Enter your command: ");
    fgets(command,sizeof(command),stdin);
    char cmd[10];
    int para1,para2;
    char check[100];
    int no_parameter = sscanf(command,"%s %d %d %s",cmd,&para1,&para2,check);
    printf("%d\n",no_parameter);
    if(no_parameter!=3){
        printf("Error! Please check your input parameters\n");
    } 
    else{
        if(strcmp("ADD",cmd)||strcmp("DEL",cmd)||strcmp("MUL",cmd)||strcmp("DIV",cmd)){
            printf("OK getting input....");
            getchar();
        }
        else{
            printf("Please check your input parameters\n");
        }
    }
    return 1;
}