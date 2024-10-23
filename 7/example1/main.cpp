#include <iostream>

#include "sum.h"
#include "sum.h"

// 1. preprocessing (-E)
// 2. compilation (-S)
// 3. assembling (-c)
// 4. linking

// g++ -std=c++20 main.cpp sum.cpp
// 1. preprocessing + compilation + assembling - main.cpp - main.o
// 2. preprocessing + compilation + assembling - sum.cpp - sum.o
// 3. linking

int main() {
    std::cout << Sum(1, 100500) << std::endl;
    return 0;
}
