#include <stdio.h>
#include <unistd.h>

int main() {
    for (int i = 0; i < 3; i++) {
        pid_t pid = fork();
        if (pid == 0) {
            printf(" PID: %d\n", getpid());
            break;
        }
    }
    return 0;
}
