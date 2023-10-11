#include <fstream>
#include <string>
#include <iostream>

std::string read_file(const std::string& filename) {
    std::ifstream file(filename);
    std::string content;

    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            content += line + "\n";  // Append each line with a newline character
        }
        file.close();
    } else {
        std::cerr << "Error: Unable to open file '" << filename << "'" << std::endl << "Does it even exist?" << std::endl;
    }

    return content;
}
