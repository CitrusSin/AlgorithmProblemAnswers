#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>

using namespace std;
typedef __int128 ll;

ll llabs(ll x) {
    return (x < 0) ? -x : x;
}

int main() {
    int n, s, len;
    cin >> n >> s >> len;

    string ribbon_data;
    cin >> ribbon_data;

    ll width = (ll)(n-1)*(ll)len + (ll)s, height = (ll)s;

    for (ll j=0; j<height; j++) {
        int last_placed_index = 0;
        for (ll i=0; i<width; i++) {
            bool ribbon_placed = false;
            for (int sqn=0; sqn<n; sqn++) {
                // Detect if the position belongs to (sqn)th ribbon
                if (llabs(i-(s/2+(ll)sqn*(ll)len)) + llabs(j-s/2) <= s/2) {
                    putchar(ribbon_data[sqn]);
                    ribbon_placed = true;
                    last_placed_index = sqn;
                    break;
                }
            }
            if (!ribbon_placed) {
                if (last_placed_index != n-1) {
                    putchar(' ');
                }
            }
        }
        putchar('\n');
    }
    return 0;
}