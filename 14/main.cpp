#include <iostream>
#include <cstdint>

struct A {
    int a;
};

class B {
public:
    int b;
};

typedef struct {
    int a;
    int b;
    bool c;
} S;

struct X {
    char a1;
    char a2;
    char a3;
    char a4;
    char a5;
    int32_t b;
    int16_t c;
    int64_t d;
};

union U {
    char c;
    int a;
    double x;
};

union U2 {
    int64_t a;
    double b;
};

union UnionPointer {
    void* p0;
    int* p1;
    double* p2;
};

// std::variant<int, double, bool, char>

enum Season {  // enumeration - перечисление
    kWinter,
    kSpring,
    kSummer = 888,
    kAutumn = 999
};

enum class Season1 {  // enumeration - перечисление
    kWinter,
    kSpring,
    kSummer,
    kAutumn
};

// int GetAverageTemperature(const int& season) {
//     if (season == 0) {
//         return -100;
//     } else if (season == 9999) {
//         return 9999999;
//     } else {
//         return 0;
//     }
// }

int GetAverageTemperature(const Season& season) {
    if (season == Season::kWinter) {
        return -100;
    } else if (season == Season::kSummer) {
        return 9999999;
    } else {
        return 0;
    }
}

// template <int a>
// template <Season a>

int main() {

    auto season = Season::kSummer;
    Season season1;

    std::cout << static_cast<int>(season) << std::endl;

    U2 u;
    u.a = 1;  // 000000001
    u.b;  // 000000001

    std::cout << u.a << " " << u.b << std::endl;

    double d = 1.1;
    UnionPointer up;
    up.p2 = &d;
    std::cout << up.p0 << " " << up.p1 << " " << up.p2 << std::endl;

    struct {
        int a;
        int b;
    } s;

    s.a = 1;
    s.b = 2;

    std::cout << s.a << " " << s.b << std::endl;

    S s2;

    s2.a = 1;
    s2.b = 2;

    std::cout << s2.a << " " << s2.b << std::endl;

    std::cout << sizeof(X) << std::endl;

    return 0;
}
