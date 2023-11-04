#include <iostream>

int main() {
    int n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    for (int i=0; i<n-1; i++) {
        if (s[i] == 'a' && s[i+1] == 'b' || s[i] == 'b' && s[i+1] == 'a') {
            std::cout << "Yes" << std::endl;
            return 0;
        }
    }
    std::cout << "No" << std::endl;
    return 0;
}