#include <iostream>
#include <chrono>
#include <random>
#include <fstream>

using namespace std;

int *bruteforce(int array[], size_t count, int target) {
    for (int i = 0; i < count; i++) {
        if (array[i] == target) {
            return array + i * sizeof(int);
        }
    }
    return nullptr;
}

void fill_array(int target[], size_t count) {
    unsigned seed = 30239;
    default_random_engine rng(seed);
    uniform_int_distribution<int> dstr(0, 9);
    for (unsigned i = 0; i < count; i++) {
        target[i] = dstr(rng);
    }
}

string runTest(size_t count) {
    int workingArray[count];
    fill_array(workingArray, count);
    auto begin = chrono::steady_clock::now();
    for (int i = 0; i < 1000; i++) {
        bruteforce(workingArray, count, 10);
    }

    auto end = std::chrono::steady_clock::now();
    auto span = chrono::duration_cast<chrono::milliseconds>(end - begin).count();
    return ";" + to_string(span) ;
}

int main() {
    std::ofstream out("bruteforce.csv");
    out << "size;time1;time2;time3;time4;time5\n";
    for (unsigned size = 1000; size <= 150000; size+=1000) {
        out << to_string(size);
        for(int j=0; j<5; j++){     //in order to determine median value
            out << runTest(size);
        }
        out << endl;
    }
    return 0;
}
