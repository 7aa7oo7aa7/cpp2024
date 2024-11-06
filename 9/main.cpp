#include <iostream>
#include <cstring>
#include <cassert>

template <class T>
T* LowerBound(T* begin, T* end, const T& value) {
    return nullptr;
}

template <class T>
const T* LowerBound(const T* begin, const T* end, const T& value) {
    // const T* != T* const
    // const int + const T* = const int*

    // T = int, value = int16_t -> int value
    return nullptr;
}

template <class T>
T* LowerBound(T* begin, T* end, T& value) {
    return nullptr;
}

template <class T, class U>
T* LowerBound(T* begin, T* end, const U& value) {
    // T = int, U = int16_t
    // T = int, U = const char*
    return nullptr;
}

template <class T1, class T2, class T3>
void Merge(const T1* first_begin, const T1* first_end,
           const T2* second_begin, const T2* second_end,
           T3* out);
// int* -> int16_t* is not possible

size_t Strlen(const char* str);

struct TimeIncorrect {
    int hours;
    int minutes;
    int seconds;
};

// class default: private
// struct default: public

class Time {
public:
    void SetHours(const int value) {
        assert(0 <= value && value < 24);
        hours = value;
    }

    void SetMinutes(const int value) {
        assert(0 <= value && value < 60);
        minutes = value;
    }

    void SetSeconds(const int value) {
        assert(0 <= value && value < 60);
        seconds = value;
    }

    int GetHours(bool use_timezone = false) const;

    int GetMinutes() const {
        return minutes;
    }

    int GetSeconds() const {
        return seconds;
    }

    void SetTimezone(const int value) {
        timezone = value;
    }

private:
    int hours;
    int minutes;
    int seconds;
    int timezone = 0;

    int GetHoursWithTimezone() const {
        return hours + timezone;
    }
};

int Time::GetHours(bool use_timezone = false) const {
    if (use_timezone) {
        return GetHoursWithTimezone();
    }
    return hours;
}

int main() {
    Time time;
    time.SetHours(12);
    time.SetMinutes(59);
    time.SetSeconds(59);
    auto hours = time.GetHours();  // 12
    const Time time_const{};
    auto hours_from_const = time_const.GetHours();
    time_const.SetHours(12);  // CE

    // time.hours = 999;
    // time.seconds = -1;

    int* arr = new int[100];  // sorted

    auto* lower_bound_1 = LowerBound<int>(arr, arr + 100, 10);  // int*, int*, const int&
    auto* lower_bound_2 = LowerBound<const int>(arr, arr + 100, 10);  // const int*, const int*, const int&
    
    auto* lower_bound_3 = LowerBound(arr, arr + 100, 10);
    // T = int -> int*, int*, const int&
    // T = const int -> const int*, const int*, const int&

    delete[] arr;

    // CString tests
    char* s = "a";
    assert(Strlen(s) == std::strlen(s));

    return 0;
}
