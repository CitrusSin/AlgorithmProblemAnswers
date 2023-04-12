#include <iostream>
#include <vector>
#include <memory>
#include <unordered_map>
#include <map>
#include <queue>
#include <stack>
#include <optional>

using namespace std;
using u64 = uint64_t;

struct _AcTrieNode {
    char ch;
    optional<string> end_mark;
    _AcTrieNode* parent;
    unordered_map<char, unique_ptr<_AcTrieNode>> child;

    _AcTrieNode* fail_ptr;

    _AcTrieNode(_AcTrieNode* parent, char ch = '\0')
        : ch(ch), parent(parent), fail_ptr(nullptr) {}
    
    _AcTrieNode() : ch('\0'), parent(nullptr), fail_ptr(this) {}
};

class AcAutomaton {
private:
    _AcTrieNode root_node;
public:
    AcAutomaton() : root_node() {}

    void add_pattern_string(const string& str) {
        _AcTrieNode* np = &root_node;
        auto iter = str.begin(), iter_stop = str.end();

        while (iter != iter_stop) {
            if (!np->child.count(*iter)) {
                // Not found, insert trie node
                np->child[*iter] = make_unique<_AcTrieNode>(np, *iter);
            }
            if (iter+1==iter_stop) {
                np->child[*iter]->end_mark = str;
            }
            np = np->child[*iter].get();
            iter++;
        }
    }

    void build_fail_back() {
        queue<_AcTrieNode*> bfsq;
        for (auto& p : root_node.child) {
            bfsq.push(p.second.get());
        }

        while (!bfsq.empty()) {
            size_t n = bfsq.size();
            while (n--) {
                _AcTrieNode* np = bfsq.front();
                bfsq.pop();
                for (auto& p : np->child) {
                    bfsq.push(p.second.get());
                }

                _AcTrieNode* p = np->parent->fail_ptr;
                while (p) {
                    if (p->child.count(np->ch) && p->child.at(np->ch).get() != np) {
                        np->fail_ptr = p->child.at(np->ch).get();
                        break;
                    } else {
                        if (p == &root_node) {
                            np->fail_ptr = &root_node;
                            break;
                        } else {
                            p = p->fail_ptr;
                        }
                    }
                }
            }
        }
    }

    unordered_map<string, vector<int>> match_all(const string& src) const {
        const _AcTrieNode* p = &root_node;
        unordered_map<string, vector<int>> found_map;
        int idx = 0;
        for (char c : src) {
            while (p != &root_node && !p->child.count(c)) {
                p = p->fail_ptr;
            }
            if (p->child.count(c)) {
                p = p->child.at(c).get();
            }
            if (p->end_mark.has_value()) {
                const _AcTrieNode* p2 = p;
                while (p2 && p2 != &root_node && p2->end_mark.has_value()) {
                    const string& val = p2->end_mark.value();
                    found_map[val].push_back(idx+1-val.size());
                    p2 = p2->fail_ptr;
                }
            }
            idx++;
        }
        return found_map;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    unordered_map<string, int> counts;
    AcAutomaton mt;
    for (int i=0; i<n; i++) {
        string s;
        cin >> s;
        counts[s]++;
        mt.add_pattern_string(s);
    }
    mt.build_fail_back();

    string t;
    cin >> t;
    unordered_map<string, vector<int>> result = mt.match_all(t);

    u64 total = 0;
    for (const pair<string, vector<int>>& p : result) {
        total += counts[p.first];
    }

    cout << total << endl;
    return 0;
}