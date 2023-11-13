#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    
    vector<int> p1l(n), p2l(n);
    for (int i=0; i<n; i++) {
        int p;
        cin >> p;
        p--;
        p1l[p] = i;
    }
    for (int i=0; i<n; i++) {
        int p;
        cin >> p;
        p--;
        p2l[p] = i;
    }
    
    vector<int> dif_loc(n, 0);
    for (int i=0; i<n; i++) {
        dif_loc[(p1l[i]-p2l[i]+n-1)%n]++;
    }
    int max_val = 0;
    for (int i=0; i<n; i++) {
        max_val = max(max_val, dif_loc[i]);
    }
    cout << max_val << endl;
    return 0;
}