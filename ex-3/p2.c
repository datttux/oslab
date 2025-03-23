#include <stdio.h>
#include <dirent.h>
void list_files(char *path) {
    struct dirent *entry;
    DIR *dir = opendir(path);
    if (dir == NULL) {
        perror("Directory opening failed");
        return;
    }
    printf("Files in %s:\n", path);
    while ((entry = readdir(dir)) != NULL) {
        printf("%s\n", entry->d_name);
    }
    closedir(dir);
}
int main() {
    char path[100];
    printf("Enter directory path: ");
    scanf("%s", path); 
    list_files(path); 
    return 0;
}
