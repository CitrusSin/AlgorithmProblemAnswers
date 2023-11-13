#include <bits/stdc++.h>
using namespace std;

const int N = 2e5;
int voc[N], sub[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    map<int, int> lan;
    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        int p;
        cin >> p;
        lan[p]++;
    }

    int m;
    cin >> m;
    for (int i=0; i<m; i++) {
        cin >> voc[i];
    }
    for (int i=0; i<m; i++) {
        cin >> sub[i];
    }

    int max_index = 0, max_v = 0, max_s = 0;
    for (int i=0; i<m; i++) {
        int v = lan[voc[i]], s = lan[sub[i]];
        if (v > max_v) {
            max_index = i;
            max_v = v;
            max_s = s;
        } else if (v == max_v) {
            if (s > max_s) {
                max_index = i;
                max_s = s;
            }
        }
    }
    cout << max_index+1 << endl;
    return 0;
}