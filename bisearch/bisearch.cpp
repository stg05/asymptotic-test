//
// Created by stg05 on 17.02.2024.
//

#include <iostream>
#include <chrono>
#include <random>
#include <fstream>
#include <algorithm>
#include "../tools.h"

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

int main() {
    const int sizeData = 100;
    std::ofstream out("bisearch.csv");
    out << "size";
    for (int i = 0; i < sizeData; i++) {
        out << ";time" << i + 1;
    }
    out << "\n";
    for (unsigned size = 1; size <= 1000000; size = size * 6 / 5 + 1) {
        out << to_string(size);
        for (int j = 0; j < sizeData; j++) {     //in order to determine median value
            out << tools::runTest(bisearch, size);
        }
        out << endl;
        cout << size << endl;
    }
    return 0;
}
