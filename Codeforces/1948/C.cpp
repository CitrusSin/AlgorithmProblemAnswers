#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<unordered_set<int>> graph(2*n);
    array<string, 2> strs;
    cin >> strs[0] >> strs[1];

    for (int i=0; i<n; i++) {
        for (int j=0; j<2; j++) {
            int pos = i * 2 + j;
            
            int p2 = i * 2 + (!j);
            if (strs[!j][i] == '<')
                p2 -= 2;
            else
                p2 += 2;

            if (p2 >= 0 && p2 < 2*n) {
                graph[pos].insert(p2);
            }

            p2 = (i-1) * 2 + j;
            if (strs[j][i-1] == '<')
                p2 -= 2;
            else
                p2 += 2;
            if (p2 != pos && p2 >= 0 && p2 < 2*n) {
                graph[pos].insert(p2);
            }

            p2 = (i+1) * 2 + j;
            if (strs[j][i+1] == '<')
                p2 -= 2;
            else
                p2 += 2;
            if (p2 != pos && p2 >= 0 && p2 < 2*n) {
                graph[pos].insert(p2);
            }
        }
    }

    vector<char> ca(2*n, false);
    ca[0] = true;
    for (int i=0; i<2*n; i++) {
        if (!ca[i]) continue;
        for (int nxt : graph[i]) ca[nxt] = true;
    }

    cout << (ca[2*n-1] ? "YES" : "NO") << '\n';
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