#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    if (n == 0) {
        cout << "DevilG is a single dog!" << endl;
        return 0;
    }

    int arr[n];
    int min_val = 1000;
    for (int i=0; i<n; i++) {
        cin >> arr[i];
        if (arr[i] < min_val) {
            min_val = arr[i];
        }
    }

    int counter = 0;
    for (int i=0; i<n; i++) {
        counter += arr[i] - min_val;
    }

    if (counter > 36500) {
        cout << "RIP" << endl;
    } else {
        cout << counter << endl;
    }
    return 0;
}