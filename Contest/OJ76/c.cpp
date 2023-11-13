#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }

    vector<int> pfsum(n);
    pfsum[0] = a[0];
    for (int i=1; i<n; i++) {
        pfsum[i] = pfsum[i-1] + a[i];
    }

    vector<int> l(n), r(n);
    deque<int> st;
    for (int i=0; i<n; i++) {
        while (!st.empty() && st.back() > pfsum[i]) {
            st.pop_back();
        }
        st.push_back(pfsum[i]);
        l[i] = st.front();
    }
    st.clear();
    for (int i=n-1; i>=0; i--) {
        while (!st.empty() && st.back() > pfsum[i]) {
            st.pop_back();
        }
        st.push_back(pfsum[i]);
        r[i] = st.front();
    }
    st.clear();

    int cnt = 0;
    cnt += r[0] >= 0;
    for (int i=1; i<n; i++) {
        int d1 = -pfsum[i-1];
        if (r[i]+d1>=0) {
            int d2 = pfsum[n-1]+d1;
            if (l[i-1]+d2>=0) {
                cnt++;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}