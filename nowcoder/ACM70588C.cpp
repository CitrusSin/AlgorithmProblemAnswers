#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int p = m == 0 ? 0 : floor(log2(m))+1;
    cout << (p <= n ? "Yes" : "No") << endl;
    return 0;
}