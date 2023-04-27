#include <bits/stdc++.h>

using namespace std;

vector<int> toposort(const vector<set<int>>& graph) {
    int n = graph.size();

    vector<int> result;
    vector<int> indegs(n, 0);
    queue<int> zero_indegs;

    for (int i=0; i<n; i++) {
        for (int fw : graph[i]) {
            indegs[fw]++;
        }
    }
    for (int i=0; i<n; i++) {
        if (indegs[i] == 0) {
            zero_indegs.push(i);
        }
    }

    while (!zero_indegs.empty()) {
        size_t sz = zero_indegs.size();
        while (sz--) {
            int id = zero_indegs.front();
            zero_indegs.pop();
            result.push_back(id);
            for (int fw : graph[id]) {
                indegs[fw]--;
                if (indegs[fw] == 0) {
                    zero_indegs.push(fw);
                }
            }
        }
    }

    return result;
}

void process(const vector<string>& strs, unordered_map<char, int>& ch2id, vector<char>& id2ch, vector<set<int>>& graph) {
    char last_char = 0;
    deque<string> last_strs;
    for (const string& s : strs) {
        if (last_char == 0) {
            last_strs.push_back(s.substr(1));
            last_char = s[0];
            continue;
        }
        if (s[0] != last_char) {
            if (!ch2id.count(last_char)) {
                ch2id[last_char] = id2ch.size();
                id2ch.push_back(last_char);
                graph.push_back(set<int>());
            }
            if (!ch2id.count(s[0])) {
                ch2id[s[0]] = id2ch.size();
                id2ch.push_back(s[0]);
                graph.push_back(set<int>());
            }

            graph[ch2id[last_char]].insert(ch2id[s[0]]);
            last_char = s[0];

            if (last_strs.size() > 1) {
                while (!last_strs.empty() && last_strs.front().empty()) {
                    last_strs.pop_front();
                }
                for (const string& s2 : last_strs) {
                    if (s2.empty()) {
                        throw string("Impossible");
                    }
                }
                process(vector<string>(last_strs.begin(), last_strs.end()), ch2id, id2ch, graph);
            }
            last_strs.clear();

            last_strs.push_back(s.substr(1));
        } else {
            last_strs.push_back(s.substr(1));
        }
    }
    if (last_strs.size() > 1) {
        while (!last_strs.empty() && last_strs.front().empty()) {
            last_strs.pop_front();
        }
        for (const string& s2 : last_strs) {
            if (s2.empty()) {
                throw string("Impossible");
            }
        }
        process(vector<string>(last_strs.begin(), last_strs.end()), ch2id, id2ch, graph);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    unordered_map<char, int> ch2id;
    vector<char> id2ch;
    vector<set<int>> graph;

    int t;
    cin >> t;
    vector<string> strs(t);
    for (int i=0; i<t; i++) {
        cin >> strs[i];
    }

    try {
        process(strs, ch2id, id2ch, graph);

        vector<int> st = toposort(graph);
        if (st.size() < graph.size()) {
            cout << "Impossible" << endl;
        } else {
            array<bool, 26> vis;
            vis.fill(false);

            string order_str;
            for (int p : st) {
                order_str.push_back(id2ch[p]);
                vis[id2ch[p]-'a'] = true;
            }

            for (int i=0; i<26; i++) {
                if (!vis[i]) {
                    order_str.push_back('a'+i);
                }
            }
            cout << order_str << endl;
        }
    } catch (string s) {
        cout << s << endl;
    }

    return 0;
}