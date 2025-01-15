
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int main() {
    pid_t pid = fork();  // Create a child process

    if (pid == 0) { // Child process
        pause(); // Wait for a signal
        printf("Child received a signal and is exiting.\n");
    } else { // Parent process
        sleep(1); // Give the child process time to set up
        kill(pid, SIGKILL); // Send the signal to terminate the child process
        printf("Parent sent a signal to terminate the child.\n");
    }

    return 0;
}
