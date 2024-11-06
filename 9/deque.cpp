#include "deque.h"

void Deque::Initialize(size_t initial_capacity) {
    capacity = initial_capacity;
    size = 0;
    arr = new int[capacity];
    begin = arr;
    end = arr;
}

int Deque::Front() const {
    return *begin;
}

int Deque::Back() const {
    return *end;
}

size_t Deque::Size() const {
    return size;
}

// 1 2 3 4 5
// PopFront()
// . 2 3 4 5
// . . 3 4 5
// . . . 4 5
// . . . . 5

void Deque::PushBack(const int value) {
    if (size == capacity) {
        Grow();
    }
    ++size;
    ++end;
    if (end == arr + size) {
        end = arr;
    }
    *end = value;
}

void Deque::Grow() {
    int* new_arr = new int[2 * capacity];
    if (begin <= end) {
        for (size_t i = 0; i <= end - begin; ++i) {
            new_arr[i] = begin[i];
        }
    } else {
        size_t i = 0;
        for (; i < arr + size - begin; ++i) {
            new_arr[i] = begin[i];
        }
        for (size_t j = 0; j <= end - arr; ++j) {
            new_arr[i++] = arr[j];
        }
    }
    delete[] arr;
    arr = new_arr;
    begin = arr;
    end = arr + size;
    capacity *= 2;
}

void Deque::Clear() {
    delete[] arr;
}
