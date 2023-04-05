#include <bits/stdc++.h>

using std::ios, std::cout, std::cin, std::endl;

std::vector<int> construct(int n, int k) {
    k = n*(n+1)/2-k;
    n++;
    std::vector<int> cons(n);
    for (int i=0; i<n; i++) {
        cons[i] = i;
    }
    int t = n;
    bool bf = false;
    while (t--) {
        for (int i=0; i<t; i++) {
            if (k>0) {
                std::swap(cons[i], cons[i+1]);
                k--;
            } else {
                bf = true;
                break;
            }
        }
        if (bf) {
            break;
        }
    }

    int f = cons[0];
    for (int i=0; i<n; i++) {
        cons[i] -= f;
    }
    n--;
    std::vector<int> arr(n);
    for (int i=0; i<n; i++) {
        arr[i] = cons[i+1]-cons[i];
    }
    return arr;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        std::vector<int> arr = construct(n, k);
        for (int p : arr) {
            cout << p << ' ';
        }
        cout << endl;
    }
    return 0;
}