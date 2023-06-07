// x^2 == 1 mod n
#include <bits/stdc++.h>

using namespace std;
using u64 = uint64_t;

vector<pair<u64, u64>> prime_decomp(u64 x) {
    vector<pair<u64, u64>> rst;
    for (u64 i=2; i*i<=x; i++) {
        if (x%i==0) rst.emplace_back(i, 0);
        while (x%i==0) {
            rst.back().second++;
            x /= i;
        }
    }
    if (x > 1) {
        rst.emplace_back(x, 1);
    }
    return rst;
}

void dfs_cof(
    const vector<pair<u64, u64>>& decm,
    const function<void(u64)>& cb,
    size_t begi = 0,
    u64 k = 1
) {
    size_t n = decm.size()-begi;
    if (n == 0) {
        cb(k);
        return;
    }
    
    u64 base = k;
    for (u64 i=0; i<=decm[begi].second; i++) {
        dfs_cof(decm, cb, begi+1, base);
        base *= decm[begi].first;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    // n|(x-1)(x+1)
    // 12 = 2(2)*3(1)
    u64 n;
    cin >> n;
    vector<pair<u64, u64>> dec = prime_decomp(n);

    if (n == 1) {
        cout << "None" << endl;
        return 0;
    }
    
    set<u64> cofs;
    dfs_cof(dec, [&cofs](u64 val){cofs.insert(val);});
    
    set<u64> result;
    for (u64 p : cofs) {
        u64 q = n/p;
        if (p >= q) break;
        if ((q-2) % p == 0) {
            result.insert(q-1);
            result.insert(n-q+1);
        }
    }
    if (result.empty()) {
        cout << "None" << endl;
    } else {
        for (u64 p : result) {
            cout << p << endl;
        }
    }
    return 0;
}