#include <iostream>
#include <fstream>
#include "../tools.h"

using namespace std;

int *bruteforce(int array[], size_t count, int target) {
    for (int i = 0; i < count; i++) {
        if (array[i] == target) {
            return array + i * sizeof(int);
        }
    }
    return nullptr;
}

int main() {
    const int sizeData = 10;
    std::ofstream out("bruteforce.csv");
    out << "size";
    for (int i = 0; i < sizeData; i++) {
        out << ";time" << i + 1;
    }
    out << "\n";
    for (unsigned size = 1000; size <= 150000; size+=1000) {
        out << to_string(size);
        for(int j=0; j<sizeData; j++){     //in order to determine median value
            out << tools::runTest(bruteforce, size, 1000, false);
        }
        out << endl;
        cout << size << endl;
    }
    return 0;
}
