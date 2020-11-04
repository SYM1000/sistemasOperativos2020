#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <semaphore.h>

unsigned saldo;
sem_t semSaldo;

void *addToSaldo(void *arg){
    //proteger la region critica 
    sem_wait(&semSaldo);

    unsigned valorInicial=saldo;
    unsigned saldoFinal = valorInicial + 500;
    saldo=saldoFinal;
    sem_post(&semSaldo);

//    printf("El saldo actual %d %d  \n ", valorInicial, saldoFinal);
    pthread_exit(NULL);
}

int main(){
    unsigned NUM_THREADS = 100;
    saldo=0;
    //semaforo
    sem_init(&semSaldo,0,1);
    pthread_t threads[NUM_THREADS];
    for(int i=0;i<NUM_THREADS;i++){
        pthread_create(&threads[i],NULL, addToSaldo,NULL);
    }
    for(int i =0;i<NUM_THREADS;i++){
        pthread_join(threads[i],NULL);
    }

    printf("el saldo final es %d \n", saldo );
    pthread_exit(NULL);

}