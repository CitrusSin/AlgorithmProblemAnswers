#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>

using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> stacks(n);
    for (int i=0; i<n; i++) {
        cin >> stacks[i];
    }

    sort(stacks.begin(), stacks.end(), std::greater<int>());

    // sg max 2
    // sg(i, d) = stacks[i-1] <= d ? sg(i-1, d) : mex{sg(i-1, d), sg(i, d+1)}
    vector<vector<uint8_t>> sg(n+1, vector<uint8_t>(stacks[0]+1, 0));
    for (int i=1; i<=n; i++) {
        for (int d=stacks[0]; d>=0; d--) {
            if (stacks[i-1] <= d) {
                sg[i][d] = sg[i-1][d];
            } else {
                uint8_t mex = 0;
                while (sg[i-1][d] == mex || sg[i][d+1] == mex) mex++;
                sg[i][d] = mex;
            }
        }
    }

    uint8_t fin = sg[n][0];
    cout << (fin ? "Alice" : "Bob") << '\n';
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