#include <iostream>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <cstdlib>
#include <csignal>

pid_t childPid = 0;

void handleTimeout(int signo) {
    // Handle the timeout signal
    if (childPid > 0) {
        // If the child process is still running, terminate it and its child processes
        kill(-childPid, SIGTERM);
    }
    std::cerr << "Timeout reached. Command terminated." << std::endl;
    exit(1);
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cerr << "Usage: " << argv[0] << " <timeout_seconds> <command...>" << std::endl;
        return 1;
    }

    int timeoutSeconds = std::stoi(argv[1]);
    std::string commandToExecute;

    // Construct the command to execute by concatenating argv[2] onwards
    for (int i = 2; i < argc; ++i) {
        commandToExecute += argv[i];
        if (i < argc - 1) {
            commandToExecute += " ";
        }
    }

    childPid = fork();
    if (childPid < 0) {
        std::cerr << "Fork failed." << std::endl;
        return 1;
    }

    if (childPid == 0) {
        // Child process
        // Create a new session for the command and start it
        setsid();
        execl("/bin/sh", "sh", "-c", commandToExecute.c_str(), NULL);
        exit(0);
    } else {
        // Parent process
        // Set up the signal handler for timeout
        signal(SIGALRM, handleTimeout);

        // Schedule the alarm for timeout
        alarm(timeoutSeconds);

        int status;
        if (waitpid(childPid, &status, 0) == -1) {
            std::cerr << "Waitpid failed." << std::endl;
            return 1;
        }

        // Cancel the alarm
        alarm(0);

        if (WIFEXITED(status)) {
            std::cout << "Command completed successfully." << std::endl;
            return WEXITSTATUS(status);
        }
    }

    return 0;
}
