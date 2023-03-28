#include <bits/stdc++.h>

using namespace std;

unordered_set<int> fwd[20];
int indegs[20], outdegs[20];
int dp[20];
int counts[20];
vector<int> orders[20];

int dfs(int idx, vector<int>& order) {
    order.clear();
    order.push_back(idx);
    if (outdegs[idx] == 0) {
        dp[idx] = counts[idx];
        return dp[idx];
    }
    if (dp[idx] != 0) {
        order = orders[idx];
        return dp[idx];
    }
    int mx = 0;
    for (int next : fwd[idx]) {
        vector<int> order2;
        int res = dfs(next, order2);
        if (res > mx) {
            order.clear();
            order.push_back(idx);
            for (int p : order2) {
                order.push_back(p);
            }
            mx = res;
        }
    }
    dp[idx] = counts[idx] + mx;
    orders[idx] = order;
    return dp[idx];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    for (int i=0; i<n; i++) {
        cin >> counts[i];
    }

    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            int p;
            cin >> p;
            if (p) {
                fwd[i].insert(j);
                indegs[j]++;
                outdegs[i]++;
            }
        }
    }

    int result = 0;
    vector<int> order;
    for (int i=0; i<n; i++) {
        if (indegs[i] == 0) {
            vector<int> order2;
            int r2 = dfs(i, order2);
            if (r2 > result) {
                result = r2;
                order = order2;
            }
        }
    }

    for (int p : order) {
        cout << (p+1) << ' ';
    }
    cout << endl;
    cout << result << endl;
    return 0;
}