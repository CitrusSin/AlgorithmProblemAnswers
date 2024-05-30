#include <iostream>
#include <vector>
#include <string>
#include <string_view>
#include <cstdint>

using namespace std;


pair<vector<int64_t>, vector<int64_t>> manacher(string_view sv) {
    struct CharVal {
        uint8_t type;
        char ch;

        CharVal(char ch) : type(0), ch(ch) {}
        CharVal(int type) : type(type), ch('\0') {}

        bool operator==(const CharVal& cv2) const {
            if (type != cv2.type) return false;
            if (type == 0) {
                return ch == cv2.ch;
            }
            return true;
        }
    };

    auto s = [&](int64_t index) -> CharVal {
        if (index == 0) return CharVal(1);
        if (index == 2*sv.size()) return CharVal(1);
        index--;
        if (index % 2 == 0) return CharVal(sv[index/2]); else return CharVal(1);
    };

    int64_t n = 2 * sv.size() + 1;

    vector<int64_t> p(n, 0);
    int64_t ct = 0;
    for (int64_t i = 0; i < n; i++) {
        if (i <= ct + p[ct]) p[i] = min(ct + p[ct] - i, p[ct - (i - ct)]);
        while (0 <= i - p[i] - 1 && i + p[i] + 1 < n && s(i - p[i] - 1) == s(i + p[i] + 1)) {
            p[i]++;
        }
        if (i + p[i] > ct + p[ct]) ct = i;
    }

    vector<int64_t> p1(n/2), p2(n - 2 - n/2);
    for (int64_t i=0; i<n/2; i++) p1[i] = p[2*i+1];
    for (int64_t i=0; i<(n - 2 - n/2); i++) p2[i] = p[2*i+2];

    return make_pair(p1, p2);
}

int main() {
    string s;
    cin >> s;

    auto [p1, p2] = manacher(s);

    cout << "p1: \n";
    for (auto v : p1) {
        cout << v << ' ';
    }
    cout << '\n';

    cout << "p2: \n";
    for (auto v : p2) {
        cout << v << ' ';
    }
    cout << '\n';
    return 0;
}