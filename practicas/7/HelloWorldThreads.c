#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

//comile and link with -pthread.

typedef struct hd{
	int hid;
	char *msg;
}ThreadData;


void * hello(void *arg){
	ThreadData *td=(ThreadData *)arg;
	printf("%s %d \n",td->msg,td->hid);
	free(arg);
	pthread_exit(NULL); //va a esperar a que todos los hilos terminen, termina el hilo prinicpal
}

int main(){
	//pthread_create();
	pthread_t newThread;
	
	for(int i=0;i<10;i++){
		ThreadData * td = (ThreadData *)calloc(1, sizeof(ThreadData));
		td->hid=i;
		td->msg="hello world desde el hilo";
		pthread_create(&newThread,NULL,hello,(void *)&td[i]); //(void *) le digo que es un apuntador a cualquier cosa
	}
	pthread_exit(NULL); //va a esperar a que todos los hilos terminen, termina el hilo prinicpal
	
	
	return 0;
}