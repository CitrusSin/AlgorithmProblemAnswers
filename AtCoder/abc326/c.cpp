#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(n);
    for (int i=0; i<n; i++) std::cin >> a[i];
    std::sort(a.begin(), a.end());

    int ans = 0;

    for (int i=0; i<n; i++) {
        int st = a[i];
        int ed = a[i] + m - 1;
        int idx = std::upper_bound(a.begin(), a.end(), ed) - a.begin();
        int len = idx - i;
        ans = std::max(ans, len);
    }

    std::cout << ans << std::endl;
    return 0;
}