#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;

constexpr size_t lowbit(size_t x) {
    return x&((~x)+1);
}

// Notice that T must support plus and minus operation.
template <typename T>
class bit_array {
private:
    vector<T> data;
    vector<T> tr;
public:
    bit_array() {}
    explicit bit_array(size_t n) : data(n), tr(n) {}

    // Notice that resize come up with clearing
    void resize(size_t n) {
        data.resize(n);
        tr.resize(n);
        for (size_t i=0; i<n; i++) data[i] = tr[i] = 0;
    }

    void clear() {
        data.clear();
        tr.clear();
    }
    
    size_t size() const {
        return data.size();
    }

    void add(size_t pos, const T& value) {
        pos++;
        size_t n = size();
        data[pos-1] += value;
        while (pos <= n) {
            tr[pos-1] += value;
            pos += lowbit(pos);
        }
    }

    T prefix_sum(size_t index) const {
        T sum = 0;
        index++;
        while (index) {
            sum += tr[index-1];
            index -= lowbit(index);
        }
        return sum;
    }

    const T& get_value(size_t pos) const {
        return data[pos];
    }

    void set_value(size_t pos, const T& value) {
        T diff = value - get_value(pos);
        add(pos, diff);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    
    bit_array<i64> arr(n);
    i64 last = 0;
    for (int i=0; i<n; i++) {
        i64 p;
        cin >> p;
        arr.add(i, p-last);
        last = p;
    }

    while (m--) {
        int op;
        cin >> op;
        if (op == 1) {
            i64 x, y, k;
            cin >> x >> y >> k;
            arr.add(x-1, k);
            if (y < n) arr.add(y, -k);
        } else if (op == 2) {
            size_t x;
            cin >> x;
            x--;
            cout << arr.prefix_sum(x) << endl;
        }
    }
    return 0;
}