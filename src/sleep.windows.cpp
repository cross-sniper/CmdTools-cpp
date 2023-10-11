#include <iostream>
#include <windows.h>  // Include the Windows API header

int to_int(const char* str) {
    return std::stoi(str);
}

int main(int argc, char* argv[]) {
    int num;

    if (argc <= 1) {
        num = 5; // Default sleep duration in seconds
    } else if (argc == 2) {
        num = to_int(argv[argc - 1]);
    } else {
        std::cerr << "Usage: " << argv[0] << " [seconds]" << std::endl;
        return 1;
    }

    int milliseconds = num * 1000; // Convert seconds to milliseconds

    // Use the Sleep function to pause the program's execution
    Sleep(milliseconds);

    return 0;
}
