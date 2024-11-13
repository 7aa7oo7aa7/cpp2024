#include <iostream>
#include <cassert>

class Time {
public:
    Time() {
        SetHours(0);
        SetMinutes(0);
        SetSeconds(0);
        SetTimezone(0);
    }

    explicit Time(const int timezone) {
        SetHours(0);
        SetMinutes(0);
        SetSeconds(0);
        SetTimezone(timezone);
    }

    // Time(const int minutes)  // CE

    Time(const int hours, const int minutes, const int seconds);
    Time(const int hours, const int minutes, const int seconds, const int timezone);

    void SetHours(const int value) {
        assert(0 <= value && value < 24);
        hours_ = value;
    }

    void SetMinutes(const int value) {
        assert(0 <= value && value < 60);
        minutes_ = value;
    }

    void SetSeconds(const int value) {
        // if (0 <= value && value < 60) {
            // seconds_ = value;
        // }
        assert(0 <= value && value < 60);
        seconds_ = value;
    }

    int GetHours(bool use_timezone = false) const;

    int GetMinutes() const {
        return minutes_;
    }

    int GetSeconds() const {
        return seconds_;
    }

    void SetTimezone(const int value) {
        timezone_ = value;
    }

private:
    int hours_;
    int minutes_;
    int seconds_ = 0;
    int timezone_ = 0;

    int GetHoursWithTimezone() const {
        return hours_ + timezone_;
    }
};

Time::Time(const int hours, const int minutes, const int seconds)
    : hours_(hours), minutes_(minutes), seconds_(seconds), timezone_(0)
{
    // SetHours(hours);
    // SetMinutes(minutes);
    // SetSeconds(seconds);
    // SetTimezone(0);
}

Time::Time(const int hours, const int minutes, const int seconds, const int timezone) {
    SetHours(hours);
    SetMinutes(minutes);
    SetSeconds(seconds);
    SetTimezone(timezone);
}

class Deque {
public:
    Deque() {
        size_ = 0;
        capacity_ = 8;
        arr_[12];  // RE
        arr_ = new int[capacity_];
    }

    Deque() : size_(0), capacity_(8), arr_(new int[capacity_]) {
    }

private:
    size_t size_;
    size_t capacity_;
    int* arr_;
};

int Time::GetHours(bool use_timezone) const {
    if (use_timezone) {
        return GetHoursWithTimezone();
    }
    return hours_;
}

template <class T>
T Sum(const T& left, const T& right) {
    return left + right;
}

template <class T>
class Stack {
private:
    T* arr;
};

int main() {
    int sum = Sum<int>(1, 2);
    // std::string sum_str = Sum<std::string>("1", "2");  // CE

    Stack<bool> stack;

    // int hours, minutes, seconds;
    // std::cin >> hours >> minutes >> seconds;
    // Time time(hours, minutes, seconds);
    // time.SetHours(hours);
    // time.SetMinutes(minutes);
    // time.SetSeconds(seconds);

    // Time time;
    // time.SetHours(12);
    // time.SetMinutes(11);
    // time.SetSeconds(50);

    Time time(12, 11, 50);  // Time time = Time::Time(12, 11, 50);
    std::cout << time.GetHours() << ":" << time.GetMinutes() << ":" << time.GetSeconds() << std::endl;

    const Time const_time = Time(14, 20, 59);
    std::cout << const_time.GetHours() << ":" << const_time.GetMinutes() << ":" << const_time.GetSeconds() << std::endl;

    Time time_with_timezone(12, 11, 50, 5);

    Time time_default;
    Time time_default_1 = Time();

    Time time_with_timezone_only(3);
    // Time time_with_timezone_only_1 = 3;
    // time_with_timezone_only_1 = 5;  // time_with_timezone_only_1 = Time(5)
    Time time_with_timezone_only_2 = Time(4);

    int n = 10;
    int i = 1;
    int j = 3;

    int** arr_2d = new int*[n];
    for (int i = 0; i < n; ++i) {
        arr_2d[i] = new int[n];
    }

    arr_2d[i][j];

    for (int i = 0; i < n; ++i) {
        delete[] arr_2d[i];
    }
    delete[] arr_2d;

    int* arr_2d_optimal = new int[n * n];

    arr_2d_optimal[i * n + j];

    delete[] arr_2d_optimal;

    return 0;
}
