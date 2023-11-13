#include <bits/stdc++.h>
using namespace std;

struct trie_node {
    char ch;
    int end_cnt;
    vector< shared_ptr<trie_node> > fwd;

    trie_node(char c) {
        ch = c;
        end_cnt = 0;
        fwd.resize(10, nullptr);
    };
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        trie_node root('\0');
        root.ch = 0;

        bool sig = true;
        for (int i=0; i<n; i++) {
            string s;
            cin >> s;
            trie_node *nptr = &root;
            for (char c : s) {
                if (nptr->fwd[c-'0'] == nullptr) {
                    nptr->fwd[c-'0'].reset(new trie_node(c));
                    nptr->fwd[c-'0']->ch = c;
                }
                nptr = nptr->fwd[c-'0'].get();
                if (nptr->end_cnt != 0) {
                    sig = false;
                }
            }
            nptr->end_cnt++;
        }
        if (sig) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}