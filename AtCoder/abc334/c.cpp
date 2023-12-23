#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int k, n;
    cin >> n >> k;

    vector<int> a(k);
    for (int i=0; i<k; i++) {
        cin >> a[i];
    }

    int oddn = 0;
    if (k % 2 == 0) {
        for (int i=0; i+1<k; i+=2) {
            oddn += abs(a[i+1]-a[i]);
        }
    } else {
        int odd1 = 0, odd2 = 0;
        for (int i=0; i+1<k; i+=2) {
            odd1 += abs(a[i+1]-a[i]);
        }
        for (int i=1; i+1<k; i+=2) {
            odd2 += abs(a[i+1]-a[i]);
        }
        oddn = min(odd1, odd2);
        vector<int> oddl((k-1)/2), oddr((k-1)/2);
        for (int i=0; i<(k-1)/2; i++) {
            oddl[i] = (i?oddl[i-1]:0) + abs(a[i*2+1]-a[i*2]);
        }
        for (int i=(k-1)/2-1; i>=0; i--) {
            oddr[i] = (i==(k-1)/2?0:oddr[i+1]) + abs(a[i*2+2]-a[i*2+1]);
        }
        for (int i=0; i<(k-1)/2-1; i++) {
            oddn = min(oddn, oddl[i]+oddr[i+1]);
        }
    }

    cout << oddn << endl;
    return 0;
}