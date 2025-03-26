// A program that creates a child process, then the 
// child closes standard output (STDOUT FILENO)

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    pid_t pid = fork();
    if (pid < 0) {
        // Fork Failed
        perror("fork");
        exit(1);
    }
    if (pid == 0) { // Child Process
        // Close the standard output
        close(STDOUT_FILENO);
        // Try to print after closing
        printf("Hello, I am trying to print!!\n");
    } else { // Parent process
        printf("This is the parent process.\n");
    }
    return 0;
}

// The child will not print out anything after closing the descriptor