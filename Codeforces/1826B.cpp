#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
    return b?gcd(b, a%b):a;
}

template <typename Iter>
int gcd(Iter a, Iter b) {
    int p = 0;
    while (a != b) {
        p = gcd(*(a++), p);
    }
    return p;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    vector<int> mods(n/2);
    for (int i=0; i<n/2; i++) {
        mods[i] = max(a[i], a[n-i-1]) - min(a[i], a[n-i-1]);
    }

    int m = gcd(mods.begin(), mods.end());
    cout << m << endl;
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