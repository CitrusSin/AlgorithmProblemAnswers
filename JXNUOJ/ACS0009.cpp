#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<long long> fibonacci = {3, 5};
    for (;;) {
        long long n = *(fibonacci.end()-1) + *(fibonacci.end()-2);
        if (n <= 2147483647) {
            fibonacci.push_back(n);
        } else break;
    }

    long long i;
    cin >> i;
    if (binary_search(fibonacci.begin(), fibonacci.end(), i)) {
        cout << "yezzz" << endl;
    } else {
        cout << "HeartFireY" << endl;
    }
    return 0;
}