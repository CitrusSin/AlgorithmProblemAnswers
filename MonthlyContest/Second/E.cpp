#include <bits/stdc++.h>
using namespace std;

struct split {
    int l;
    int r;
};

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }

    if (n%2==0) {
        vector<split> splits;
        for (int i=0; i<n; i+=2) {
            if (arr[i]-arr[i+1]==0) {
                splits.push_back(split{i, i+1});
            } else {
                splits.push_back(split{i, i});
                splits.push_back(split{i+1, i+1});
            }
        }
        cout << splits.size() << endl;
        for (split &sp : splits) {
            cout << sp.l+1 << " " << sp.r+1 << endl;
        }
    } else {
        cout << -1 << endl;
    }
    return 0;
}