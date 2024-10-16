#include <iostream>

// int Sum(int, int);
// double Sum(double, double);

template <typename T>
T Sum(T x, T y) {
    return x + y;
}

template <typename T, typename U>
void Print(T x, U y) {
    std::cout << x << y;
}

template <typename T>
void Swap(T& x, T& y) {
    T temp = x;
    x = y;
    y = temp;
}

// (T*, const T&)

template <class T>
void Copy(const T* src, T* dest, const size_t size) {  // T = int, T* = int*
    for (size_t i = 0; i < size; ++i) {
        dest[i] = src[i];
    }
}

template <class T>
void Fill(T* arr, const T& value, const size_t size) {
    for (size_t i = 0; i < size; ++i) {
        arr[i] = value;
    }
}

template <class T1, class T2 = int>
T2 Diff(T1 x, T1 y) {
    return x - y;
}

// template <class T1, class T2 = int, class T3, class T4>  // CE
template <class T1, class T2 = int, class T3 = double>
void F();

// F<int, double, int>
// F<int, double> = F<int, double, double>
// F<int> = F<int, int, double>
// F<int, ???, int> -> CE

template <int X>
void PrintTemplate() {
    std::cout << X << std::endl;
}

template <uint64_t X>
uint64_t Factorial() {
    // X! = 1 * 2 * ... * X = (X - 1)! * X
    return Factorial<X - 1>() * X;
}

template <>
uint64_t Factorial<0>() {
    return 1;
}

template <class T>
void Copy(const T* src_begin, const T* src_end, T* dest) {
    for (/* ???; ???; ???*/) {
        dest[i] = /* ??? */;
    }
}

int main() {
    std::cout << Sum(1, 1) << std::endl;
    // std::cout << Sum(1, 1.1) << std::endl;  // Sum<int> vs Sum<double>
    // Copy<int***>(nullptr, nullptr, 0);

    std::cout << Diff<double, double>(1.5, 2.2) << std::endl;  // Diff<double, double>
    std::cout << Diff<double>(1.5, 2.2) << std::endl;  // Diff<double, int>

    PrintTemplate<1>();
    PrintTemplate<3>();
    PrintTemplate<-228>();

    std::cout << Factorial<10>() << std::endl;

    size_t size = 10;
    int* arr = new int[size];
    int* dest = new int[size];
    Copy(arr, arr + size, dest);
    delete[] arr;
    delete[] dest;

    return 0;
}
