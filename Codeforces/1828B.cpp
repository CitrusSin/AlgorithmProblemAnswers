#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
    return b?gcd(b, a%b):a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> permu(n);
        for (int i=0; i<n; i++) {
            cin >> permu[i];
            permu[i]--;
        }
        vector<char> vis(n, false);
        int max_k = 0;
        for (int u=0; u<n; u++) {
            if (vis[u]) continue;
            vis[u] = true;
            vector<int> swap_loop;
            swap_loop.push_back(u);
            for (int i=permu[u]; i!=u; i=permu[i]) {
                vis[i] = true;
                swap_loop.push_back(i);
            }
            sort(swap_loop.begin(), swap_loop.end());
            for (int i=0; i<swap_loop.size()-1; i++) {
                max_k = gcd(max_k, swap_loop[i+1]-swap_loop[i]);
                if (max_k == 1) break;
            }
            if (max_k == 1) break;
        }
        cout << max_k << endl;
    }
    return 0;
}