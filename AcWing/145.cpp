#include <bits/stdc++.h>

using namespace std;

constexpr int N = 100010, M = N*31;

int a[N] = {};
int trie[M][2] = {}, idx = 0;

void insert(int x) {
    int p = 0;
    for (int i=30; i>=0; i--) {
        int bit = (x >> i) & 1;
        if (trie[p][bit] == 0) {
            trie[p][bit] = ++idx;
        }
        p = trie[p][bit];
    }
}

int query(int x) {
    int p = 0;
    int result = 0;
    for (int i=30; i>=0; i--) {
        int bit = (x >> i)&1;
        if (trie[p][!bit]) {
            result |= 1 << i;
            p = trie[p][!bit];
        } else p = trie[p][bit];
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> a[i];
        insert(a[i]);
    }

    int max_val = 0;
    for (int i=0; i<n; i++) {
        int x = a[i];
        int res = query(x);
        if (res > max_val) max_val = res;
    }

    cout << max_val << endl;
    return 0;
}