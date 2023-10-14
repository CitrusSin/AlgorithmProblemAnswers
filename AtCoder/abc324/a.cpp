#include <iostream>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int n;
    std::cin >> n;

    int a = 0;
    std::cin >> a;
    n--;
    while (n--) {
        int b;
        std::cin >> b;
        if (a != b) {
            std::cout << "No" << '\n';
            return 0;
        }
    }
    std::cout << "Yes" << '\n';
    return 0;
}