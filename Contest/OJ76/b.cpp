#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+10;
int dt[N];

int main() {
    int n, k;
    cin >> n >> k;

    for (int i=0; i<n; i++) {
        cin >> dt[i];
    }

    deque<int> mtq;
    for (int i=0; i<n; i++) {
        if (!mtq.empty() && mtq.front() <= i-k) {
            mtq.pop_front();
        }
        while (!mtq.empty() && dt[mtq.back()] < dt[i]) {
            mtq.pop_back();
        }
        mtq.push_back(i);
        if (!mtq.empty() && i >= k-1) {
            cout << dt[mtq.front()] << endl;
        }
    }
    return 0;
}