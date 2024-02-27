#include <bits/stdc++.h>

using namespace std;
using u64 = uint64_t;

vector<u64> generate_list(u64 upper) {
    vector<u64> ans;
    constexpr array<u64, 4> bases{2, 3, 5, 7};

    function<void(int, u64)> f = [&](int idx, u64 p) {
        if (idx >= 4) {
            ans.push_back(p);
            return;
        }
        while (p <= upper) {
            f(idx+1, p);
            p *= bases[idx];
        }
    };

    f(0, 1);
    sort(ans.begin(), ans.end());
    return ans;
}

int main() {
    u64 l, r;
    cin >> l >> r;

    vector<u64> nums = generate_list(r);
    auto lb = lower_bound(nums.begin(), nums.end(), l);
    u64 cnt = nums.end() - lb;

    cout << cnt << '\n';
    return 0;
}