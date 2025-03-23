#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
int main() {
	pid_t pid = fork();
	if (pid == 0) {
		printf("Child process exiting.\n");
	exit(0);
	}
	else if (pid > 0) {
		int status;
		wait(&status);
		printf("Parent process: Child exited with status %d.\n",
		WEXITSTATUS(status));
	} 
	else {
		perror("Fork failed");
	}
	return 0;
}

