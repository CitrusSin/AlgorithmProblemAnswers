#include <bits/stdc++.h>

using namespace std;
using u64 = uint64_t;

constexpr size_t lowbit(size_t n) {
    return n&((~n)+1);
}

template <typename T>
class bit_array {
private:
    vector<T> data;
    vector<T> tr;
public:
    bit_array() {}
    explicit bit_array(size_t size) : data(size), tr(size) {}

    void add(size_t pos, const T& increment) {
        pos++;
        data[pos-1] += increment;
        size_t n = size();
        while (pos <= n) {
            tr[pos-1] += increment;
            pos += lowbit(pos);
        }
    }

    T prefix_sum(size_t len) const {
        T sum = 0;
        while (len) {
            sum += tr[len-1];
            len -= lowbit(len);
        }
        return sum;
    }

    size_t size() const {
        return data.size();
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    bit_array<u64> arr(n);
    while (m--) {
        string op;
        u64 a, b;
        cin >> op >> a >> b;
        if (op == "x") {
            arr.add(a-1, b);
        } else if (op == "y") {
            a--;
            cout << (arr.prefix_sum(b)-arr.prefix_sum(a)) << endl;
        }
    }
    return 0;
}