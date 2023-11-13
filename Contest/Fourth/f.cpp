#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cstdio>

using namespace std;

bool check(const vector<int>& cables, int len, int k) {
    int total = 0;
    size_t n = cables.size();
    for (int i=0; i<n; i++) {
        int l = cables[i];
        total += l / len;
        if (total >= k) return true;
    }
    return total >= k;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;

    vector<int> cables;
    cables.reserve(n);
    for (int i=0; i<n; i++) {
        double p;
        cin >> p;
        cables.push_back(int(p*100));
    }

    int available_max = accumulate(cables.begin(), cables.end(), 0);
    if (available_max < k) {
        cout << "0.00" << endl;
        return 0;
    }

    int l=1, r=1+*max_element(cables.begin(), cables.end());
    while (l < r) {
        int mid = l+(r-l)/2;
        if ((r-l)%2==1) mid++;
        if (check(cables, mid, k)) {
            l = mid;
        } else {
            r = mid-1;
        }
    }
    printf("%.2lf\n", l/100.0);
    return 0;
}