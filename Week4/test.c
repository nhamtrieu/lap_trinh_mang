#include<stdio.h>
#include<string.h>


int main(){
    FILE * file = fopen("/media/orind30/D/lap_trinh_mang/Week4/hello.txt","w");
    char input[1000];
    while(1){
        fgets(input,sizeof(input),stdin);
        if(!strncmp(input,"exit",4)){
             break;
        }
        fprintf(file,"%s",input);
    }
    fclose(file);
}