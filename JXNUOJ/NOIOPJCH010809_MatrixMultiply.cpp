#include <iostream>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    int m1[n][m], m2[m][k];
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> m1[i][j];
        }
    }

    for (int i=0; i<m; i++) {
        for (int j=0; j<k; j++) {
            cin >> m2[i][j];
        }
    }

    int product[n][k];
    for (int i=0; i<n; i++) {
        for (int j=0; j<k; j++) {
            int sum = 0;
            for (int s=0; s<m; s++) {
                sum += m1[i][s] * m2[s][j];
            }
            product[i][j] = sum;
        }
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<k; j++) {
            cout << product[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}