#include <bits/stdc++.h>

using namespace std;

const int N = 1e8+1;
bool np[N];
int primes[N], cnt = 0;

void select_np(int n) {
    np[0] = true;
    np[1] = true;
    for (int i=2; i<=n; i++) {
        if (!np[i]) primes[cnt++] = i;
        for (int j=0; j<cnt; j++) {
            if ((long long)i * primes[j] > n) break;
            np[i * primes[j]] = true;
            if (i % primes[j] == 0) break;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, q;
    cin >> n >> q;
    select_np(n);

    while (q--) {
        int k;
        cin >> k;
        cout << primes[k-1] << endl;
    }
    return 0;
}