#include <bits/stdc++.h>
using namespace std;

struct competitor {
    int index;
    int score;
    int power;
};

bool comparator(const competitor& c1, const competitor& c2) {
    if (c1.score != c2.score) {
        return c1.score > c2.score;
    } else {
        return c1.index < c2.index;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, r, q;
    cin >> n >> r >> q;

    vector<competitor> co(2*n);
    for (int i=0; i<2*n; i++) {
        co[i].index = i;
        cin >> co[i].score;
    }
    for (int i=0; i<2*n; i++) {
        cin >> co[i].power;
    }

    sort(co.begin(), co.end(), comparator);

    vector<competitor> win, lose;
    win.reserve(n);
    lose.reserve(n);
    while (r--) {
        for (int i=0; i<n; i++) {
            if (co[2*i].power > co[2*i+1].power) {
                co[2*i].score++;
                win.push_back(co[2*i]);
                lose.push_back(co[2*i+1]);
            } else {
                co[2*i+1].score++;
                win.push_back(co[2*i+1]);
                lose.push_back(co[2*i]);
            }
        }
        auto l = win.begin(), r = lose.begin();
        auto le = win.end(), re = lose.end();
        int ci = 0;
        while (l < le && r < re) {
            if (comparator(*l, *r)) {
                co[ci++] = *l++;
            } else {
                co[ci++] = *r++;
            }
        }
        while (l < le) {
            co[ci++] = *l++;
        }
        while (r < re) {
            co[ci++] = *r++;
        }

        win.clear();
        lose.clear();
        win.reserve(n);
        lose.reserve(n);
    }

    cout << co[q-1].index+1 << endl;
    return 0;
}