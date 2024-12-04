#include <iostream>
#include <algorithm>
#include <functional>

// git init
// git remote add origin https://github.com/7aa7oo7aa7/cpp_2024_test_repo_1.git
// git add main.cpp / git reset main.cpp / git add .
// git status
// git commit -m "initial commit"
// git push origin master
// git config --global user.name YOUR_USERNAME
// git branch
// git checkout -b branch1





struct Team {
public:
    int i;  // номер команды
    int S;  // количество решённых задач
    int T;  // штрафное время
};

std::istream& operator>>(std::istream& stream, Team& team) {
    stream >> team.S >> team.T;
    return stream;
}

std::ostream& operator<<(std::ostream& stream, const Team& team) {
    stream << team.i;
    return stream;
}

bool TeamLessFunc(const Team& left, const Team& right) {
    return left.S > right.S || (left.S == right.S && (left.T < right.T || (left.T == right.T && left.i < right.i)));
}

// DFS - depth first search - обход в глубину
// pre-order, in-order, post-order

struct Tree {
    size_t n_vertices;
    int* vertices;
};

int* vertices_arr;

void DFS(const Tree& tree, const std::function<void(int vertex)>& f) {
    for (size_t v = 0; v < tree.n_vertices; ++v) {
        f(tree.vertices[v]);
    }
}

int x = 0;

int main() {

    int n = 0;
    std::cin >> n;
    Team* arr = new Team[n];

    for (size_t i = 0; i < n; ++i) {
        std::cin >> arr[i];
        arr[i].i = i + 1;
    }

    bool (*less)(const Team&, const Team&) = &TeamLessFunc;
    bool (*less2)(const Team&, const Team&) = TeamLessFunc;
    // (*less)(arr[0], arr[1]);

    std::function<bool(const Team&, const Team&)> less_lambda = TeamLessFunc;

    std::function<bool(const Team&, const Team&)> less_lambda_2 = [](const Team& left, const Team& right) {
        // new scope
        return left.S > right.S || (left.S == right.S && (left.T < right.T || (left.T == right.T && left.i < right.i)));
    };

    auto less_lambda_3 = [](const Team& left, const Team& right) -> bool {
        return left.S > right.S || (left.S == right.S && (left.T < right.T || (left.T == right.T && left.i < right.i)));
    };

    const auto& less_lambda_4 = less_lambda_3;

    auto less_lambda_5 = [](const Team& left, const Team& right) -> bool {
        ++x;
        return TeamLessFunc(left, right);
    };

    // [n, arr]
    // [=]
    // [&n, &arr]
    // [&]

    // std::sort(arr, arr + n, TeamLessFunc);
    // std::sort(arr, arr + n, *less);
    std::sort(arr, arr + n, less_lambda_4);

    for (size_t i = 0; i < n; ++i) {
        std::cout << arr[i] << "\n";
    }

    delete[] arr;

    Tree tree;
    DFS(tree, [](int vertex) { std::cout << vertex; });
    DFS(tree, [](int vertex) { vertices_arr[vertex] = vertex; });

    return 0;
}
