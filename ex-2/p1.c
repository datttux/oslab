#include <stdio.h>
#include <unistd.h>
int main() {
	pid_t pid = fork();
	if (pid == 0) {
		printf("Child process ID: %d\n", getpid());
	} 
	else if (pid > 0) {
		printf("Parent process ID: %d\n", getpid());
	} 
	else {
		perror("Fork failed");
	}
	return 0;
}

