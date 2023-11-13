#include <bits/stdc++.h>

using namespace std;

int qpow(int base, unsigned int exp) {
    int r = base, rst = 1;
    while (exp) {
        if (exp & 1) rst *= r;
        r *= r;
        exp >>= 1;
    }
    return rst;
}

int solve(const string& s) {
    size_t n = s.size();

    vector<int> pss(n);
    vector<int> lims(n, 0);
    deque<int> dq;

    for (size_t i = 0; i < n; i++) {
        int v = qpow(10, s[n-i-1]-'A');
        while (!dq.empty() && dq.back() <= v) {
            dq.pop_back();
        }
        if (dq.size() > 0) {
            v *= -1;
            lims[n-i-1] = dq.front();
        }
        dq.push_back(abs(v));
        pss[n-i-1] = v;
    }

    array<int, 5> counter;
    for (int i=0; i<5; i++) counter[i] = 0;

    int inc = 0;
    for (size_t i = 0; i < n; i++) {
        int l = log10(abs(pss[i]));
        for (int j=0; j<5; j++) {
            if (j == l) continue;

            int p2 = qpow(10, j);
            if (p2 < lims[i]) p2 *= -1;
            p2 -= pss[i];

            if (j < l) {
                for (int r=j; r<l; r++) {
                    if (qpow(10, r) >= lims[i]) p2 += counter[r] * qpow(10, r) * 2;
                }
            } else {
                for (int r=l; r<j; r++) {
                    if (qpow(10, r) >= lims[i]) p2 -= counter[r] * qpow(10, r) * 2;
                }
            }

            inc = max(inc, p2);
        }
        counter[l]++;
    }

    int val = accumulate(pss.begin(), pss.end(), 0);
    return val + inc;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        cout << solve(s) << endl;
    }
    return 0;
}