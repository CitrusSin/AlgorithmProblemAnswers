#include <iostream>
#include <functional>
#include <memory.h>

using namespace std;

void nqueen_recursive(int *checkboard, int n, int depth, const function<void(int*, int)> &receiver) {
    if (depth == n) {
        receiver(checkboard, n);
        return;
    }
    for (int pos=0; pos<n; pos++) {
        bool pos_available = true;
        for (int row=0; row<depth; row++) {
            int col = checkboard[row];
            if (row+col == depth+pos || row-col == depth-pos || row == depth || col == pos) {
                pos_available = false;
                break;
            }
        }
        if (pos_available) {
            checkboard[depth] = pos;
            nqueen_recursive(checkboard, n, depth+1, receiver);
        }
    }
}

void nqueen(int n, const function<void(int*, int)> &receiver) {
    int *checkboard = new int[n];
    memset(checkboard, 0, n*sizeof(int));

    nqueen_recursive(checkboard, n, 0, receiver);

    delete checkboard;
}

int main() {
    int counter = 1;
    nqueen(8, [&counter](int *checkboard, int n) -> void {
        cout << "No. " << counter << endl;
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                int pos = checkboard[j];
                if (i == pos) {
                    cout << "1";
                } else {
                    cout << "0";
                }
                if (j == n-1) {
                    cout << endl;
                } else {
                    cout << " ";
                }
            }
        }
        counter++;
    });
    return 0;
}