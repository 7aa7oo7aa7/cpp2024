#include <iostream>
#include <cstring>

bool IsLine(int** arr, size_t n, size_t m, size_t line, const bool vertical) {
    for (size_t i = 0; i < (vertical ? n : m); ++i) {
        if ((vertical ? arr[i][line] : arr[line][i]) != 1) {
            return false;
        }
    }
    return true;
}

void GetNotebookType(int** arr, size_t n, size_t m) {
    for (size_t i = 0; i < n; ++i) {
        auto is_line = IsLine(arr, n, m, i, false);  // horizontal lines
        // code
    }
    for (size_t i = 0; i < m; ++i) {
        auto is_line = IsLine(arr, n, m, i, true);  // vertical lines
        // code
    }
}

template <class T>
T Sum(T a, T b) {
    return a + b;
}

// 1 2 3 5 5 5 7 8 10
// BinarySearch(5) = true
// BinarySearch(6) = false
// LowerBound(5) = 3
// UpperBound(5) = 6

template <class T>
bool operator>(T left, T right) {  // left > right
    return right < left;
}

template <class T>
bool operator==(T left, T right) {  // left == right
    return !(left < right) && !(right < left);
}

void Func(const char* str) {
    // for (size_t i = 0; i < strlen(str); ++i) {  // O(n)
    size_t len = strlen(str);
    for (size_t i = 0; i < len; ++i) {  // O(1)
        //
    }
}

template <class T>
struct Deque {
    T* arr;
    size_t size;
    size_t capacity;
};

template <class T>
void pop_front(Deque<T>& deque) {
    if (deque.size > 0) {
        T value = deque.arr[0];
        // delete first element
        std::cout << value;  // bad, move output outside
    } else {
        std::cout << "error";  // bad, move output outside
    }
}

template <class T>
pop_front(Deque<T>& deque) {
    //
}

template <class T>
struct PopFrontResult {
    T value;
    bool value_exists;
};

template <class T>
std::pair<T, bool>;

int main() {
    Sum<int>(1, 2);
    Sum(1.1, 2.2);

    Deque<int> deque1;
    Deque<int> deque2 = {new int[10], 0, 10};
    Deque<int> deque3 = {
        .arr = new int[10],
        .size = 0,
        .capacity = 10,
    };

    deque3.arr[0] = 0;

    delete[] deque2.arr;
    delete[] deque3.arr;

    // 1.
    // T front(), void pop_front()

    // 2.
    // T* pop_front() -> nullptr, &value

    // 3.
    // size() > 0 -> T pop_front()

    // 4.
    // PopFrontResult pop_front()

    // pop_front() -> value / no value -> std::cout << value / "error"

    return 0;
}
