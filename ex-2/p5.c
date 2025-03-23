#include <stdio.h>
#include <sys/stat.h>
int main() {
	struct stat fileStat;
	if (stat("test.txt", &fileStat) < 0) {
		perror("Failed to get file stats");
		return 1;
	}
	printf("File size: %ld bytes\n", fileStat.st_size);
	printf("Permissions: %o\n", fileStat.st_mode & 0777);
	printf("Last accessed: %ld\n", fileStat.st_atime);
	return 0;
}

