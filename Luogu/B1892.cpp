#include <bits/stdc++.h>

using namespace std;

class dset {
public:
    dset(int n);
    void init(int n);
    int head(int x) const;
    void merge(int a, int b);
    bool query(int a, int b) const;
    int count() const;
private:
    mutable vector<int> arr;
    int cnt;
};

dset::dset(int n) {
    init(n);
}

void dset::init(int n) {
    arr.resize(n, -1);
    cnt = n;
}

int dset::head(int x) const {
    if (arr[x] == -1) return x;
    int res = head(arr[x]);
    arr[x] = res;
    return res;
}

void dset::merge(int a, int b) {
    a = head(a);
    b = head(b);
    if (a != b) {
        arr[b] = a;
        cnt--;
    }
}

bool dset::query(int a, int b) const {
    return head(a) == head(b);
}

int dset::count() const {
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector< vector<int> > enemy_map(n);
    dset friend_set(n);

    while (m--) {
        string opt;
        int p, q;
        cin >> opt >> p >> q;
        p--, q--;
        switch (opt[0]) {
        case 'F':
            friend_set.merge(p, q);
            break;
        case 'E':
            enemy_map[p].push_back(q);
            enemy_map[q].push_back(p);
            break;
        }
    }

    for (const vector<int>& g : enemy_map) {
        size_t s = g.size();
        for (int i=1; i<s; i++) {
            friend_set.merge(g[i-1], g[i]);
        }
    }

    cout << friend_set.count() << endl;
    return 0;
}