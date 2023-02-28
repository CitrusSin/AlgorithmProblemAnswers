#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    a--;
    b--;

    int k[n];
    for (int i=0; i<n; i++) {
        cin >> k[i];
    }

    if (a == b) {
        cout << 0 << endl;
        return 0;
    }

    queue<int> bfsq;
    bfsq.push(a);
    for (int t=0; t<n; t++) {
        size_t qsize = bfsq.size();
        for (int r=0; r<qsize; r++) {
            int i = bfsq.front();
            bfsq.pop();

            if (i == b) {
                cout << t << endl;
                return 0;
            }

            if (k[i] != 0) {
                if (i - k[i] >= 0) {
                    bfsq.push(i-k[i]);
                }
                if (i + k[i] < n) {
                    bfsq.push(i+k[i]);
                }
                k[i] = 0;
            }
        }
    }
    cout << -1 << endl;
    return 0;
}