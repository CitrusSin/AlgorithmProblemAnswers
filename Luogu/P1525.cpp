#include <bits/stdc++.h>
using namespace std;

struct conflict {
    int crime_a;
    int crime_b;
    int amp;
    conflict(int a, int b, int c) {
        crime_a = a;
        crime_b = b;
        amp = c;
    }
    bool operator<(const conflict& c2) const {
        return amp < c2.amp;
    }
    bool operator>(const conflict& c2) const {
        return amp > c2.amp;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> crim_sgn(n, 1);
    vector<conflict> confs;

    confs.reserve(m);
    for (int i=0; i<m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        confs.emplace_back(a, b, c);
    }

    sort(confs.begin(), confs.end(), greater<conflict>());

    vector<int> a, b;
    a.reserve(n);
    b.reserve(n);
    for (conflict& conf : confs) {
        
    }
    return 0;
}