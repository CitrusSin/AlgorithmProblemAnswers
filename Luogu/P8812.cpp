#include <bits/stdc++.h>
using namespace std;
using u64 = unsigned long long;

struct store {
    int s, t, p;
    unordered_map<int, int> goods;
};

store read_store(istream& ist) {
    store st;
    int c;
    ist >> st.s >> st.t >> st.p >> c;
    while (c--) {
        int a, b;
        ist >> a >> b;
        st.goods[a] = b;
    }
    return st;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<store> stores;
    vector<int> discrete_time;
    for (int i=0; i<n; i++) {
        store st = read_store(cin);
        discrete_time.push_back(st.s);
        discrete_time.push_back(st.t);
        stores.push_back(std::move(st));
    }
    sort(discrete_time.begin(), discrete_time.end());
    discrete_time.erase(unique(discrete_time.begin(), discrete_time.end()), discrete_time.end());

    unordered_map<int, int> discrete_map;
    int dlen = discrete_time.size();
    for (int i=0; i<dlen; i++) {
        discrete_map[discrete_time[i]] = i;
    }

    for (store& st : stores) {
        st.s = discrete_map[st.s];
        st.t = discrete_map[st.t];
    }

    vector<int> good_prices(n);

    for (int i=0; i<n; i++) {
        int price = 2147483647;
        for (store &st : stores) {
            if (st.goods.count(i+1)) {
                price = min(price, st.goods[i+1]);
            }
        }
        good_prices[i] = price;
    }

    u64 min_price = accumulate(good_prices.begin(), good_prices.end(), 0ull);
    for (int t=0; t<dlen; t++) {
        for (store& st : stores) {
            if (st.s == t) {
                for (const pair<int, int>& gvp : st.goods) {
                    int new_price = gvp.second * st.p / 100;
                    if (new_price < good_prices[gvp.first-1]) {
                        good_prices[gvp.first-1] = new_price;
                    }
                }
            } else if (st.t == t) {
                for (const pair<int, int>& gvp : st.goods) {
                    // Recalculate good values
                    int price = 2147483647;
                    for (store& st2 : stores) {
                        if (st2.goods.count(gvp.first)) {
                            int nprice = st2.goods[gvp.first];
                            if (t >= st2.s && t < st2.t) {
                                nprice = nprice * st2.p / 100;
                            }
                            price = min(price, nprice);
                        }
                    }
                    good_prices[gvp.first-1] = price;
                }
            }
        }
        u64 pr = accumulate(good_prices.begin(), good_prices.end(), 0ull);
        if (pr < min_price) min_price = pr;
    }

    cout << min_price << endl;
    return 0;
}