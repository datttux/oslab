#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define BUFFER_SIZE 5       
#define PRODUCER_COUNT 3    
#define CONSUMER_COUNT 3    

int buffer[BUFFER_SIZE];    
int in = 0, out = 0;        

sem_t empty, full, mutex;   

void* producer(void* arg) {
    for (int i = 0; i < 5; i++) {
        int item = rand() % 100; 

        sem_wait(&empty);  
        sem_wait(&mutex);  

        buffer[in] = item; 
        printf("Producer %ld produced item: %d at index %d\n", (long)arg, item, in);
        in = (in + 1) % BUFFER_SIZE; 

        sem_post(&mutex);  
        sem_post(&full);   

        sleep(1); 
    }
    return NULL;
}

void* consumer(void* arg) {
    for (int i = 0; i < 5; i++) {
        sem_wait(&full);   
        sem_wait(&mutex);  

        int item = buffer[out]; 
        printf("Consumer %ld consumed item: %d from index %d\n", (long)arg, item, out);
        out = (out + 1) % BUFFER_SIZE; 

        sem_post(&mutex);  
        sem_post(&empty);  
        sleep(2); 
    }
    return NULL;
}

int main() {
    pthread_t producers[PRODUCER_COUNT], consumers[CONSUMER_COUNT];

    sem_init(&empty, 0, BUFFER_SIZE); 
    sem_init(&full, 0, 0);            
    sem_init(&mutex, 0, 1);           

    for (long i = 0; i < PRODUCER_COUNT; i++) {
        pthread_create(&producers[i], NULL, producer, (void*)i);
    }

    for (long i = 0; i < CONSUMER_COUNT; i++) {
        pthread_create(&consumers[i], NULL, consumer, (void*)i);
    }

    for (int i = 0; i < PRODUCER_COUNT; i++) {
        pthread_join(producers[i], NULL);
    }

    for (int i = 0; i < CONSUMER_COUNT; i++) {
        pthread_join(consumers[i], NULL);
    }

    sem_destroy(&empty);
    sem_destroy(&full);
    sem_destroy(&mutex);

    return 0;
}
