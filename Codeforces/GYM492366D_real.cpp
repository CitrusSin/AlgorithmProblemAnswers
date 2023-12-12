#include <algorithm>
#include <cstdint>
#include <iostream>
#include <array>
#include <vector>

using namespace std;
using u64 = uint64_t;

constexpr array nums = {2ull, 3ull, 5ull, 7ull, 23ull, 37ull, 53ull, 73ull, 373ull};

int main() {
    u64 n, m;
    cin >> n >> m;

    auto left = lower_bound(nums.begin(), nums.end(), n);
    auto right = upper_bound(nums.begin(), nums.end(), m);
    int cnt = right - left;

    cout << cnt << endl;
}