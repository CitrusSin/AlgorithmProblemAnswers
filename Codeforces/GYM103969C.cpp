#include <bits/stdc++.h>

using namespace std;

int count_cake(int *arr, int n) {
    int max_cakes_count = n/5;
    int cakes[max_cakes_count];
    for (int i=0; i<max_cakes_count; i++) cakes[i] = 0;

    int cakes_count = 0, finished_cakes_count = 0;
    for (int i=0; i<n; i++) {
        int j=0;
        while (j <= cakes_count && cakes[j] != arr[i]-1) j++;
        if (j > cakes_count) continue;
        if (j == cakes_count) cakes_count++;
        cakes[j]++;
        if (cakes[j] == 5) finished_cakes_count++;
    }

    return finished_cakes_count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    int arr[n];
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }

    cout << count_cake(arr, n) << endl;
    return 0;
}