#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, l, r;
    cin >> n >> l >> r;

    vector<int> a(n+1);
    for (int i=0; i<=n; i++) {
        cin >> a[i];
    }

    vector<int> result(n+1, 0);

    deque<int> dec;
    for (int i=0; i<l; i++) {
        while (!dec.empty() && result[dec.back()] < result[i]) {
            dec.pop_back();
        }
        dec.push_back(i);
    }
    for (int i=1; i<l; i++) result[i] = -2147483648;
    result[l] = result[dec.front()] + a[l];
    for (int i=l+1; i<=n; i++) {
        if (!dec.empty() && dec.front() < i-r) {
            dec.pop_front();
        }
        while (!dec.empty() && result[dec.front()] < result[i-l]) {
            dec.pop_back();
        }
        dec.push_back(i-l);
        result[i] = result[dec.front()] + a[i];
    }
    
    int t = *max_element(result.begin()+(n-r+1), result.end());
    cout << t << endl;
    return 0;
}