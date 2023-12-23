#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;
using i64 = int64_t;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    priority_queue<pair<int, int>> pqp;
    for (int i=1; i<=n; i++) {
        int v;
        cin >> v;
        auto p = make_pair(v, i);
        if (pqp.size() < n/2+1 || p < pqp.top()) pqp.push(p);
        if (pqp.size() > n/2+1) pqp.pop();
    }

    i64 ans = 0;
    vector<int> st;
    st.reserve(n/2+1);
    while (!pqp.empty()) {
        auto p = pqp.top();
        pqp.pop();
        ans += p.first;
        st.push_back(p.second);
    }

    sort(st.begin(), st.end());

    cout << ans << '\n';
    for (int i : st) {
        cout << i << ' ';
    }
    cout << '\n';
    return 0;
}