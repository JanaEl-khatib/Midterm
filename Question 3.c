// A program that the child prints hello and the parent prints goodbye
// Child first then the parent

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();
    if (pid < 0) {
        // Fork Failed
        perror("fork");
        exit(1);
    }
    if (pid == 0) { // Child Process
        printf("hello\n");
    } else { // Parent process
        // Without useing wait(), use sleep to allow the child process to run first.
        sleep(1);
        printf("goodbye\n");
    }
    return 0;
}