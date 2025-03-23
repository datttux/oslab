#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <pthread.h>
#include <unistd.h> 
#define MAX_PORTS 3 
sem_t available_ports; 
void* open_port(void* id) {
    int thread_id = *(int*)id;
    printf("Thread %d: Attempting to open a port...\n", thread_id);
    sem_wait(&available_ports);
    printf("Thread %d: Port opened.\n", thread_id);
    sleep(2);
    printf("Thread %d: Closing port.\n", thread_id);
    sem_post(&available_ports);
    return NULL;
}
int main() {
    pthread_t threads[5]; 
    int thread_ids[5];
    sem_init(&available_ports, 0, MAX_PORTS);
    for (int i = 0; i< 5; i++) {
        thread_ids[i] = i + 1;
        pthread_create(&threads[i], NULL, open_port, &thread_ids[i]);
    }
    for (int i = 0; i< 5; i++) {
        pthread_join(threads[i], NULL);
    }
    sem_destroy(&available_ports);
    return 0;
}