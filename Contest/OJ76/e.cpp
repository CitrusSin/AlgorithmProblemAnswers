#include <bits/stdc++.h>

using namespace std;
using u64 = unsigned long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<u64> heights(n);
    for (int i=0; i<n; i++) {
        cin >> heights[i];
    }

    u64 cnt = 0;

    deque<int> st;
    //vector<int> l(n), r(n);
    for (int i=0; i<n; i++) {
        while (!st.empty() && heights[st.back()]<heights[i]) {
            st.pop_back();
        }
        if (!st.empty()) {
            int p = heights[st.back()];
            auto it = st.rbegin();
            while (it != st.rend() && heights[*it] == p) {
                it++;
                cnt++;
            }
        }
        st.push_back(i);
    }
    st.clear();
    for (int i=n-1; i>=0; i--) {
        while (!st.empty() && heights[st.back()]<=heights[i]) {
            st.pop_back();
        }
        if (!st.empty()) {
            cnt++;
        }
        st.push_back(i);
    }
    st.clear();

    cout << cnt << endl;
    return 0;
}