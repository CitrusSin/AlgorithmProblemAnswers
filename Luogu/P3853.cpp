#include <bits/stdc++.h>
using namespace std;

bool judge(const vector<int>& dists, int k, int g) {
    for (int dist : dists) {
        k -= dist / g;
        if (dist % g == 0) k+=1;
        if (k < 0) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int l, n, k;
    cin >> l >> n >> k;

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

    int a = 1, b = l;
    while (a < b) {
        int mid = a + (b-a)/2;
        if (judge(dists, k, mid)) {
            b = mid;
        } else {
            a = mid+1;
        }
    }
    cout << a << endl;
    return 0;
}