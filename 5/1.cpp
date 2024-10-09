#include <iostream>

int Sum(int a, int b) {
    return a + b;
}

// void -> что делает -> Print
// non-void -> что возвращает -> GetSumOfThreeNumbers
// bool -> что проверяет -> IsEqual

void PrintArr(const int* arr, const size_t size) {
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i];
    }
    std::cout << std::endl;
}

void Increment(int& value) {
    ++value;
}

// dangling pointer
int* GetPointer() {
    int a = 0;
    return &a;
}

// dangling reference
int& GetReference() {
    int a = 0;
    return a;
}

int* GetDynamicPointer() {
    int* a = new int;
    return a;
}

int main() {
    // std::cin >> a >> b;
    // int ans = Sum(a, b);
    // std::cout << ans << std::endl;

    int arr[4] = {1, 2, 3, 4};
    PrintArr(arr, 4);

    int a = 0;
    int& a_ref = a;
    std::cout << a << std::endl;
    Increment(a);
    std::cout << a << std::endl;

    int* p = GetDynamicPointer();
    delete p;

    // указатель на константу
    const int* pointer1 = new int;  // const value, non-const pointer
    ++pointer1;
    *pointer1 = 10;
    delete pointer1;

    // константный указатель
    int* const pointer2 = new int;  // const pointer, non-const value
    ++pointer2;
    *pointer2 = 10;
    delete pointer2;

    int value = 0;
    const int& value_ref_1 = value;  // const reference
    // int& const value_ref_2 = value;

    return 0;
}
