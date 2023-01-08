#include <iostream>

using namespace std;

void sort(int *arr, int n) {
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            if (arr[i] > arr[j]) {
                arr[i] ^= arr[j];
                arr[j] ^= arr[i];
                arr[i] ^= arr[j];
            }
        }
    }
}

int main() {
    int n;
    cin >> n;

    int packets[n];
    for (int i=0; i<n; i++) {
        cin >> packets[i];
    }
    sort(packets, n);

    int m=0, k=0;

    for (int i=0; i<n/2; i++) {
        m += packets[i];
    }
    for (int i=n/2; i<n; i++) {
        k += packets[i];
    }
    
    cout << m << " " << k << endl;
    return 0;
}