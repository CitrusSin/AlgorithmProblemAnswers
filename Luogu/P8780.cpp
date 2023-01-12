#include <bits/stdc++.h>

using namespace std;
using u64 = unsigned long long;

int main() {
    u64 a, b, n;
    cin >> a >> b >> n;

    u64 day_cnt = 0;

    u64 weekly = a*5+b*2;
    day_cnt += (n/weekly)*7;
    n = n % weekly;

    int rc;
    for (rc=0; rc<5; rc++) {
        day_cnt++;
        if (n < a) {
            break;
        }
        n -= a;
    }
    if (rc == 5) {
        for (rc=0; rc<2; rc++) {
            day_cnt++;
            if (n < b) {
                break;
            }
            n -= b;
        }
    }

    cout << day_cnt << endl;
    return 0;
}