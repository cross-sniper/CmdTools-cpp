#include <iostream>
#include <chrono>
#include <thread>

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

    std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));

    return 0;
}
