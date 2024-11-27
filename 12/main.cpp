#include <iostream>
#include <algorithm>

struct Team {
public:
    int i;  // номер команды
    int S;  // количество решённых задач
    int T;  // штрафное время
};

// bool operator<(const Team& left, const Team& right) {
    // Сначала учитывается количество решённых задач (в порядке убывания).
    // Далее, при равенстве количества решённых задач, Кубок учитывает штрафное время прохождения испытания (в порядке возрастания).
    // При прочих равных сортировка происходит по номеру команды (в порядке возрастания).

    // if (left.S != right.S) {
    //     return left.S > right.S;
    // } else if (left.T != right.T) {
    //     return left.T < right.T;
    // }
    // return left.i < right.i;

    // return left.S > right.S || (left.S == right.S && (left.T < right.T || (left.T == right.T && left.i < right.i)));
// }

std::istream& operator>>(std::istream& stream, Team& team) {
    // i - main: constructor, i = ???
    stream >> team.S >> team.T;
    return stream;
}

std::ostream& operator<<(std::ostream& stream, const Team& team) {
    stream << team.i;
    return stream;
}

struct TeamLess {
    bool operator()(const Team& left, const Team& right) const {
        return left.S > right.S || (left.S == right.S && (left.T < right.T || (left.T == right.T && left.i < right.i)));
    }
};

// int x
// Less(left, right) = left < x && right > x

bool TeamLessFunc(const Team& left, const Team& right) {
    return left.S > right.S || (left.S == right.S && (left.T < right.T || (left.T == right.T && left.i < right.i)));
}

// TeamLess comparator;
// comparator(team_left, team_right);

template <size_t T, size_t L, size_t M>
class Quantity {
    // code
};

using Time = Quantity<1, 0, 0>;

template <class T, size_t Size>
class Array {
    // code
};

template <class T, size_t Size>
using Array2D = Array<Array<T, Size>, Size>;  // arr[Size][Size]

template <class T>
size_t GetSize(const T& array) {
    return 0;
}

template <class T, size_t Size>
size_t GetSize(const T (&array)[Size]) {
    return Size;
}

// Time time;  // Quantity<1, 0, 0> time
// time + time;  // operator+<Quantity<1, 0, 0>>

int main() {

    int n = 0;
    std::cin >> n;
    Team* arr = new Team[n];

    for (size_t i = 0; i < n; ++i) {
        std::cin >> arr[i];
        arr[i].i = i + 1;
    }

    TeamLess comparator;
    std::sort(arr, arr + n, comparator);
    // std::sort(arr, arr + n, TeamLessFunc);

    for (size_t i = 0; i < n; ++i) {
        std::cout << arr[i] << "\n";
    }

    delete[] arr;

    return 0;
}
