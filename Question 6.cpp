// Closh Program

#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <vector>

int main() {
    while (true) {
        string program;
        int count;
        char mode;

        // Get Program Name:
        cout << "closh>";
        cin >> program;
        // Get the number of copies
        cout << "count>";
        cin >> count;
        // Check if the number if valid
        if (count < 1 || count > 9) {
            cerr << "Error: count must be 1 and 9.\n";
            continue;
        }
        // Get execution mode
        cout << "[p]arallel or [s]equential";
        cin >> mode;
        // Store child process IDs
        vector<pid_t> pids;

        for(int i = 0; i < count; i++) {
            pid_t pid = fork(); // create a new process
            if (pid == -1) {
                cerr << "Error: Failed to fork\n";
                return 1;
            }
            if (pid == 0) { // Child Process
                char *args[] = {const_cast<char *> (program.c_str()), NULL}; // Convert string to C-String
                execvp(args[0], args); // Replace process with given program
                // If execvp fails
                cerr << "Error: Failed to execute" << program << endl;
                exit(1);
            } else { // Parent Process
                pids.push_back(pid);
                // If mode is Sequential
                if (mode == 's') {
                    waitpid(pid, NULL, 0) // Waiting
                }
            }
        }
        // If parallel mode, wait for all processes at the end
        if (mode == 'p') {
            for (pid_t : pids) {
                waitpid(pid, NULL, 0);
            }
        }
    }
    return 0;
}