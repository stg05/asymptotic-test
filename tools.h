//
// Created by stg05 on 23.02.2024.
//

#ifndef ASYMPTOTIC_TEST_TOOLS_H
#define ASYMPTOTIC_TEST_TOOLS_H

#include <cstddef>

using namespace std;

class tools {
public:
    static void fill_array(int target[], size_t count);
    static string runTest(int* (*target_f)(int[], size_t, int), size_t count);
};


#endif //ASYMPTOTIC_TEST_TOOLS_H
