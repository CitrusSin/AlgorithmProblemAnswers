#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    int a[n];
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }

    int b[n-1];
    for (int i=0; i<n-1; i++) {
        b[i] = abs(a[i+1]-a[i]);
    }
    sort(b, b+n-1);

    bool result = true;
    for (int i=0; i<n-1; i++) {
        if (i+1 != b[i]) {
            result = false;
            break;
        }
    }

    cout << (result?"Jolly":"Not jolly") << endl;
    return 0;
}