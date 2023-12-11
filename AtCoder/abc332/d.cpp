#include <algorithm>
#include <iostream>
#include <vector>
#include <type_traits>

using namespace std;

vector<vector<int>> transpose(const vector<vector<int>>& arr) {
    size_t n = arr.size(), m = arr[0].size();
    vector<vector<int>> ans(m, vector<int>(n));
    for (size_t i=0; i<n; i++) {
        for (size_t j=0; j<m; j++) {
            ans[j][i] = arr[i][j];
        }
    }
    return ans;
}

int64_t invc(const vector<int>& arr) {
    int64_t ans = 0;
    for (size_t i=0; i<arr.size(); i++) {
        for (size_t j=i+1; j<arr.size(); j++) {
            if (arr[i] > arr[j]) ans++;
        }
    }
    return ans;
}

template <typename Iter>
int64_t mgsort_count(Iter first, Iter last) {
    using T = typename iterator_traits<Iter>::value_type;

    size_t n = last - first;

    if (n == 0 || n == 1) {
        return 0;
    } else if (n == 2) {
        Iter p1 = first, p2 = last - 1;
        if (*p1 > *p2) {
            swap(*p1, *p2);
            return 1;
        }
        return 0;
    }

    Iter split = first + (n / 2);
    vector<T> left(first, split), right(split, last);
    int64_t ans = 0;
    ans += mgsort_count(left.begin(), left.end());
    ans += mgsort_count(right.begin(), right.end());

    size_t l = 0, r = 0;
    for (Iter it = first; it != last; it++) {
        if (l == left.size()) {
            *it = right[r++];
        } else if (r == right.size()) {
            *it = left[l++];
        } else {
            if (right[r] < left[l]) {
                *it = right[r++];
                ans += left.size() - l;
            } else {
                *it = left[l++];
            }
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int h, w;
    cin >> h >> w;

    vector<vector<int>> a(h, vector<int>(w)), b(h, vector<int>(w));

    for (int i=0; i<h; i++) {
        for (int j=0; j<w; j++) {
            cin >> a[i][j];
        }
    }
    for (int i=0; i<h; i++) {
        for (int j=0; j<w; j++) {
            cin >> b[i][j];
        }
    }

    vector<int> hp(h), wp(w);
    for (int i=0; i<h; i++) hp[i] = i;
    for (int i=0; i<w; i++) wp[i] = i;
    bool find_solution = false;
    do {
        do {
            vector<vector<int>> a2(h, vector<int>(w)), b2(w, vector<int>(h));

            for (int i=0; i<h; i++) {
                a2[i] = a[hp[i]];
            }
            vector<vector<int>> b3 = transpose(b);
            for (int i=0; i<w; i++) {
                b2[i] = b3[wp[i]];
            }

            bool equals = true;
            for (int i=0; equals && i<h; i++) {
                for (int j=0; equals && j<w; j++) {
                    if (a2[i][j] != b2[j][i]) {
                        equals = false;
                    }
                }
            }
            if (equals) {
                find_solution = true;
            }
        } while (!find_solution && next_permutation(wp.begin(), wp.end()));
    } while (!find_solution && next_permutation(hp.begin(), hp.end()));

    if (!find_solution) {
        cout << -1 << endl;
        return 0;
    }

    int64_t cnt = 0;
    cnt += invc(hp);
    cnt += invc(wp);
    cout << cnt << endl;

    return 0;
}