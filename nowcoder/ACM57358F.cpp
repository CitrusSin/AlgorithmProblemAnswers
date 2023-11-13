#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
#include <concepts>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<pair<int, int>> candidates(n);
    deque<int> a(n);
    deque<int> idx(n);
    for (int i=0; i<n; i++) {
        candidates[i].first = i;
        cin >> candidates[i].second;
    }
    stable_sort(candidates.begin(), candidates.end(), [](auto& a, auto& b) {
        return a.second < b.second;
    });
    for (int i=0; i<n; i++) {
        a[i] = candidates[i].second;
        idx[i] = candidates[i].first;
    }

    for (int i=0; i<n-1; i++) {
        int mid = (int64_t(a.front()) + a.back()) / 2;
        auto sp = upper_bound(a.begin(), a.end(), mid);
        int sl = sp - a.begin();
        int sr = a.end() - sp;
        if (sl >= sr) {
            a.pop_back();
            idx.pop_back();
        } else {
            a.pop_front();
            idx.pop_front();
        }
    }

    

    cout << (idx.front() + 1) << endl;
    return 0;
}