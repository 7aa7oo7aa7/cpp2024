#include "sum.h"

int SumInner(int x, int y) {
    return x + y;
}

int Sum(int x, int y) {
    return SumInner(x, y);
}
