#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    i64 n, x, y;
    cin >> n >> x >> y;
    
    vector<i64> health(n);
    
    for (i64 i=0; i<n; i++) {
        cin >> health[i];
    }
    
    sort(health.begin(), health.end(), greater<i64>());

    if (y >= x) {
        i64 t = health[0]/y;
        if (health[0] % y != 0) t++;
        cout << t << endl;
        return 0;
    }

    i64 r = x/y;
    if (x%y!=0) r++;
    if (r > n) {
        i64 counter = 0;
        for (i64 i=0; i<n; i++) {
            i64 t = health[i]/x;
            counter += t;
            health[i] -= t*x;
        }
        i64 mx = *max_element(health.begin(), health.end());
        i64 t1 = mx / y;
        if (mx % y != 0) t1++;
        i64 t2 = 0;
        for (i64 i=0; i<n; i++) {
            if (health[i] <= 0) break;
            t2++;
        }
        counter += min(t1, t2);
        cout << counter << endl;
    } else {
        i64 counter = 0;

        i64 li = health[r-1];
        i64 times = li / y;
        li = times * y;
        counter = times;
        for (i64 i=0; i<n; i++) {
            health[i] -= li;
        }

        i64 decrease_counter = 0;
        i64 sub = 0;
        for (;;) {
            for (i64 i=0; i<n; i++) {
                i64 delta = max(min(health[i], (i64)y), 0ll);
                if (delta == 0) break;
                decrease_counter += delta;
            }
            if (decrease_counter >= x) {
                sub += y;
                counter++;
                decrease_counter = 0;
            } else break;
        }
        
        for (i64 i=0; i<n; i++) {
            health[i] -= sub;
            if (health[i] <= 0) break;
            // Calculate time
            i64 t = health[i]/x;
            counter += t;
            health[i] -= t*x;
        }

        i64 mx = *max_element(health.begin(), health.end());
        i64 t1 = mx / y;
        if (mx % y != 0) t1++;
        i64 t2 = 0;
        for (i64 i=0; i<n; i++) {
            if (health[i] <= 0) break;
            t2++;
        }
        counter += min(t1, t2);

        cout << counter << endl;
    }
    return 0;
}