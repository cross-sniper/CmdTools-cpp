#include "../include/print.cpp"
#include "../include/read_file.cpp"
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm> // for std::sort

using namespace std;

void sort(vector<int>& vec) {
    // Sort the vector using std::sort
    std::sort(vec.begin(), vec.end());
    print("Sorted vector:");
    for (int num : vec) {
        cout << num << ' ';
    }
    cout << endl;
}

int main(int argc, char* argv[]) {
    for (int i = 1; i < argc; i++) {
        vector<int> Num;

        // Read the file and convert its contents to a vector of integers
        string fileContent = read_file(argv[i]);
        istringstream iss(fileContent);
        int num;
        while (iss >> num) {
            Num.push_back(num);
        }

        sort(Num);
    }
    return 0;
}
