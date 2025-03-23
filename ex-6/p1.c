#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void* print_message(void* thread_id) {
    long tid = (long) thread_id;
    printf("Thread %ld is running\n", tid);
    sleep(2); 
    printf("Thread %ld is done\n", tid);
    return NULL;
}

int main() {
    pthread_t threads[5]; 
    int num_threads = 5;

    for (long i = 0; i < num_threads; i++) {
        int result = pthread_create(&threads[i], NULL, print_message, (void*)i);
        if (result != 0) {
            perror("Thread creation failed");
            return -1;
        }
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("All threads have finished execution.\n");
    return 0;
}