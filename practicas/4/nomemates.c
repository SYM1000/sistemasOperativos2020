#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void signalHandler(int signum){
    printf("HHAHAHHAA no me matas \n");
}


int main(){
    signal(17, signalHandler);
    while(1){
        sleep(2);
        printf("Trabajando \n");
    }
    return 0;
}