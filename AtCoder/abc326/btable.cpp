#include <iostream>

bool number_ok(int x) {
    int a = x % 10;
    int b = x / 10 % 10;
    int c = x / 100 % 10;
    return b*c==a;
}

int main() {
    for (int i=100; i<1000; i++) {
        if (number_ok(i)) std::cout << i << ", ";
    }
    std::cout << std::endl;
    return 0;
}