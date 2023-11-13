#include <bits/stdc++.h>

using namespace std;

class adt {
public:
    explicit adt(int n);

    void reset(int n);
    int head(int x) const;
    bool query(int a, int b) const;
    bool merge(int a, int b);
    int count() const;
private:
    mutable vector<int> dst;
    int set_count;
};

adt::adt(int n) {
    reset(n);
}

void adt::reset(int n) {
    dst.resize(n, -1);
    set_count = n;
}

int adt::head(int x) const {
    if (dst[x] == -1) {
        return x;
    }
    int rst = head(dst[x]);
    dst[x] = rst;
    return rst;
}

bool adt::query(int a, int b) const {
    return head(a) == head(b);
}

bool adt::merge(int a, int b) {
    a = head(a);
    b = head(b);
    if (a != b) {
        dst[b] = a;
        set_count--;
        return true;
    }
    return false;
}

int adt::count() const {
    return set_count;
}

vector<tuple<int, int, int>> kruskal(
    const vector<tuple<int, int, int>>& graph_sides, size_t n, int& sum
) {
    using tup = tuple<int, int, int>;
    struct comp {
        bool operator()(const tup& a, const tup& b) const {
            return get<2>(a) > get<2>(b);
        }
    };

    priority_queue<tup, vector<tup>, comp> pq;
    for (const tup& t : graph_sides) {
        pq.push(t);
    }

    sum = 0;
    adt s(n);
    vector<tuple<int, int, int>> result;
    result.reserve(n-1);
    while (!pq.empty() && s.count() > 1) {
        tup side = pq.top();
        pq.pop();

        if (s.merge(get<0>(side), get<1>(side))) {
            sum += get<2>(side);
            result.push_back(side);
        }
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<tuple<int, int, int>> graph_sides;
    int total = 0;
    graph_sides.reserve(m);
    while (m--) {
        int x, y, z;
        cin >> x >> y >> z;
        x--, y--;
        graph_sides.emplace_back(x, y, z);
        total += z;
    }

    int sum = 0;
    kruskal(graph_sides, n, sum);
    cout << total-sum << endl;
    return 0;
}