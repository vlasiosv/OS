#include <stdio.h>
#include <unistd.h>

int main() {
    FILE *file = fopen("pids.txt", "a");
    pid_t pid = fork();

    if (file == NULL) {
        perror("Failed to open file");
        return 1;
    }

    if (pid == 0) { // Child process
        fprintf(file, "Child PID: %d\n", getpid());
    } else { // Parent process
        fprintf(file, "Parent PID: %d\n", getpid());
    }

    fclose(file);
    return 0;
}
