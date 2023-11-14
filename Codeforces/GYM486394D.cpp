#include <iostream>
#include <limits>
#include <vector>

int sr(const std::vector<int>& a, int p, int q) {
    int d = 0;
    for (size_t i=0; i<a.size(); i++) {
        if (i % 2) {
            if (a[i] == p) d++;
        } else {
            if (a[i] == q) d++;
        }
    }
    return d;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i=0; i<n; i++) std::cin >> a[i], a[i]%=2;
    int min_d = std::numeric_limits<int>::max();

    for (int i=0; i<=1; i++)
        for (int j=0; j<=1; j++)
            min_d = std::min(min_d, sr(a, i, j));
    std::cout << min_d << std::endl;
    return 0;
}