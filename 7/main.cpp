#include <iostream>

int f() {
    return 1;
}

auto g() {
    return true;
}

auto f_void() {
    std::cout << 1 << std::endl;
}

int main() {

    double x = 0;
    auto y = x;
    auto& x_ref = x;
    auto* x_ptr = &x;

    // auto a = 0;
    int a1 = 0;
    auto a2 = int(0);

    auto f_value = f();
    auto g_value = g();

    f_void();

    return 0;
}
