#include <iostream>
#include <fstream>
#include <string>
#include <cerrno>  // for handling error numbers
#include <cstring>  // for handling C-style strings

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <source_file> <destination_file>" << std::endl;
        return 1;
    }

    const char* sourceFilename = argv[1];
    const char* destinationFilename = argv[2];

    std::ifstream sourceFile(sourceFilename, std::ios::binary);
    if (!sourceFile) {
        std::cerr << "Error: Unable to open source file '" << sourceFilename << "': " << std::strerror(errno) << std::endl;
        return 1;
    }

    std::ofstream destinationFile(destinationFilename, std::ios::binary);
    if (!destinationFile) {
        std::cerr << "Error: Unable to create or open destination file '" << destinationFilename << "': " << std::strerror(errno) << std::endl;
        return 1;
    }

    destinationFile << sourceFile.rdbuf();
    
    sourceFile.close();
    destinationFile.close();

    return 0;
}
