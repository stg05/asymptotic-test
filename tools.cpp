//
// Created by stg05 on 23.02.2024.
//

#include <ctime>
#include <random>
#include <algorithm>
#include <chrono>
#include "tools.h"

void tools::fill_array(int *target, size_t count) {
    unsigned seed = time(nullptr);
    default_random_engine rng(seed);
    uniform_int_distribution<int> dstr(0, 99);
    for (unsigned i = 0; i < count; i++) {
        target[i] = dstr(rng);
    }

};

string tools::runTest(int* (*target_f)(int[], size_t, int), size_t count) {
    int *workingArray = new int[count];
    tools::fill_array(workingArray, count);
    sort(workingArray, workingArray + count);
    auto begin = chrono::steady_clock::now();
    for (int i = 0; i < 5e5; i++) {
        target_f(workingArray, count, 100);
    }

    auto end = std::chrono::steady_clock::now();
    auto span = chrono::duration_cast<chrono::microseconds>(end - begin).count();
    delete[] workingArray;
    workingArray = nullptr;
    return ";" + to_string(span);
}