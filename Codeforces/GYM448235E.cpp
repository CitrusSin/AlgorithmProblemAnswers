#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m, x;
    cin >> n >> m >> x;

    char mp[n][m];
    int ctdp[n][m], qudp[n][m];

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> mp[i][j];
        }
    }

    switch (mp[0][0]) {
    case '0':
        ctdp[0][0] = qudp[0][0] = 0;
        break;
    case '1':
        ctdp[0][0] = 1;
        qudp[0][0] = 0;
        break;
    case '?':
        ctdp[0][0] = 0;
        qudp[0][0] = 1;
        break;
    }

    for (int i=1; i<n; i++) {
        ctdp[i][0] = ctdp[i-1][0];
        qudp[i][0] = qudp[i-1][0];
        switch (mp[i][0]) {
        case '1':
            ctdp[i][0]++;
            break;
        case '?':
            qudp[i][0]++;
            if (qudp[i][0] > x) qudp[i][0] = x;
            break;
        }
    }

    for (int j=1; j<m; j++) {
        ctdp[0][j] = ctdp[0][j-1];
        qudp[0][j] = qudp[0][j-1];
        switch (mp[0][j]) {
        case '1':
            ctdp[0][j]++;
            break;
        case '?':
            qudp[0][j]++;
            if (qudp[0][j] > x) qudp[0][j] = x;
            break;
        }
    }

    for (int i=1; i<n; i++) {
        for (int j=1; j<m; j++) {
            int cinc = 0;
            switch (mp[i][j]) {
            case '1':
                cinc = 1;
            case '0':
                if (ctdp[i-1][j]+qudp[i-1][j] > ctdp[i][j-1]+qudp[i][j-1]) {
                    ctdp[i][j] = ctdp[i-1][j] + cinc;
                    qudp[i][j] = qudp[i-1][j];
                } else {
                    ctdp[i][j] = ctdp[i][j-1] + cinc;
                    qudp[i][j] = qudp[i][j-1];
                }
                break;
            case '?':
                if (ctdp[i-1][j]+min(qudp[i-1][j]+1, x) > ctdp[i][j-1]+min(qudp[i][j-1]+1, x)) {
                    ctdp[i][j] = ctdp[i-1][j];
                    qudp[i][j] = min(qudp[i-1][j]+1, x);
                } else {
                    ctdp[i][j] = ctdp[i][j-1];
                    qudp[i][j] = min(qudp[i][j-1]+1, x);
                }
                break;
            }
        }
    }

    cout << (ctdp[n-1][m-1] + qudp[n-1][m-1]) << endl;
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