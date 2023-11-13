#include <bits/stdc++.h>
using namespace std;

vector<double> shortest_path(const vector<vector<pair<int, double>>>& graph, int start) {
    struct node {
        int id;
        double mul;
        node(int id, double mul) : id(id), mul(mul) {}
        bool operator<(const node& n) const {
            return mul < n.mul;
        }
    };

    size_t n = graph.size(), found_count = 0;
    vector<char> found(n, false);
    priority_queue<node> notfound;
    vector<double> muls(n, 0.0);
    notfound.emplace(start, 1.0);
    muls[start] = 1.0;

    while (!notfound.empty() && found_count < n) {
        int source = notfound.top().id;
        notfound.pop();

        found[source] = true;
        found_count++;

        for (const pair<int, double>& fwd : graph[source]) {
            int dest = fwd.first;
            double mul = fwd.second * muls[source];
            if (!found[dest] && mul > muls[dest]) {
                muls[dest] = mul;
                notfound.emplace(dest, mul);
            }
        }
    }

    return muls;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(8);
    
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, double>>> graph(n);
    while (m--) {
        int x, y, z;
        cin >> x >> y >> z;
        double multiplier = (100-z)/100.0;
        x--, y--;
        graph[x].emplace_back(y, multiplier);
        graph[y].emplace_back(x, multiplier);
    }

    int a, b;
    cin >> a >> b;
    a--, b--;

    vector<double> sp = shortest_path(graph, a);
    double result = 100.0/sp[b];

    cout << result << endl;
    return 0;
}