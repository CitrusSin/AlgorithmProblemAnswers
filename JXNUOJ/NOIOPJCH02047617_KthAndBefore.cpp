#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    long long array[n];
    for (int i=0; i<n; i++) {
        cin >> array[i];
    }
    sort(array, array+n, [](long long a, long long b) {return a>b;});

    int k;
    cin >> k;

    for (int i=0; i<k; i++) {
        cout << array[i] << endl;
    }
    return 0;
}