#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
        if (a[i] > 0) a[i]--;
    }

    vector<char> mark(n, false);
    int cnt = 0, i=0;
    for (i=0; i<n && cnt<n; i++) {
        int r = i;
        while (r != -1 && !mark[r]) {
            mark[r] = true;
            cnt++;
            r = a[r];
        }
    }
    i--;

    int r = i;
    stack<int> seq;
    while (r != -1) {
        seq.push(r);
        r = a[r];
    }

    bool flag = false;
    while (!seq.empty()) {
        int v = seq.top();
        if (!flag) flag = true; else cout << ' ';
        cout << (v+1);
        seq.pop();
    }
    cout << endl;
    return 0;
}