#include <bits/stdc++.h>
#include <limits>

using namespace std;
using i64 = int64_t;

i64 A, B, C, D, E, F, G, P, X1, X2, Y1, Y2;

i64 calculate(i64 x, i64 y) {
    array<i64, 4> xs, ys;
    xs[0] = 1; ys[0] = 1;
    for (int i=1; i<4; i++) {
        xs[i] = xs[i-1] * x % P;
        ys[i] = ys[i-1] * y % P;
    }

    i64 ans = 0;
    ans += A * xs[3];
    ans += B * ys[3];
    ans %= P;
    ans += C * xs[2] % P * ys[1] % P;
    ans %= P;
    ans += D * xs[1] % P * ys[2] % P;
    ans %= P;
    ans += E * x % P * y % P;
    ans %= P;
    ans += F * x % P;
    ans %= P;
    ans += G * y % P;
    ans %= P;

    return ans;
}

int main() {
    cin >> A >> B >> C >> D >> E >> F >> G >> P >> X1 >> X2 >> Y1 >> Y2;
    i64 max_val = numeric_limits<i64>::min();
    for (i64 x = X1; x <= X2; x++) {
        for (i64 y = Y1; y <= Y2; y++) {
            max_val = max(max_val, calculate(x, y));
        }
    }

    cout << max_val << endl;
}