#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char **argv){
    char *sourceFile = argv[1];
    char *destinoFile = argv[2];

    int fd = open("./lee.c", O_RDONLY, 0); //Abrir archivos, fopen
    if(fd < 0){
        printf("Error al abrir el programa ");
        return 1;
    }
    int dfd = open(destinoFile, O_WRONLY | O_CREAT, 0600);
    char c;
        while (read(fd, &c, 1)) {
            write(dfd, &c, 1);
            //printf("%c", c);
    }
    close(fd);
    close(dfd);
    return 0;
}