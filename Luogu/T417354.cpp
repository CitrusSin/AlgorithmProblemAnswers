#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    
    vector<size_t> as, bs;
    size_t ap = 0, bp = 0;
    while (ap != string::npos) {
        size_t p = s.find("Genshin", ap);
        if (p == string::npos) {
            ap = p;
        } else {
            as.push_back(p);
            ap = p + 1;
        }
    }
    while (bp != string::npos) {
        size_t p = s.find("player", bp);
        if (p == string::npos) {
            bp = p;
        } else {
            bs.push_back(p);
            bp = p + 1;
        }
    }

    size_t total = 0;
    for (size_t gp : as) {
        size_t cnt = bs.end() - lower_bound(bs.begin(), bs.end(), gp+1);
        total += cnt;
    }

    cout << total << endl;
}