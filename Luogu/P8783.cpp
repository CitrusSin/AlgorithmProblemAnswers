#include <bits/stdc++.h>
using namespace std;
using u64 = unsigned long long;

inline u64 pfrange(const vector<vector<u64>>& pfsum, int x1, int y1, int x2, int y2) {
    u64 sum = pfsum[x2][y2];
    if (x1 > 0) sum -= pfsum[x1-1][y2];
    if (x1 > 0 && y1 > 0) sum += pfsum[x1-1][y1-1];
    if (y1 > 0) sum -= pfsum[x2][y1-1];
    return sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<u64>> pfsum(n, vector<u64>(m, 0));
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            int p;
            cin >> p;
            u64 sum = p;
            if (i > 0) sum+=pfsum[i-1][j];
            if (i > 0 && j > 0) sum-=pfsum[i-1][j-1];
            if (j > 0) sum+=pfsum[i][j-1];
            pfsum[i][j] = sum;
        }
    }

    u64 total_cnt = 0;
    for (int x1=0; x1<n; x1++) {
        for (int y1=0; y1<m; y1++) {
            int x2 = n-1, y2 = m-1;
            u64 sum = pfrange(pfsum, x1, y1, x2, y2);
            while (x2 > x1 && sum > k) {
                x2--;
                sum = pfrange(pfsum, x1, y1, x2, y2);
            }
            while (y2 > y1 && sum > k) {
                y2--;
                sum = pfrange(pfsum, x1, y1, x2, y2);
            }
            if (sum <= k) {
                u64 cnt = (x2-x1+1)*(y2-y1+1);
                while (x2 < n-1 && y2 > y1) {
                    while (x2 < n-1 && sum <= k) {
                        sum = pfrange(pfsum, x1, y1, ++x2, y2);
                        if (sum <= k) cnt += (y2-y1+1);
                    }
                    while (y2 > y1 && sum > k) {
                        sum = pfrange(pfsum, x1, y1, x2, --y2);
                        if (sum <= k) cnt += (y2-y1+1);
                    }
                }
                if (y2 == y1) {
                    while (x2 < n-1 && pfrange(pfsum, x1, y1, ++x2, y2) <= k) {
                        cnt++;
                    }
                }
                total_cnt += cnt;
            }
        }
    }
    cout << total_cnt << endl;
    return 0;
}