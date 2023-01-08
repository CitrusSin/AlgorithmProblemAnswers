#include <bits/stdc++.h>

using namespace std;

constexpr int N = 1001;

struct fix_rec {
    int a;
    int b;
    int t;
    bool operator<(const fix_rec &b) const {
        return t < b.t;
    }
    fix_rec(int a, int b, int t) {
        this->a = a;
        this->b = b;
        this->t = t;
    }
};

int sta[N];

int dst_head(int n) {
    if (sta[n] == -1) {
        return n;
    } else {
        int res = dst_head(sta[n]);
        sta[n] = res;
        return res;
    }
}

void dst_merge(int a, int b) {
    a = dst_head(a);
    b = dst_head(b);
    sta[b] = a;
}

int main() {
    memset(sta, 0xff, sizeof(sta));

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<fix_rec> rec_list;
    rec_list.reserve(m);
    for (int i=0; i<m; i++) {
        int a, b, t;
        cin >> a >> b >> t;
        rec_list.emplace_back(--a, --b, t);
    }

    sort(rec_list.begin(), rec_list.end());

    int cnt = n;
    int last_time = 0;
    for (auto& rec : rec_list) {
        if (cnt > 1) {
            if (dst_head(rec.a) != dst_head(rec.b)) {
                dst_merge(rec.a, rec.b);
                cnt--;
                last_time = rec.t;
            }
        } else {
            cout << last_time << endl;
            return 0;
        }
    }
    if (cnt > 1) {
        cout << -1 << endl;
    } else {
        cout << last_time << endl;
    }
    return 0;
}