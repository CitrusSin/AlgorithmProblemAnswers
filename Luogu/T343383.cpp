#include <bits/stdc++.h>

using namespace std;

struct Trie {
    char val;
    bool stop_mark;
    array<unique_ptr<Trie>, 8> childs;

    Trie() : val('\0'), stop_mark(false) {
        for (int i=0; i<8; i++) {
            childs[i] = nullptr;
        }
    }
    Trie(char c, bool stmk = false) : val(c), stop_mark(stmk) {
        for (int i=0; i<8; i++) {
            childs[i] = nullptr;
        }
    }

    bool add_str(const string& str, int idx = 0) {
        int n = str.size();
        if (n == 0) return false;

        char c = str[idx];
        bool bm = stop_mark;
        if (childs[c-'0'] == nullptr) {
            childs[c-'0'] = make_unique<Trie>(c);
        }
        if (idx >= n-1) {
            childs[c-'0']->stop_mark = true;
            for (int i=0; i<7; i++) {
                if (childs[c-'0']->childs[i] != nullptr) {
                    return true;
                }
            }
            return stop_mark;
        } else {
            return childs[c-'0']->add_str(str, idx+1) || stop_mark;
        }
    }

    bool check() {
        if (stop_mark) {
            for (auto &ptr : childs) {
                if (ptr != nullptr) {
                    return false;
                }
            }
            return true;
        }
        for (auto &ptr : childs) {
            if (ptr != nullptr && !(ptr->check())) return false;
        }
        return true;
    }
};

void solve() {
    Trie tr;
    string s;

    bool result = false;
    while (cin >> s, s != "9") {
        if (!result) {
            bool rst = tr.add_str(s);
            if (rst) result = true;
        }
    }

    cout << (result?"yes":"no") << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    while (cin) {
        solve();
    }
    return 0;
}