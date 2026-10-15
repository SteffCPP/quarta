#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
    int pid;
    printf("1) Before fork\n");
    pid = fork();
    printf("2) After fork, and I will get executed twice.\n");

    if(pid == 0){
        printf("3) I'm the child process \n");
        exit(1);
    }else{
        printf("3) I'm the father process\n");
        exit(0);
    }
    
    return 0;
}