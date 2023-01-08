#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1e6+10;

int arr[N];
bool chkd[N] = {};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i=0; i<n; i++) {
            cin >> arr[i];
        }
        
        vector<pair<int, int>> ranges;
        for (int i=0; i<n; i++) {
            if (arr[i] != i+1 && !chkd[i]) {
                int p = i;
                int max_i = -2147483647, min_i = 2147483647;
                while (!chkd[p]) {
                    chkd[p] = true;
                    if (p > max_i) max_i = p;
                    if (p < min_i) min_i = p;
                    p = arr[p]-1;
                }
                ranges.emplace_back(min_i, max_i);
            }
        }

        for (int i=0; i<n; i++) chkd[i] = false;

        sort(ranges.begin(), ranges.end(), [](auto &a, auto &b) {return a.first < b.first;});
        int cnt = 0;
        int last_pos = -1;
        for (pair<int, int> &p : ranges) {
            if (p.second > last_pos) {
                cnt += p.second - max(p.first-1, last_pos);
                last_pos = p.second;
            }
        }

        cout << cnt << endl;
    }
    return 0;
}