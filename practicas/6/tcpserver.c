#include <netdb.h>
#include <stdio.h>
#include <sys/socket.h>
#include <strings.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char **argv){

    struct sockaddr_in serverAddress;
    
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(2727);
    serverAddress.sin_addr.s_addr = htonl(INADDR_ANY);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    bind(sockfd, &serverAddress, sizeof(serverAddress));
    listen(sockfd, 5);

    while(1){
        struct sockaddr_in clientAddress;
        int clinetSize = sizeof(clientAddress);
        int clientSocket = accept(sockfd, &clientAddress, &clinetSize);
        char c;
        char *message = "Hellou desde gitpod";
        //while(read(clientSocket, &c, 1)){
          //  printf("%c",c);   
        //}
        write(clientSocket, message, strlen(message));
        close(clientSocket);
    }
}