#include <bits/stdc++.h>

using namespace std;
using u64 = uint64_t;

u64 upow(u64 base, u64 exp) {
    u64 rst = 1;
    for (u64 i = 0; i < exp; i++) rst *= base;
    return rst;
}

int main() {
    u64 a, b;
    cin >> a >> b;

    cout << (upow(a, b)+upow(b, a)) << endl;
    return 0;
}