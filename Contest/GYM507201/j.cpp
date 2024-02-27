#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> count(n);
    for (int i=0; i<n-1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        count[u]++;
        count[v]++;
    }

    int tc = 0;
    for (int i=0; i<n; i++) {
        if (count[i] > 1) {
            tc++;
        }
    }
    if (tc == 0) tc++;

    cout << (tc % 2 ? "Bob" : "Alice") << endl;
    return 0;
}