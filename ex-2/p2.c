#include <stdio.h>
#include <unistd.h>
int main() {

	printf("Executing `ls` command:\n");
	execl("/bin/ls", "ls", "-l", NULL);
	perror("Exec failed");
	return 0;
}

