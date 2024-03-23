#include <bits/stdc++.h>

using namespace std;

void output(const vector<int>& arr) {
    size_t n = arr.size();
    for (size_t i=0; i<n; i++) {
        if (i) cout << ' ';
        cout << (arr[i]+1);
    }
    cout << '\n';
}

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> arr(n), par(n);
    //k = 3
    //0, 2, 1
    //k=4
    //0, 3, 2, 1

    int gpc = n / k + (n % k > 0);

    for (int i=0; i<gpc; i++) {
        arr[i * k] = i * k;
        par[i*k] = i;
        for (int j=1; j<k; j++) {
            if (i*k+j >= n) break;
            arr[i*k+j] = i*k+(k-j);
            par[i*k+j] = i;
        }
    }

    output(arr);
    cout << gpc << '\n';
    output(par);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t--) solve();

    return 0;
}