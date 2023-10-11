#include <iostream>
#include <windows.h>
#include <tchar.h>

HANDLE childProcess = nullptr;
DWORD childProcessId = 0;

void handleTimeout(int signo) {
    // Handle the timeout signal
    if (childProcess != nullptr) {
        // If the child process is still running, terminate it and its child processes
        GenerateConsoleCtrlEvent(CTRL_BREAK_EVENT, childProcessId);
        WaitForSingleObject(childProcess, INFINITE);
        CloseHandle(childProcess);
    }
    std::cerr << "Timeout reached. Command terminated." << std::endl;
    exit(1);
}

int _tmain(int argc, _TCHAR* argv[]) {
    if (argc < 3) {
        std::cerr << "Usage: " << argv[0] << " <timeout_seconds> <command...>" << std::endl;
        return 1;
    }

    int timeoutSeconds = _tstoi(argv[1]);
    _TCHAR commandToExecute[MAX_PATH];

    // Construct the command to execute by concatenating argv[2] onwards
    _tcscpy(commandToExecute, argv[2]);
    for (int i = 3; i < argc; ++i) {
        _tcscat(commandToExecute, _T(" "));
        _tcscat(commandToExecute, argv[i]);
    }

    STARTUPINFO si;
    PROCESS_INFORMATION pi;

    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));

    if (!CreateProcess(NULL, commandToExecute, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi)) {
        std::cerr << "Failed to create the process." << std::endl;
        return 1;
    }

    childProcess = pi.hProcess;
    childProcessId = pi.dwProcessId;

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

    return 0;
}
