#include <iostream>
#include <string>

int main() {
    std::string s;
    std::cin >> s;
    for (size_t i=0; i<s.size(); i++) {
        std::cout << s[i];
        if (i < s.size() - 1) std::cout << ' ';
    }
    std::cout << std::endl;
    return 0;
}