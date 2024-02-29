//
// Created by stg05 on 17.02.2024.
//

#include <iostream>
#include <fstream>
#include "../tools.h"

using namespace std;

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

int main() {
    const int sizeData = 25;
    std::ofstream out("sumtwo-sorted.csv");
    out << "size";
    for (int i = 0; i < sizeData; i++) {
        out << ";time" << i + 1;
    }
    out << "\n";
    for (unsigned size = 10'000; size <= 1'000'000; size+=10'000) {
        out << to_string(size);
        for (int j = 0; j < sizeData; j++) {     //in order to determine median value
            out << tools::runTest(searchsum, size, 1, true);
        }
        out << endl;
        cout<<size<<endl;
    }
    return 0;
}