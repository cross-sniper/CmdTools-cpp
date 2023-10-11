/*

this was made based on 'cat', which is written in c

https://github.com/wertarbyte/coreutils/blob/master/src/cat.c
*/

#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char* argv[]) {
    if (argc == 1) {
        // If no arguments are provided, read from standard input
        std::string line;
        while (std::getline(std::cin, line)) {
            std::cout << line << std::endl;
        }
    } else {
        // Loop through the provided files and display their contents
        for (int i = 1; i < argc; ++i) {
            std::string filename = argv[i];
            std::ifstream file(filename);

            if (file.is_open()) {
                std::string line;
                while (std::getline(file, line)) {
                    std::cout << line << std::endl;
                }
                file.close();
            } else {
                std::cerr << "Error: Unable to open file '" << filename << "'" << std::endl << "does it even exists?" << std::endl;
            }
        }
    }

    return 0;
}
