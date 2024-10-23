#include <iostream>

#include "sum.h"

// 1. preprocessing (-E)
// 2. compilation (-S)
// 3. assembling (-c)
// 4. linking

int main() {
    std::cout << Sum(1, 100500) << std::endl;  // Sum<int>
    std::cout << Sum(1.1, 100499.9) << std::endl;  // Sum<double>
    // std::cout << Sum(true, false) << std::endl;  // Sum<bool>
    return 0;
}
