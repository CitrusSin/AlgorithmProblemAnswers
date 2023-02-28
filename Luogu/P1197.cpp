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

    vector< pair<int, int> > tunnels;
    vector< vector<int> > forward_table(n);
    while (m--) {
        int x, y;
        cin >> x >> y;
        tunnels.emplace_back(x, y);
        forward_table[x].push_back(y);
        forward_table[y].push_back(x);
    }

    int k;
    cin >> k;

    vector<int> attack_list;
    set<int> attack_set;

    for (int i=0; i<k; i++) {
        int id;
        cin >> id;
        attack_list.push_back(id);
        attack_set.insert(id);
    }

    dset connects(n);
    for (const pair<int, int>& c : tunnels) {
        if (!attack_set.count(c.first) && !attack_set.count(c.second)) {
            connects.merge(c.first, c.second);
        }
    }

    stack<int> rev_st;
    int attacked_cnt = k;
    for (auto it = attack_list.crbegin(); it != attack_list.crend(); it++) {
        rev_st.push(connects.count() - attacked_cnt);
        
        int id = *it;
        attack_set.erase(id);
        for (int fw : forward_table[id]) {
            if (!attack_set.count(fw)) {
                connects.merge(id, fw);
            }
        }

        attacked_cnt--;
    }
    rev_st.push(connects.count());

    while (!rev_st.empty()) {
        cout << rev_st.top() << endl;
        rev_st.pop();
    }
    return 0;
}