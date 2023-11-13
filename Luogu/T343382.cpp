#include <bits/stdc++.h>

using namespace std;

int lowbit(int x) {
    return x & -x;
}

void bidxt_add(vector<int>& arr, int idx, int d) {
    int n = arr.size();
    while (idx < n) {
        arr[idx] += d;
        idx += lowbit(idx+1);
    }
}

int bidxt_query(vector<int>& arr, int idx) {
    int rst = 0;
    while (idx >= 0) {
        rst += arr[idx];
        idx -= lowbit(idx+1);
    }
    return rst;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int> bidxt(n, 0), value(n);
    int p = 0;
    for (int i=0; i<n; i++) {
        int r;
        cin >> r;
        value[i] = r - p;
        p = r;
        bidxt_add(bidxt, i, value[i]);
    }

    for (int tt=0; tt<n; tt++) {
        int op, l, r, x;
        cin >> op >> l >> r >> x;
        l--, r--;
        if (op) {
            int val = bidxt_query(bidxt, r);
            cout << val << endl;
        } else {
            //value[l]+=x;value[r+1]-=x;
            value[l] += x;
            bidxt_add(bidxt, l, x);

            if (r+1 < n) {
                value[r+1] -= x;
                bidxt_add(bidxt, r+1, -x);
            }
        }
    }

    return 0;
}