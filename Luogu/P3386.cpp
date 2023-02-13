#include <bits/stdc++.h>

using namespace std;

struct graph_match {
    vector<int> left, right;
    graph_match(size_t n, size_t m);
};

graph_match::graph_match(size_t n, size_t m) : left(n, -1), right(m, -1) {}

class graph {
public:
    graph(size_t n, size_t m);

    void connect(int a, int b);
    graph_match find_maximum_match(int& count) const;
private:
    vector<set<int>> left, right;

    bool find_extern_path(
        int right_node,
        graph_match& match, 
        vector<char>& mark_left,
        vector<char>& mark_right
    ) const;
};

graph::graph(size_t n, size_t m) : left(n), right(m) {}

void graph::connect(int a, int b) {
    left[a].insert(b);
    right[b].insert(a);
}

graph_match graph::find_maximum_match(int& count) const {
    size_t n = left.size(), m = right.size();
    graph_match match(n, m);
    int cnt = 0;
    for (int i=0; i<n; i++) {
        bool found = false;
        for (int r : left[i]) {
            vector<char> mark_left(n, false), mark_right(m, false);
            if (find_extern_path(r, match, mark_left, mark_right)) {
                match.right[r] = i;
                match.left[i] = r;
                found = true;
                break;
            }
        }
        if (found) cnt++;
    }
    count = cnt;
    return match;
}

bool graph::find_extern_path(
    int right_node,
    graph_match& match,
    vector<char>& mark_left,
    vector<char>& mark_right
) const {
    size_t n = left.size(), m = right.size();

    if (mark_right[right_node]) return false;
    if (match.right[right_node] == -1) {
        return true;
    }
    mark_right[right_node] = true;

    int left_node = match.right[right_node];
    mark_left[left_node] = true;
    for (int r2 : left[left_node]) {
        if (mark_right[r2] || r2 == match.left[left_node]) {
            continue;
        }
        bool res = find_extern_path(r2, match, mark_left, mark_right);
        if (res) {
            match.right[r2] = left_node;
            match.left[left_node] = r2;
            return true;
        }
    }
    mark_left[left_node] = false;

    mark_right[right_node] = false;
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, e;
    cin >> n >> m >> e;

    graph g(n, m);
    while (e--) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g.connect(u, v);
    }

    int count = 0;
    g.find_maximum_match(count);
    cout << count << endl;
    return 0;
}