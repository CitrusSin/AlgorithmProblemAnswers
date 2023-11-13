#include <bits/stdc++.h>
using namespace std;
using u64 = unsigned long long;


vector<vector<int>> dfs_net;
vector<u64> mem;

u64 dfs(int origin) {
    if (mem[origin]>0) {
        return mem[origin];
    } else {
        if (dfs_net[origin].empty()) {
            mem[origin] = 1;
            return 1;
        }

        u64 cnt = 0;
        for (int node : dfs_net[origin]) {
            cnt += dfs(node);
        }
        mem[origin] = cnt;
        return cnt;
    }
}

void set_dfs_net(const vector<vector<int>>& net) {
    dfs_net = net;
    mem.clear();
    mem.assign(dfs_net.size(), 0);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> origins(n, 1);
    vector<vector<int>> net(n, vector<int>(0));

    while (m--) {
        int a, b;
        cin >> a >> b;
        net[a-1].push_back(b-1);
        origins[b-1] = 0;
    }

    set_dfs_net(net);

    u64 cnt = 0;
    for (int k=0; k<n; k++) {
        if (origins[k] && !net[k].empty()) {
            cnt += dfs(k);
        }
    }

    cout << cnt << endl;
    return 0;
}