#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<pair<int, int>> ps(n);
    for (int i=0; i<n; i++) {
        cin >> ps[i].first;
    }
    for (int i=0; i<n; i++) {
        cin >> ps[i].second;
    }

    sort(ps.begin(), ps.end());

    int i=0, j=0;

    int i2=i+1, j2=j, i3=i, j3=j+1;
    if (i2 == j2) i2++;
    if (i3 == j3) j3++;
    

    return 0;
}