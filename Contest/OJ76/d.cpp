#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int> heights(n);
    for (int i=0; i<n; i++) {
        cin >> heights[i];
    }

    stack<int> st;
    vector<int> targets(n);
    for (int i=n-1; i>=0; i--) {
        while (!st.empty() && heights[st.top()] <= heights[i]) {
            st.pop();
        }
        targets[i] = st.empty()?0:st.top()+1;
        st.push(i);
    }
    for (int p : targets) {
        cout << p << endl;
    }
    return 0;
}