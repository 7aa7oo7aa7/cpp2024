#include <iostream>
#include <cstdint>

int main() {
    uint64_t n = 0;
    std::cin >> n;
    // i
    // n = i * j
    // n = sqrt(n) * sqrt(n)
    // i <= sqrt(n), j >= sqrt(n)
    // i <= sqrt(n)
    while (n % 2 == 0) {
        std::cout << 2 << " ";
        n /= 2;
    }
    for (uint64_t i = 3; i * i <= n; i += 2) {  // O(sqrt(n) / 2) = O(sqrt(n))
        while (n % i == 0) {
            std::cout << i << " ";
            n /= i;
        }
    }
    if (n != 1) {
        std::cout << n;
    }
    std::cout << std::endl;

    // 3 = 111
    // 3 = 1*(-2)^0 + 1*(-2)^1 + 1*(-2)^2 = 1 - 2 + 4 = 3

    int64_t m = 0;
    int64_t two = 1;
    while (n != 0) {
        // 3 = 11
        if (n % 2 == 0) {
            std::cout << 0;
        } else {
            std::cout << 1;
            m += two;
        }
        n /= -2;
        two *= -2;
    }
    if (n != m) {
        //
    }

    // 3 -> 1
    // -1 -> 1
    // 0 -> 1

    // 5 -> 1
    // -2 -> 0
    // 1 -> 1
    // 0
    // 1 - 0 * 2 + 1 * 4 = 5

    return 0;
}
