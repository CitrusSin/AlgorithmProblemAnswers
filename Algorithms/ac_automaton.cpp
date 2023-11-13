#include <iostream>
#include <vector>
#include <memory>
#include <unordered_map>
#include <map>
#include <queue>
#include <stack>
#include <optional>

using namespace std;

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

    map<string, vector<int>> match_all(const string& src) const {
        const _AcTrieNode* p = &root_node;
        map<string, vector<int>> found_map;
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
    AcAutomaton test;
    test.add_pattern_string("he");
    test.add_pattern_string("her");
    test.add_pattern_string("say");
    test.add_pattern_string("she");
    test.add_pattern_string("shr");
    test.build_fail_back();

    map<string, vector<int>> res = test.match_all("hesayhersheshe");
    return 0;
}