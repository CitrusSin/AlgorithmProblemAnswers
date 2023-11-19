#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i=0; i<n; i++) {
        std::cin >> a[i];
    }
    std::sort(a.begin(), a.end(), std::greater<int>());
    std::unique(a.begin(), a.end());
    std::cout << a[1] << std::endl;
    return 0;
}