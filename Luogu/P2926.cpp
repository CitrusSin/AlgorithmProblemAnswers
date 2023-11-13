#include <bits/stdc++.h>

using namespace std;

const int N = 1e6+1;

int cnt[N], idx[100001], res[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    for (int i=0; i<n; i++) {
        cin >> idx[i];
        cnt[idx[i]]++;
    }

    for (int i=1; i<N; i++) {
        if (cnt[i]) {
            for (int j=1; j<=N/i; j++) {
                res[i*j]+=cnt[i];
            }
            res[i]--;
        }
    }

    for (int i=0; i<n; i++) {
        cout << res[idx[i]] << endl;
    }
    return 0;
}