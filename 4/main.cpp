#include <iostream>

int main() {

    // std::vector<int> v;  // НЕЛЬЗЯ!!!!!0
    // v.push_back(1);
    // v.push_back(1);
    // v.push_back(1);
    // v.push_back(1);

    int n = 0;
    std::cin >> n;

    int* arr = new int[n];
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    int shouldGrow = 0;
    std::cin >> shouldGrow;
    if (shouldGrow != 0) {
        // arr[2 * n]
        int* new_arr = new int[2 * n];
        // 1. copy first n elements
        for (int i = 0; i < n; ++i) {
            new_arr[i] = arr[i];
        }
        // 2. std::cin >> last n elements
        for (int i = 0; i < n; ++i) {
            std::cin >> new_arr[n + i];
        }
        // 3. move new_arr -> arr
        delete[] arr;
        arr = new_arr;
        n *= 2;
    }

    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    delete[] arr;

    return 0;
}
