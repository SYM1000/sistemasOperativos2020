#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char **argv){

    unsigned pid = fork();
    if(pid == 0){
        char *newargv[] = {NULL};
        char *newargve[] = {NULL};
        newargv[0] = argv[1];
        printf("Soy el proceso hijo\n");
        //execve(argv[1],newargv,newargve);
        execv(argv[1],&argv[1]);
        return 10;
    }else{
        int status;
        printf("Soy el proceso padre y mi hijo es %u\n",pid);
        wait(&status);
        printf("Termindnado despues del hijo y el estatus es %d\n", status);
    }

    

    printf("Hola mundo\n"); 

    return 0;
}