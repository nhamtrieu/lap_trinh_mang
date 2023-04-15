#include<stdio.h>
#include<string.h>
#include<stdlib.h>


int main(){
    char pasv[] = "227 Entering Passive Mode (213,229,112,130,216,4)";
    char* index = strchr(pasv,'(');
    char input[6][1000];
    int i = 0;
    char * tok;
    tok = strtok(index+1,", )\"");
    while(tok!=NULL){
        strcpy(input[i],tok);
        i++;
        tok=strtok(NULL," ,)\"");
    }
    printf("IP: %s.%s.%s.%s:%d\n",input[0],input[1],input[2],input[3],atoi(input[4])*256+atoi(input[5]));
}