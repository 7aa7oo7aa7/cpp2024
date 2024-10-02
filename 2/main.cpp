#include <iostream>
#include <cstdint>

int main() {
    1ULL;
    int a = 1UL;
    unsigned long long x = 1;
    long long b = 9999999999999999;
    std::cout << b << std::endl;

    // +, -, *
    // / - целочисленное деление
    // % - деление с остатком
    // &, |, ~, ^

    std::cout << (3 % (-2)) << std::endl;  // 3 = -2 * -1 + 1
    std::cout << ((-3) % 2) << std::endl;  // -3 = 2 * -1 - 1
    std::cout << ((-3) % (-2)) << std::endl;  // -3 = -2 * 1 - 1

    unsigned int a1 = 1;  // 0..001
    unsigned int a2 = 2;  // 0..010

    std::cout << (a1 & a2) << " " << (a1 | a2) << " " << (a1 ^ a2) << " " << (~a1) << std::endl;


    int a3 = 1;
    std::cout << (~a3) << std::endl;

    std::cout << (a1 & a2 << 2 | a3);

    // <<, >>
    unsigned long long a4 = 1;
    std::cout << (a4 << 32) << std::endl;

    unsigned int b1 = 3;
    unsigned int b2 = 4294967295;  // 2^32 - 1
    std::cout << b1 + b2 << std::endl;  // 2^32 - 1 + 1 + 2 = 0 + 2 = 2

    int b3 = 1;
    int b4 = 2147483647;  // 2^31 - 1
    // std::cout << b3 + b4 << std::endl;  // 2^31 - 1 + 1 - undefined behavior
    // 1 / 0;  // UB

    int64_t i64 = 0;
    uint16_t u16 = 0;

    char c = 'a';  // 1 byte number, [-128, 127]
    std::cout << c << std::endl;
    c = 98;
    std::cout << c << std::endl;
    c = -1;
    std::cout << c << std::endl;
    unsigned char cu = 97;  // 1 byte unsigned number, [0, 255]
    std::cout << cu << std::endl;

    int8_t cc;

    bool y1 = true;
    bool y2 = false;  // 1 byte

    // &&, ||, !

    sizeof(int);
    sizeof(a);
    sizeof(1);

    // std::string, std::vector, std::map - нельзя

    int a = 1;
    int b = 2;

    a = a + b;
    a = a - b;
    a = a * b;
    a = a / b;
    a = a % b;

    a += b;  // a = a + b
    a -= b;
    // *=, /=, %=
    // &=, |=, ^=, >>=, <<=

    // +, +=

    // +
    // копия a
    // +b
    // -> a

    a += 1;
    a -= 1;
    ++a;
    a++;
    --a;
    a--;

    return 0;
}
