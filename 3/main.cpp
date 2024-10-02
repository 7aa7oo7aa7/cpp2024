#include <iostream>

int main() {

    int a = 0;
    int b = 0;
    int c = 0;

    // if a == 1 -> b = 1, else -> b = 3
    (a == 1) ? b = 1 : b = 3;
    b = (a == 1 ? 1 : 3);

    // if a == 1 -> b = 1, else -> c = 1
    (a == 1) ? b = 1 : c = 1;
    (a == 1 ? b : c) = 1;

    bool x = true;
    if (x == true);
    if (x == false);
    if (x);  // if (x == true)
    if (!x);  // if (x == false)

    switch (a) {
        case 0:  // if (a == 0)
            std::cout << a;
            std::cout << 0;
            break;
        case 2:  // if (a == 2)
            std::cout << 1;
            [[fallthrough]];
        default:  // else
            std::cout << 2;
    }

    return 0;
}
