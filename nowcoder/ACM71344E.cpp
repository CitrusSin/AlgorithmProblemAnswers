#include <iostream>
#include <queue>
#include <vector>
#include <list>

using namespace std;
using i64 = int64_t;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    i64 n, q;
    cin >> n >> q;
    
    vector<list<pair<i64, i64>>> graph_forward(n+1);
    for (i64 i=1; i<=n; i++) {
        i64 x, t;
        cin >> x >> t;
        graph_forward[x].emplace_back(i, t);
    }

    vector<i64> delay(n+1, -1);
    delay[0] = 0;
    queue<i64> bfsq;
    bfsq.push(0);
    while (!bfsq.empty()) {
        i64 hd = bfsq.front();
        bfsq.pop();

        for (const auto& [next, t] : graph_forward[hd]) {
            delay[next] = delay[hd] + t;
            bfsq.push(next);
        }
    }

    for (int i=0; i<q; i++) {
        int d, x;
        cin >> d >> x;
        cout << (delay[x]>=0&&delay[x]<=d?"Holiday":"Stay") << '\n';
    }

    return 0;
}