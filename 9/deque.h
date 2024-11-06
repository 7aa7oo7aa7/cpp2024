#ifndef DEQUE_H
#define DEQUE_H

#include <iostream>

class Deque {
public:
    void Initialize(size_t initial_capacity = 8);

    int Front() const;
    int Back() const;
    size_t Size() const;

    void PushBack(const int value);

    void Clear();

private:
    int* arr;
    size_t size;  // number of elements
    size_t capacity;  // size of memory
    int* begin;
    int* end;

    void Grow();
};

#endif
