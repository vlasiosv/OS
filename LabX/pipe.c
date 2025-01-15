#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
    int pipefd[2];       // Pipe file descriptors: pipefd[0] for reading, pipefd[1] for writing
    pipe(pipefd);        // Create a pipe
    pid_t pid = fork();  // Create a child process

    if (pid == 0) { // Child process
        close(pipefd[1]); // Close the write end of the pipe
        char buffer[128]; // Buffer to store the received message
        read(pipefd[0], buffer, sizeof(buffer)); // Read from the pipe
        printf("Child received: %s\n", buffer);
    } else { // Parent process
        close(pipefd[0]); // Close the read end of the pipe
    }

    return 0;
}
