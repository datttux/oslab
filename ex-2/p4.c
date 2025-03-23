#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
int main() {
	int fd = open("test.txt", O_CREAT | O_RDWR, 0644);
	if (fd < 0) {
		perror("Failed to open file");
		return 1;
	}
	printf("File opened with descriptor: %d\n", fd);
	close(fd);
	printf("File descriptor closed.\n");
	return 0;
}

