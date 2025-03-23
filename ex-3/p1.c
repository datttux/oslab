#include <stdio.h>
#include <stdlib.h>
void copy_file(char *source, char *destination) {
    FILE *src, *dest;
    char ch;
    src = fopen(source, "r");
    if (src == NULL) {
        perror("Source file opening failed");
        return;
    }
    dest = fopen(destination, "w");
    if (dest == NULL) {
        perror("Destination file opening failed");
        fclose(src);
        return;
    }
    while ((ch = fgetc(src)) != EOF) {
        fputc(ch, dest);
    }
    printf("File copied successfully.\n");
    fclose(src);
    fclose(dest);
}
int main() {
    char source[100], destination[100];
    printf("Enter source file name: ");
    scanf("%s", source);
    printf("Enter destination file name: ");
    scanf("%s", destination);
    copy_file(source, destination);
    return 0;
}
