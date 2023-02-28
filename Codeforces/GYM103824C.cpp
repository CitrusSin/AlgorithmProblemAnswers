#include <bits/stdc++.h>
using namespace std;

int sort_cnt(const int *arr, int n) {
    bool scd[n];
    memset(scd, 0, n*sizeof(bool));
    int total_cnt = 0;
    for (int i=0; i<n; i++) {
        scd[i] = true;
        int sci = arr[i], cnt = 0;
        while (!scd[sci]) {
            cnt++;
            scd[sci] = true;
            sci = arr[sci];
        }
        total_cnt += cnt;
    }
    return total_cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k, l, r;
    cin >> n >> k >> l >> r;
    int arr[n];
    for (int i=0; i<n; i++) {
        cin >> arr[i];
        arr[i]--;
    }
    cout << abs(sort_cnt(arr, n)-k) << endl;
    return 0;
}