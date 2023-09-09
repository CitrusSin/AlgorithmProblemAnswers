#include <bits/stdc++.h>

using namespace std;

int solve(const vector<int>& arr) {
    set<int> st;
    for (int x : arr) {
        st.insert(x);
    }

    int last = -1, cnt = 0, maxcnt = 0;
    for (int x : st) {
        if (last == -1 || last == x-1) {
            cnt++;
            maxcnt = max(maxcnt, cnt);
        } else {
            cnt = 1;
        }
        last = x;
    }

    return maxcnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, q;
    cin >> n >> q;

    vector<int> arr(n);
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }

    while (q--) {
        int x;
        cin >> x;
        for (int& r : arr) {
            r ^= x;
        }
        cout << solve(arr) << endl;
    }
    return 0;
}