#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i=0; i<n; i++) cin >> arr[i];

    vector<int> rst(n, 0);
    for (int i=0; i<n; i++) {
        int tcnt = 0, r = arr[i];
        for (int j=i+1; j<n; j++) {
            if (arr[j] > r) {
                tcnt++;
                r = arr[j];
                if (tcnt >= 2) break;
            }
        }
        if (r != arr[i] && tcnt == 2) rst[i] = r;
    }
    for (int i : rst) {
        cout << i << ' ';
    }
    cout << endl;
    return 0;
}