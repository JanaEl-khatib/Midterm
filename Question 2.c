//A program that opens a file and then calls fork()

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h> // How to Call a file in c

int main() {
    int fd = open("output.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (fd < 0) {
        perror("open");
        exit(1);
    }

    pid_t pid = fork();
    if (pid < 0){
        perror("fork");
        exit(1);
    }
    if (pid == 0) { // Child Process
        write(fd, "Child writing...\n", 17);
    } else { // Parent process
        write(fd, "Parent writing..\n", 18);
    }

    close(fd);
    return 0;
}

// Yes they both can access the file descriptor returned by open()
// The parent will finish first and then the child will start writing.
//  the way the code is structured it has the child waiting for the parent to finish before it does anything