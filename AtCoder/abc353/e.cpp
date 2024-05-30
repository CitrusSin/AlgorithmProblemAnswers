#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;

class StringTree {
private:
    vector<i64> fa, stop_count, depth, mark_stop;
    vector<map<char, i64>> childs;
    vector<char> chr;

    i64 ndc;

    i64 acclaim_node(i64 parent, char ch) {
        if (childs[parent].count(ch)) {
            return childs[parent][ch];
        }

        i64 index = ndc++;

        childs[parent][ch] = index;
        childs.emplace_back();
        fa.push_back(parent);
        chr.push_back(ch);
        mark_stop.push_back(0);
        stop_count.push_back(0);
        depth.push_back(depth[parent]+1);

        return index;
    }

    void append_str(i64 parent, string_view subss) {
        if (subss.size() == 0) {
            mark_stop[parent]++;
            stop_count[parent]++;
            return;
        }

        i64 idx = acclaim_node(parent, subss[0]);
        append_str(idx, subss.substr(1));
        stop_count[parent]++;
    }

    i64 count_copre(i64 node) {
        i64 premstotal = stop_count[node];
        i64 ans = 0;
        for (auto& [chr, child] : childs[node]) {
            ans += (premstotal - stop_count[child]) * stop_count[child];
        }
        ans += (premstotal - mark_stop[node]) * mark_stop[node];
        ans += mark_stop[node] * (mark_stop[node] - 1);
        return ans / 2;
    }
public:
    StringTree() :
        fa(1, -1),
        stop_count(1, 0),
        depth(1, 0),
        childs(1),
        chr(1, '\0'),
        mark_stop(1, 0),
        ndc(1)
    {}

    void add_string(string_view str) {
        append_str(0, str);
    }

    i64 count_total() {
        i64 ans = 0;
        for (i64 i=1; i<ndc; i++) {
            ans += depth[i] * count_copre(i);
        }
        return ans;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    StringTree stt;
    for (int i=0; i<n; i++) {
        string s;
        cin >> s;
        stt.add_string(s);
    }

    cout << stt.count_total() << '\n';
    return 0;
}