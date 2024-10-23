#include "sum.h"

template <class T>
T Sum(T a, T b) {
    return a + b;
}

template int Sum(int, int);
template double Sum(double, double);
