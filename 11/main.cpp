#include <iostream>
#include <cstring>

template <class T, size_t N>
class Array {
public:
    T arr_[N];

    // Array(int value) {
    //     arr_[0] = value;
    // }

    // +,-,*,/,%, +=,-=,*=,/=,%=, [], <<,>>

    T& operator[](size_t index) {
        return arr_[index];
    }

    const T& operator[](size_t index) const {
        return arr_[index];
    }

    void Swap(Array<T, N>& other) {
        for (size_t i = 0; i < N; ++i) {
            std::swap(arr_[i], other.arr_[i]);
        }
    }
};

struct A {
    int a;
    int b;
};

class StringView {
public:
    StringView(const char* str) : str_(str), size_(std::strlen(str)) {}
    StringView(const char* str, const size_t size) : str_(str), size_(size) {}

    size_t Size() const {
        return size_;  // n_bytes
    }

    size_t Length() const {
        return size_;  // n_symbols
    }

    void RemovePrefix(size_t prefix_size) {
        if (prefix_size < size_) {
            str_ += prefix_size;  // *abcde, 3 -> abc*de -> *de
            size_ -= prefix_size;
        } else {
            str_ = nullptr;
            size_ = 0;
        }
    }

private:
    const char* str_;
    size_t size_;
};

class Rational {
public:
    Rational(const int numerator = 0, const int denominator = 1)
        : numerator_(numerator), denominator_(denominator)
    {
        Reduce();
    }

    // Rational(1, 2)

    Rational operator+(const Rational& other) {
        Rational copy = *this;
        return copy += other;
        // a/b + c/d = (ad + bc) / bd
    }

    // Rational + ???
    // ??? + ???

    friend Rational operator+(const Rational& left, const Rational& right);

    Rational& operator+=(const Rational& other) {
        // a/b + c/d = (ad + bc) / bd
        numerator_ = numerator_ * other.denominator_ + denominator_ * other.numerator_;
        denominator_ = denominator_ * other.denominator_;
        return *this;
    }

    // operator+ : Rational(new_numerator, new_denominator)
    // operator+= : numerator = new_numerator, denominator = new_denominator

    static int GCD(int a, int b) {
        return 1;  // Euclede algorithm
    }

private:
    int numerator_;
    int denominator_;

    void Reduce() {
        auto gcd = GCD(numerator_, denominator_);
        numerator_ /= gcd;
        denominator_ /= gcd;
    }
};

Rational operator+(const Rational& left, const Rational& right) {
    Rational copy = left;
    return copy += right;
    // a/b + c/d = (ad + bc) / bd
}

int main() {
    A a{1, 0};
    int arr_c[4]{1, 2, 3, 0};
    auto arr = Array<int, 4>{1, 2, 3};
    // Array<int, 4>(1);

    // arr.arr_[1];
    arr[1];

    const auto arr_const = Array<int, 4>{1, 2, 3};
    arr_const[1];

    const char* c_str = "aaaaa";
    StringView str(c_str);

    Rational::GCD(1, 2);

    Rational rational1(1, 2);
    Rational rational2(5, 6);
    auto rational3 = rational1 + rational2;
    auto rational4 = rational3 + 5;  // rational3 + Rational(5)
    auto rational5 = 5 + rational4;  // Rational(5) + rational4

    return 0;
}
