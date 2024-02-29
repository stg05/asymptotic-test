//
// Created by stg05 on 17.02.2024.
//

#include <iostream>
#include <fstream>
#include "../tools.h"

using namespace std;



response searchsum(int array[], size_t count, int target) {
    response rsp{nullptr, nullptr};
    for(size_t i = 0; i<count; i++){
        for(size_t j = 0; j < count; j++){
            if(array[i]+array[j] == target){
                rsp.var1 = array + sizeof(int) * i;
                rsp.var2 = array + sizeof(int) * j;
                return rsp;
            }
        }
    }
    return rsp;
}

int main() {
    const int sizeData = 10;
    std::ofstream out("sumtwo.csv");
    out << "size";
    for (int i = 0; i < sizeData; i++) {
        out << ";time" << i + 1;
    }
    out << "\n";
    for (unsigned size = 1000; size <= 100000; size=size*50/49) {
        out << to_string(size);
        for (int j = 0; j < sizeData; j++) {     //in order to determine median value
            out << tools::runTest(searchsum, size, 1, false);
        }
        out << endl;
        cout<<size<<endl;
    }
    return 0;
}
