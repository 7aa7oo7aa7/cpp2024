#include <iostream>

#include "sum.h"

// 1. preprocessing (-E)
// 2. compilation (-S)
// 3. assembling (-c)
// 4. linking

int main() {
    std::cout << Sum(1, 100500) << std::endl;  // Sum<int>
    std::cout << Sum(1.1, 100500.5) << std::endl;  // Sum<double>
    printf("%f\n", Sum(1.1, 100500.6));  // Sum<double>
    return 0;
}
