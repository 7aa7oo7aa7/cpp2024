#include <iostream>

int main() {
    int value = 1;
    int* p = &value;

    std::cout << p << std::endl;

    std::cout << *p << std::endl;

    value = 2;
    std::cout << *p << std::endl;

    *p = 3;
    std::cout << *p << std::endl;
    std::cout << value << std::endl;

    std::cout << p << std::endl;
    p = p + 1;  // 4 bytes = sizeof(int)
    std::cout << p << std::endl;
    // std::cout << *p << std::endl;  // UB

    int* p_null = nullptr;
    if (p_null == nullptr) {
        p_null = &value;
    }

    void* p_void = reinterpret_cast<void*>(p);
    int* p1 = reinterpret_cast<int*>(p_void);

    int arr[3];  // 3 * sizeof(int)

    // arr[i] -> *(arr + i)

    std::cout << arr << std::endl;

    arr[1] = -12345;
    std::cout << arr[1] << std::endl;
    std::cout << *(arr + 1) << std::endl;

    arr[0] = -10;
    std::cout << *arr << std::endl;

    // 1. only static length
    // 2. much memory
    // int n = 0;
    // std::cin >> n;
    // int arr_n[n];

    int* a = new int;
    *a = 5;
    std::cout << a << std::endl;
    std::cout << *a << std::endl;
    delete a;

    // *a = 1;  // UB
    // std::cout << a << std::endl;
    // std::cout << *a << std::endl;

    // delete a;  // RE

    a = new int;
    *a = 1;
    std::cout << a << std::endl;
    std::cout << *a << std::endl;
    delete a;

    a = &value;

    // new double;  // leak

    int* b = new int(3);
    std::cout << b << std::endl;
    std::cout << *b << std::endl;
    delete b;

    int* dyn_arr = new int[10];
    for (int i = 0; i < 10; ++i) {
        dyn_arr[i] = i + 2;
    }
    for (int i = 0; i < 10; ++i) {
        std::cout << dyn_arr[i] << " ";
    }
    std::cout << std::endl;
    // delete dyn_arr;  // memory leak
    delete[] dyn_arr;

    int n = 0;
    std::cin >> n;
    int* dyn_arr_n = new int[n];
    for (int i = 0; i < n; ++i) {
        dyn_arr_n[i] = i + 2;
    }
    for (int i = 0; i < n; ++i) {
        std::cout << dyn_arr_n[i] << " ";
    }
    std::cout << std::endl;
    delete[] dyn_arr_n;

    // int* arr = new int[2];
    // int arr[2];

    return 0;
}
