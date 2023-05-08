#include <iostream>
#include <vector>
#include <set>

using namespace std;
using u64 = uint64_t;

u64 gcd(u64 a, u64 b) {
    return b?gcd(b, a%b):a;
}

void gcd_dfs(set<u64>& res, u64 l, u64 r, u64 limit, u64 t = 0, u64 p = 0) {
    if (l > r || p >= limit || t == 1) {
        if (t && p == limit || t == 1) res.insert(t);
        return;
    }
    gcd_dfs(res, l+1, r, limit, t, p);
    gcd_dfs(res, l+1, r, limit, gcd(l, t), p+1);
}

int main() {
    int l, r, k;
    cin >> l >> r >> k;

    set<u64> st;
    gcd_dfs(st, l, r, k);
    cout << st.size() << endl;
    return 0;
}