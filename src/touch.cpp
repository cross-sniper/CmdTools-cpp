#include <iostream>
#include <fstream>
#include <string>
#include <cerrno>  // for handling error numbers
#include <cstring>  // for handling C-style strings

int main(int argc, char* argv[]) {
    for(int i=1; i < argc;i++){
    	const char* destinationFilename = argv[i];
	    std::ofstream destinationFile(destinationFilename, std::ios::binary);
	    if (!destinationFile) {
	        std::cerr << "Error: Unable to create or open destination file '" << destinationFilename << "': " << std::strerror(errno) << std::endl;
	        return 1;
	    }
	    destinationFile << "";
	    
	    destinationFile.close();
    }
    return 0;
}
