#include <bits/stdc++.h>
using namespace std;
using u64 = unsigned long long;

class square_func {
public:
    square_func(int a, int b, int c) {
        set_coefficients(a, b, c);
    }
    inline void set_coefficients(int a, int b, int c) {
        this->a = a;
        this->b = b;
        this->c = c;
    }
    inline u64 operator()(int x) {
        if (res_buffer.count(x)) {
            return res_buffer[x];
        }
        u64 res = u64(a)*x*x + u64(b)*x + u64(c);
        res_buffer[x] = res;
        return res;
    }
    bool operator<(square_func& sec) {
        return (*this)(1) < sec(1);
    }
private:
    int a;
    int b;
    int c;
    unordered_map<int, u64> res_buffer;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<square_func> sqv;
    sqv.reserve(n);
    for (int i=0; i<n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        sqv.emplace_back(a, b, c);
    }

    sort(sqv.begin(), sqv.end());

    vector<int> ptrs(n, 1);
    vector<u64> resv;
    resv.reserve(m);

    int use_count = 0;
    for (int t=0; t<m; t++) {
        pair<u64, int> target = make_pair(sqv[0](ptrs[0]), 0);

        if (use_count == 0 || use_count < n && sqv[use_count](1) < sqv[use_count-1](ptrs[use_count-1])) {
            use_count++;
        }
        for (int i=0; i<use_count; i++) {
            u64 res = sqv[i](ptrs[i]);
            if (res < target.first) {
                target = make_pair(res, i);
            }
        }
        resv.push_back(target.first);
        ptrs[target.second]++;
    }

    for (u64 r : resv) {
        cout << r << " ";
    }
    cout << endl;
    return 0;
}