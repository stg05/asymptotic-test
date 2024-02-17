//
// Created by stg05 on 17.02.2024.
//

#include <iostream>
#include <chrono>
#include <random>
#include <fstream>
#include <algorithm>

using namespace std;

int *bisearch(int array[], size_t count, int target) {
    size_t start = 0, end = count - 1;

    while (true) {
        size_t current = (start + end) / 2u;
        if (start == end) {
            if (array[start] != target) {
                return nullptr;
            } else {
                return array + sizeof(int) * start;
            }
        } else {
            if (array[current] > target) {
                end = current - 1;
            } else if (array[current] < target) {
                start = current + 1;
            } else {
                return array + sizeof(int) * current;
            }
        }


    }
}

void fill_array(int target[], size_t count) {
    unsigned seed = 30239;
    default_random_engine rng(seed);
    uniform_int_distribution<int> dstr(0, 99);
    for (unsigned i = 0; i < count; i++) {
        target[i] = dstr(rng);
    }
}

string runTest(size_t count) {
    int workingArray[count];
    fill_array(workingArray, count);
    sort(workingArray, workingArray + count);
    auto begin = chrono::steady_clock::now();
    for (int i = 0; i < 2e6; i++) {
        bisearch(workingArray, count, 100);
    }

    auto end = std::chrono::steady_clock::now();
    auto span = chrono::duration_cast<chrono::milliseconds>(end - begin).count();
    return ";" + to_string(span);
}

int main() {
    std::ofstream out("bisearch.csv");
    out << "size;time1;time2;time3;time4;time5\n";
    for (unsigned size = 1; size <= 520000; size = size * 6 / 5 + 1) {
        out << to_string(size);
        for (int j = 0; j < 5; j++) {     //in order to determine median value
            out << runTest(size);
        }
        out << endl;
    }
    return 0;
}
