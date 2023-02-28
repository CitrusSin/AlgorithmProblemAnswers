#include <iostream>
#include <cmath>

using namespace std;

#define EPS 1e-6

bool predict24(double *arr, int n) {
    if (n == 1) {
        return abs(arr[0] - 24) < EPS;
    }
    double b[n-1];
    for (int i=0; i<n-1; i++) {
        for (int j=i+1; j<n; j++) {
            if (i != j) {
                for (int k=0; k<n-1; k++) {
                    if (k!=i) {
                        if (k < j) {
                            b[k] = arr[k];
                        } else {
                            b[k] = arr[k+1];
                        }
                    }
                }

                b[i] = arr[i] + arr[j];
                if (predict24(b, n-1)) return true;
                b[i] = arr[i] - arr[j];
                if (predict24(b, n-1)) return true;
                b[i] = arr[j] - arr[i];
                if (predict24(b, n-1)) return true;
                b[i] = arr[i] * arr[j];
                if (predict24(b, n-1)) return true;
                b[i] = arr[i] / arr[j];
                if (predict24(b, n-1)) return true;
                b[i] = arr[j] / arr[i];
                if (predict24(b, n-1)) return true;
            }
        }
    }
    return false;
}

int main() {
    double arr[4];
    while (true) {
        for (int i=0; i<4; i++) {
            cin >> arr[i];
        }
        if (abs(arr[0])<EPS && abs(arr[1])<EPS && abs(arr[2])<EPS && abs(arr[3])<EPS) {
            return 0;
        }
        cout << (predict24(arr, 4)?"YES":"NO") << endl;
    }
    return 0;
}