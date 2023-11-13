#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
        a[i]--;
    }

    vector<int> rec;
    unordered_map<int, int> itd;
    int p = 0;
    while (!itd.count(p)) {
        itd[p] = rec.size();
        rec.push_back(p);
        p = a[p];
    }

    cout << (rec.size() - itd[p]) << endl;
    for (int i=itd[p]; i<rec.size(); i++) {
        if (i > itd[p]) cout << ' ';
        cout << (rec[i] + 1);
    }
    cout << endl;
    return 0;
}