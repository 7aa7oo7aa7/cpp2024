#include <iostream>

int main() {

    int arr[2][2][2];
    // 1 1
    // 1 1

    // dyn_arr[n][m]
    int n = 0;
    int m = 0;
    std::cin >> n >> m;

    int** dyn_arr = new int*[n];
    for (int i = 0; i < n; ++i) {
        dyn_arr[i] = new int[m];
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            dyn_arr[i][j] = i + j;
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cout << dyn_arr[i][j] << " ";
        }
        std::cout << std::endl;
    }

    for (int i = 0; i < n; ++i) {
        delete[] dyn_arr[i];
    }
    delete[] dyn_arr;

    return 0;
}