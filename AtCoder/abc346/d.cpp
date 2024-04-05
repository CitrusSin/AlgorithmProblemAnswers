#include <bits/stdc++.h>
#include <limits>

using namespace std;

int main() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    vector<int64_t> c(n);
    for (int i=0; i<n; i++) cin >> c[i];

    vector<int64_t> p0s(n), p1s(n);

    for (int i=0; i<n; i++) {
        p0s[i] = (s[i] == '0') ^ (i % 2) ? 0 : c[i];
        p1s[i] = (s[i] == '1') ^ (i % 2) ? 0 : c[i];
    }

    vector<int64_t> p0e = p0s, p1e = p1s;
    
    for (int i=1; i<n; i++) {
        p0s[i] += p0s[i-1];
        p1s[i] += p1s[i-1];
    }
    for (int i=n-2; i>=0; i--) {
        p0e[i] += p0e[i+1];
        p1e[i] += p1e[i+1];
    }

    int64_t ans = numeric_limits<int64_t>::max();
    for (int i=0; i<n-1; i++) {
        ans = min(ans, p0s[i] + p1e[i+1]);
        ans = min(ans, p1s[i] + p0e[i+1]);
    }

    cout << ans << '\n';
    return 0;
}