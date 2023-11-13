#include <bits/stdc++.h>

using namespace std;

void solve() {
    int m;
    cin >> m;

    vector<int> a;
    for (int i=0; i<m; i++) {
        int num;
        cin >> num;
        a.push_back(num);
    }
    
    vector<int> tags;
    for (vector<int>::iterator iter = a.end()-1; iter >= a.begin(); iter--) {
        vector<int>::iterator num = find(tags.begin(), tags.end(), *iter);
        if (num == tags.end()) {
            tags.insert(tags.begin(), *iter);
        }
    }

    cout << tags.size() << endl;
    for (vector<int>::iterator iter=tags.begin(); iter<tags.end(); iter++) {
        cout << *iter;
        if (iter + 1 == tags.end()) {
            cout << endl;
        } else {
            cout << ' ';
        }
    }
}

int main() {
    int t;
    cin >> t;
    for (int i=0; i<t; i++) {
        solve();
    }
    return 0;
}