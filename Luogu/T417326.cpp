#include <algorithm>
#include <iostream>
#include <array>
#include <limits>

using namespace std;

int main() {
    array<int, 3> vals;
    cin >> vals[0] >> vals[1] >> vals[2];
    sort(vals.begin(), vals.end());

    int mindiff = numeric_limits<int>::max();
    int a, b;
    do {
        int z = vals[0] + vals[1], yz = vals[2];
        int v = abs(z - yz);
        if (v < mindiff) {
            a = max(z, yz);
            b = min(z, yz);
            mindiff = v;
        }
    } while (next_permutation(vals.begin(), vals.end()));
    cout << a << " " << b << endl;;
}