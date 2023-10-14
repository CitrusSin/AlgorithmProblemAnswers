#include <iostream>
#include <vector>
#include <string>
#include <string_view>

using namespace std;

bool compare(std::string_view sv1, std::string_view sv2) {
    if (sv1 == sv2) return true;

    size_t n = sv1.size(), m = sv2.size();

    size_t dif = 0;
    if (n == m) {
        for (size_t i=0; i<n && dif < 2; i++) {
            if (sv1[i] != sv2[i]) dif++;
        }
        return dif < 2;
    }
    if (n < m) {
        std::swap(sv1, sv2);
        std::swap(n, m);
    }
    for (size_t i=0, j=0; i<n && dif < 2; i++, j++) {
        while (sv1[i] != sv2[j] && dif < 2) {
            i++;
            dif++;
        }
    }
    return dif < 2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    string tr;
    cin >> n >> tr;

    vector<int> indices;
    indices.reserve(n);

    for (int i=0; i<n; i++) {
        string t;
        cin >> t;

        if (compare(tr, t)) {
            indices.push_back(i);
        }
    }

    cout << indices.size() << '\n';
    for (int x : indices) {
        cout << (x+1) << ' ';
    }
    cout << '\n';
    return 0;
}