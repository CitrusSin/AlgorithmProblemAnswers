#include <iostream>
#include <cinttypes>

using namespace std;
using u64 = uint64_t;

int main() {
    u64 n;
    cin >> n;

    while (n % 2 == 0) {
        n /= 2;
    }
    while (n % 3 == 0) {
        n /= 3;
    }

    cout << (n==1?"Yes":"No") << '\n';
    return 0;
}