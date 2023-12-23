#include <functional>
#include <iostream>
#include <set>
#include <vector>

using namespace std;
using i64 = int64_t;

const i64 MOD = 998244353;

i64 qpow(i64 base, i64 exp, i64 mod) {
    i64 r = base % mod, rst = 1;
    while (exp) {
        if (exp & 1) rst = rst * r % mod;
        r = r * r % mod;
        exp >>= 1;
    }
    return rst;
}

i64 inv(i64 base, i64 mod) {
    return qpow(base, mod-2, mod);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int h, w;
    cin >> h >> w;

    vector<vector<char>> s(h, vector<char>(w));
    for (int i=0; i<h; i++) {
        for (int j=0; j<w; j++) {
            cin >> s[i][j];
        }
    }

    vector<vector<int>> idc(h, vector<int>(w, -1));
    function<void(int, int, int)> dfsp = [&](int x, int y, int id) {
        constexpr array<int, 4> dx{1, 0, 0, -1},
                                dy{0, 1, -1, 0};
        idc[x][y] = id;
        for (int d=0; d<4; d++) {
            int x2 = x + dx[d], y2 = y + dy[d];
            if (x2 < 0 || x2 >= h || y2 < 0 || y2 >= w) continue;
            if (s[x2][y2] == s[x][y] && idc[x2][y2] == -1) {
                dfsp(x2, y2, id);
            }
        }
    };
    int inc_id = 0;
    for (int i=0; i<h; i++) {
        for (int j=0; j<w; j++) {
            if (s[i][j] == '#' && idc[i][j] == -1) {
                dfsp(i, j, inc_id++);
            }
        }
    }


    array<i64, 5> pcnts;
    pcnts.fill(0);
    for (int i=0; i<h; i++) {
        for (int j=0; j<w; j++) {
            if (s[i][j] == '.') {
                constexpr array<int, 4> dx{1, 0, 0, -1},
                                    dy{0, 1, -1, 0};
                set<int> regs;
                for (int d=0; d<4; d++) {
                    int i2 = i + dx[d], j2 = j + dy[d];
                    if (i2 < 0 || i2 >= h || j2 < 0 || j2 >= w) continue;
                    if (idc[i2][j2] != -1) regs.insert(idc[i2][j2]);
                }

                pcnts[regs.size()]++;
            }
        }
    }

    i64 expect = 0, total = 0;
    for (int i=0; i<5; i++) {
        expect += pcnts[i] * (inc_id-i+1) % MOD;
        expect %= MOD;
        total += pcnts[i] % MOD;
        total %= MOD;
    }

    expect *= inv(total, MOD);
    expect %= MOD;

    cout << expect << endl;
    
    return 0;
}