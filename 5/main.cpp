#include <iostream>
#include <cstring>



int main() {
    const char s[7] = "string";
    // s[0] = 's'
    // s[1] = 't'
    // s[2] = 'r'
    // s[3] = 'i'
    // s[4] = 'n'
    // s[5] = 'g'
    // s[6] = '\0'
    char c = 0;  // '\0'
    char s1[7] = "string";

    // s1 = "str1ng";  // CE
    s1[0] = 'a';

    char str1[4] = "kek";
    char str2[4] = "kek";
    std::cout << (str1 == str2 ? "true" : "false") << std::endl;

    // "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"

    // size_t strlen(char* str) {
    //     size_t size = 0;
    //     for (; str[size] != '\0'; ++size);
    //     return size;
    // }

    // size_t size = strlen(str);

    // for (size_t i = 0; i < size)  // O(n)

    size_t size1 = 0;
    for (; str1[size1] != '\0'; ++size1);

    size_t size2 = 0;
    for (; str2[size2] != '\0'; ++size2);

    // "a" -> "a\0" -> size("a") = 1

    bool equal = true;
    if (size1 != size2) {
        equal = false;
    } else {
        for (size_t i = 0; i < size1; ++i) {
            if (str1[i] != str2[i]) {
                equal = false;
                break;
            }
        }
    }



    return 0;
}
