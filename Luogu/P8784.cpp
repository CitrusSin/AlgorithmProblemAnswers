#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;

const i64 MOD = 1e9+7;

struct mat4mod {
    array<array<i64, 4>, 4> data;

    mat4mod(const initializer_list<initializer_list<int>>& l) {
        int i=0;
        for (const auto& p : l) {
            int j=0;
            for (int p2 : p) {
                data[i][j] = p2;
                j++;
            }
            i++;
        }
    }

    mat4mod(array<array<i64, 4>, 4> &&val) : data(move(val)) {}
    mat4mod(i64 val) {
        for (int i=0; i<4; i++) {
            for (int j=0; j<4; j++) {
                data[i][j] = (i==j)?val:0;
            }
        }
    }

    mat4mod operator*(const mat4mod& m2) {
        array<array<i64, 4>, 4> arr;
        for (int i=0; i<4; i++) {
            for (int j=0; j<4; j++) {
                arr[i][j] = 0;
                for (int k=0; k<4; k++) {
                    arr[i][j] += (data[i][k]*m2.data[k][j])%MOD;
                    arr[i][j] %= MOD;
                }
            }
        }
        return arr;
    }
};

mat4mod qpow(mat4mod base, int exp) {
    if (exp == 0) {
        return mat4mod(1);
    } else if (exp == 1) {
        return base;
    }

    mat4mod b2 = qpow(base, exp/2);
    if (exp%2==0) {
        return b2*b2;
    } else {
        return b2*b2*base;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    // f(n) = f(n-1)+2f(n-2)+f(n-3)+f(n-4)
    mat4mod mat = 
    {{1, 2, 1, 1},
     {1, 0, 0, 0},
     {0, 1, 0, 0},
     {0, 0, 1, 0}};

    mat4mod fin = qpow(mat, n);

    i64 res = 0;
    res += (fin.data[3][0]*5)%MOD;
    res %= MOD;
    res += (fin.data[3][1]*2)%MOD;
    res %= MOD;
    res += (fin.data[3][2])%MOD;
    res %= MOD;
    res += (fin.data[3][3])%MOD;
    res %= MOD;

    cout << res << endl;
    return 0;
}