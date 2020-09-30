#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>


void signalHandler(int signum){
    int status;
    //printf("HHAHAHHAA no me matas \n");
    //sleep(2);
    wait(&status);
    printf("mi hijo termino %d", status);
}
void controlC(){
    printf("Contro c precionado");
}

int main(int argc, char **argv){
    signal(17, signalHandler);
    //signal(2, controlC);

    unsigned pid = fork();
    if(pid == 0){
        sleep(5);
        printf("Soy el proceso hijo\n");
        //execve(argv[1],newargv,newargve);
        //execv(argv[1],&argv[1]);
        return 10;
    }else{
        
        sleep(2);
        printf("Soy el proceso padre y mi hijo es %u\n",pid);
        while(1){
            //Aqui llegan nuevas peticiones
            sleep(2);
            printf("trabajando \n");
        }
        
    }
   printf("Hola mundo\n"); 
    return 0;
}
