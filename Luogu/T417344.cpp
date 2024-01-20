#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    for (int i=0; i<n; i++) {
        int v;
        cin >> v;
        if (i) cout << ' ';
        cout << (v + 1) % n;
    }
    cout << endl;
}