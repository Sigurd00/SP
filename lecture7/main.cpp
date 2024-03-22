//
// Created by sigurd on 01-03-24.
//
#include <iostream>
#include <vector>

void print(const std::vector<int>& vec) {
    std::cout << "{";
    if (!vec.empty()) {
        std::cout << vec[0];
        for (size_t i = 1; i < vec.size(); ++i) {
            std::cout << "," << vec[i];
        }
    }
    std::cout << "}";
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec) {
    os << "{";
    if (!vec.empty()) {
        os << vec[0];
        for (size_t i = 1; i < vec.size(); ++i) {
            os << "," << vec[i];
        }
    }
    os << "}";
    return os;
}

int main() {
    print(std::vector{1, 2, 3});
    std::cout << std::vector{1, 2, 3};
    std::cout << std::vector{1,2,3} << std::endl; // should still print "{1,2,3}"
    std::cout << std::vector{2.7,3.14} << std::endl; // should print "{2.7,3.14}"
    std::cout << std::vector{std::vector{"hello", "template"}, std::vector{"world"}} << std::endl;
    return 0;
}
