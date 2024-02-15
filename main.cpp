#include <iostream>
#include <chrono>

using namespace std;

void func() {

};

int main() {
    auto begin = chrono::steady_clock::now();
    for (unsigned cnt = 100000; cnt != 0; cnt--) {
        func();
    }
    auto end = std::chrono::steady_clock::now();
    auto span = chrono::duration_cast<chrono::milliseconds>(end - begin);

    std::cout << std::endl << span.count() << std::endl;
    return 0;
}
