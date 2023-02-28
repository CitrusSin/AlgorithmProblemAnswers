#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }

    vector<int> painter_data(m, 0);
    int i = 0, j = 0;
    int min_len = n, min_a = 0, min_b = n;
    while (i < n && j < n) {
        painter_data[a[j++]-1]++;
        while (painter_data[a[i]-1] >= 2) {
            painter_data[a[i++]-1]--;
        }
        if (j-i+1 < min_len) {
            bool available = true;
            for (int p : painter_data) {
                if (p == 0) {
                    available = false;
                    break;
                }
            }
            if (available) {
                min_len = j-i+1;
                min_a = i;
                min_b = j;
            }
        }
    }
    cout << min_a+1 << " " << min_b << endl;
    return 0;
}