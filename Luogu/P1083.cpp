#include <bits/stdc++.h>

using namespace std;

bool check_rec(int x, vector<int> room_df, const vector<tuple<int, int, int>>& records) {
    for (int i=0; i<=x; i++) {
        const tuple<int, int, int>& rec = records[i];
        int d = get<0>(rec), s = get<1>(rec), t = get<2>(rec);
        room_df[s-1] -= d;
        if (t < room_df.size()) room_df[t] += d;
    }

    int sum = 0;
    for (int df : room_df) {
        sum += df;
        if (sum < 0) return false;
    }
    return true;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> room_df(n);
    int sum = 0;
    for (int i=0; i<n; i++) {
        int p;
        cin >> p;
        room_df[i] = p - sum;
        sum = p;
    }

    vector<tuple<int, int, int>> records(m);
    for (int i=0; i<m; i++) {
        int d, s, t;
        cin >> d >> s >> t;
        records[i] = make_tuple(d, s, t);
    }

    if (check_rec(m-1, room_df, records)) {
        cout << "0" << endl;
        return 0;
    }
    int l = 0, r = m-1;
    while (l < r) {
        int mid = l+(r-l)/2;
        if (check_rec(mid, room_df, records)) {
            l = mid+1;
        } else {
            r = mid;
        }
    }
    cout << "-1" << endl;
    cout << l+1 << endl;
    return 0;
}