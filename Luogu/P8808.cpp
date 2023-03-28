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

    vector<int> fib(n);
    fib[0] = 1;
    fib[1] = 1;
    for (int i=2; i<n; i++) fib[i] = fib[i-1]+fib[i-2];

    vector<int> e(n, -1);
    unordered_map<int, int> counter;
    for (int i=0; i<n; i++) {
        if (fib[i] > 1000000) break;
        if (arr[i]%fib[i] == 0) {
            e[i] = arr[i]/fib[i];
            counter[e[i]]++;
        } else {
            e[i] = -1;
        }
    }

    int max_counter = 0;
    for (auto& p : counter) {
        max_counter = max(max_counter, p.second);
    }
    int result = n-max_counter;

    cout << result << endl;
    return 0;
}