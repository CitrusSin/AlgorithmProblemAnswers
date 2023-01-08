#include <bits/stdc++.h>
using namespace std;

bool check_distance(const vector<int>& distances, int min_distance, int m) {
    for (auto it = distances.begin(); it < distances.end(); it++) {
        int dist = *it;
        while (dist < min_distance) {
            it++;
            if (it == distances.end()) {
                m--;
                return m>=0;
            }
            dist += *it;
            m--;
            if (m < 0) {
                return false;
            }
        }
    }
    return m>=0;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int l, n, m;
    cin >> l >> n >> m;

    if (n == 0) {
        cout << l << endl;
        return 0;
    }

    vector<int> dists;
    int sum = 0;
    for (int i=0; i<n; i++) {
        int p;
        cin >> p;
        if (p > sum) {
            dists.push_back(p-sum);
            sum = p;
        }
    }
    if (l > sum) {
        dists.push_back(l-sum);
    }

    int ld = *min_element(dists.begin(), dists.end()), rd = *max_element(dists.begin(), dists.end());
    while (ld < rd) {
        int mid = ld + (rd-ld)/2;
        if ((rd-ld)%2==1) mid++;
        if (check_distance(dists, mid, m)) {
            ld = mid;
        } else {
            rd = mid - 1;
        }
    }
    cout << ld << endl;
    return 0;
}