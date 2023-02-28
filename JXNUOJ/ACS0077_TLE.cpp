#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    unsigned long long n;
    cin >> n;

    for (unsigned long long i=0; i<=n; i++) {
        if ((i | n) == n) {
            cout << i << endl;
        }
    }
    return 0;
}