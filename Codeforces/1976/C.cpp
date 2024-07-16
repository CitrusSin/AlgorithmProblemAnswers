#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n+m+1), b(n+m+1);
    for (int i=0; i<n+m+1; i++) {
        cin >> a[i];
    }
    for (int i=0; i<n+m+1; i++) {
        cin >> b[i];
    }

    vector<int> st(n+m+1);
    for (int i=0; i<n+m+1; i++) {
        st[i] = a[i] > b[i];
    }

    vector<int> ans(n+m+1);
    vector<int> state(n+m);
    int rightp = 0, rightt = 0;
    int score = 0;
    int pc = 0, tc = 0;
    for (int i=0; i<n+m; i++) {
        if (tc == m || (pc < n && st[i])) {
            state[i] = 1;
            pc++;
            score += a[i];
            rightp = i;
        } else {
            state[i] = 0;
            tc++;
            score += b[i];
            rightt = i;
        }
    }
    int pivot = n+m;
    while (pivot > 0) {
        ans[pivot] = score;
        if (state[pivot-1]) {
            pc--;
            score -= a[pivot-1];
        } else {
            tc--;
            score -= b[pivot-1];
        }
        int sta = tc == m || (pc < n && st[pivot]);
        if (sta) {
            score += a[pivot];
        } else {
            score += b[pivot];
        }
        bool change = sta != state[pivot-1];
        if (change) {
            if (sta) { // tester => programmer
                
            }
        }
        state[pivot-1] = sta;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}