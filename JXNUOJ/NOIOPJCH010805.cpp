#include <iostream>

using namespace std;

int main() {
    int matrix[5][5];
    for (int i=0; i<5; i++) {
        for (int j=0; j<5; j++) {
            cin >> matrix[i][j];
        }
    }

    for (int i=0; i<5; i++) {
        for (int j=0; j<5; j++) {
            int val = matrix[i][j];

            bool p = true;
            for (int k=0; k<5; k++) {
                if (matrix[i][k]>val) {
                    p = false;
                    break;
                }
                if (matrix[k][j]<val) {
                    p = false;
                    break;
                }
            }

            if (p) {
                cout << i+1 << ' ' << j+1 << ' ' << val << endl;
                return 0;
            }
        }
    }
    cout << "not found" << endl;
    return 0;
}