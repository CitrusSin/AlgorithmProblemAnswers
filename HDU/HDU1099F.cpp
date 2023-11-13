#include <bits/stdc++.h>

using namespace std;

int nearest_larger_square_number(int x) {
    int v = sqrt(x);
    while (v * v > x) v--;
    while (v * v < x) v++;

    return v * v;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }

    vector<int> pfs(n);
    pfs[0] = a[0];
    for (int i=1; i<n; i++) {
        pfs[i] = pfs[i-1] + a[i];
    }

    int max_contrib = 0;
    for (int i=0; i<n; i++) {
        array<int, 300> contrib;
        contrib.fill(0);
        int null_contrib = 0;
        for (int l=0; l<=i; l++) {
            for (int r=i; r<n; r++) {
                int sum = pfs[r];
                if (l > 0) sum -= pfs[l-1];
                if (sum == nearest_larger_square_number(sum)) null_contrib++;

                sum -= a[i];

                int q = nearest_larger_square_number(sum);
                if (q == sum) q = nearest_larger_square_number(sum+1);
                while (q - sum <= 300 && q - sum > 0) {
                    contrib[q-sum-1]++;
                    q = nearest_larger_square_number(q+1);
                }
            }
        }

        int net_con = (*max_element(contrib.begin(), contrib.end())) - null_contrib;
        if (net_con > 0) {
            max_contrib = max(max_contrib, net_con);
        }
    }

    int count = 0;
    for (int i=0; i<n; i++) {
        for (int j=i; j<n; j++) {
            int sum = pfs[j];
            if (i > 0) sum -= pfs[i-1];
            if (sum == nearest_larger_square_number(sum)) count++;
        }
    }

    cout << (count + max_contrib) << endl;
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