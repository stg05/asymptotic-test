//
// Created by stg05 on 17.02.2024.
//

#include <iostream>
#include <chrono>
#include <random>
#include <fstream>
#include <algorithm>

using namespace std;

struct response {
    int *var1;
    int *var2;
};

response searchsum(int array[], size_t count, int target) {
    response rsp{nullptr, nullptr};
    size_t left = 0, right = count - 1;
    while (true) {
        if (array[left] + array[right] == target) {
            rsp.var1 = array + sizeof(int) * left;
            rsp.var2 = array + sizeof(int) * right;
            return rsp;
        }
        if (left == right) {
            return rsp;
        }
        if (array[left] + array[right] > target) {
            right -= 1;
        }
        if (array[left] + array[right] < target) {
            left += 1;
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
    for (int i = 0; i < 3e3; i++) {
        searchsum(workingArray, count, 200);
    }

    auto end = std::chrono::steady_clock::now();
    auto span = chrono::duration_cast<chrono::milliseconds>(end - begin).count();
    return ";" + to_string(span);
}

int main() {
    std::ofstream out("sumtwo-sorted.csv");
    out << "size;time1;time2;time3;time4;time5\n";
    for (unsigned size = 1000; size <= 10000; size+=100) {
        out << to_string(size);
        for (int j = 0; j < 5; j++) {     //in order to determine median value
            out << runTest(size);
        }
        out << endl;
    }
    return 0;
}
