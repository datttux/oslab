#include <stdio.h>
#include <string.h>
void grep_pattern(char *file_name, char *pattern) {
    FILE *file;
    char line[256];
    int line_number = 0;
    file = fopen(file_name, "r");
    if (file == NULL) {
        perror("File opening failed");
        return;
    }
    while (fgets(line, sizeof(line), file)) {
        line_number++;
        if (strstr(line, pattern)) {
            printf("Line %d: %s", line_number, line);
        }
    }
    fclose(file);
}
int main() {
    char file_name[100], pattern[100];
    printf("Enter file name: ");
    scanf("%s", file_name);
    printf("Enter pattern to search: ");
    scanf("%s", pattern);
    grep_pattern(file_name, pattern);
    return 0; 
}
