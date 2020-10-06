#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main(){

    //Variables
    char c;
    char buffer[250];
    unsigned i = 0;
    unsigned lineas = 0;
    unsigned palabras = 0;
    unsigned caracteres = 0;


    while(read(STDIN_FILENO,&c,1) != 0){

        i++;
        buffer[i] = c;
        
        if(c != '\n'){
            caracteres++;
        }

        if(c != ' '){
            if (i > 1 && buffer[i-1] != '\n' && buffer[i-1] != ' ' ) {
                palabras++;
            }
        }else if (c == '\n') {
            lineas ++;
            if (buffer[i-1] != ' ' && i > 1){
                palabras++;
            }
            i=0;
        }
        //write(STDOUT_FILENO, &c, 1);
    }

    caracteres = caracteres+lineas;
    printf("%u\n", lineas);
    printf("%u\n", palabras);
    printf("%u\n", caracteres);
    return 0;
}