#include <iostream>

using namespace std;

void sort(int *arr, int n) {
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            if (arr[i] < arr[j]) {
                int swap = arr[i];
                arr[i] = arr[j];
                arr[j] = swap;
            }
        }
    }
}

int main() {
    int n;
    cin >> n;

    int arr[n];
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }

    sort(arr, n);

    if (n < 3) {
        cout << arr[0] << endl;
    } else {
        cout << arr[2] << endl;
    }

    return 0;
}