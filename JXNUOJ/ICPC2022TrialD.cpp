#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    int vocals[n];
    for (int i=0; i<n; i++) {
        cin >> vocals[i];
    }

    int vocal_counts[n];
    for (int i=0; i<n; i++) vocal_counts[i] = 0;
    for (int i=0; i<n; i++) {
        vocal_counts[vocals[i]]++;
    }

    vector<int> vocal_groups(n);
    int vgsize = 0;
    for (int i=0; i<n; i++) {
        if (vocal_counts[i] != 0) {
            vocal_groups[vgsize] = vocal_counts[i];
            vgsize++;
        }
    }
    vocal_groups.resize(vgsize);
    m -= vgsize;

    if (m < 0) {
        cout << "-1" << endl;
        return 0;
    }

    for (int t=0; t<m; t++) {
        int max_count = 0, max_index = 0;
        for (int i=0; i<vocal_groups.size(); i++) {
            if (vocal_groups[i] > max_count) {
                max_count = vocal_groups[i];
                max_index = i;
            }
        }
        int p = max_count / 2;
        int q = max_count - p;
        vocal_groups[max_index] = p;
        vocal_groups.push_back(q);
    }

    int result = 0;
    for (auto iter = vocal_groups.begin(); iter < vocal_groups.end(); iter++) {
        if (*iter > result) {
            result = *iter;
        }
    }

    cout << result << endl;

    return 0;
}