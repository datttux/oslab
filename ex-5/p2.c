#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h> 
#define MAX_PORTS 3 
pthread_mutex_t mutex; 
pthread_cond_t cond; 
int available_ports = MAX_PORTS; 
void* open_port(void* id) {
    int thread_id = *(int*)id;
    printf("Thread %d: Attempting to open a port...\n", thread_id);
    pthread_mutex_lock(&mutex); 
    while (available_ports == 0) {
        pthread_cond_wait(&cond, &mutex);
    }
    available_ports--;
    printf("Thread %d: Port opened. Remaining ports: %d\n", thread_id,available_ports);
    pthread_mutex_unlock(&mutex); 
    sleep(2);
    pthread_mutex_lock(&mutex); 
    available_ports++; 
    printf("Thread %d: Closing port. Remaining ports: %d\n", thread_id,
    available_ports);
    pthread_cond_signal(&cond); 
    pthread_mutex_unlock(&mutex); 
    return NULL;
}
int main() {
    pthread_t threads[5]; 
    int thread_ids[5];
    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&cond, NULL);
    for (int i = 0; i< 5; i++) {
        thread_ids[i] = i + 1;
        pthread_create(&threads[i], NULL, open_port, &thread_ids[i]);
    }
    for (int i = 0; i< 5; i++) {
        pthread_join(threads[i], NULL);
    }
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);
    return 0;
}