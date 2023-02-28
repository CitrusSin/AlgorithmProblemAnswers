#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }

    int i=0, j=arr.size()-1;
    int a=0, b=0;
    int counter = 0, max_counter = 0;
    while (i <= j) {
        if (a == b) {
            max_counter = counter;
            a += arr[i];
            b += arr[j];
            i++;
            j--;
            counter+=2;
        } else {
            if (a > b) {
                b += arr[j];
                j--;
            } else {
                a += arr[i];
                i++;
            }
            counter++;
        }
    }
    if (a == b) {
        max_counter = counter;
    }

    cout << max_counter << endl;
    return 0;
}