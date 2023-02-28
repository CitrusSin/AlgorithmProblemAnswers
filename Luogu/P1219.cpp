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
    int checkboard[n];
    memset(checkboard, 0, n*sizeof(int));

    nqueen_recursive(checkboard, n, 0, receiver);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    int counter = 0;
    nqueen(n, [&counter](int *checkboard, int n2) -> void {
        if (counter <= 2) {
            bool flag = true;
            for (int i=0; i<n2; i++) {
                if (flag) {
                    flag = false;
                } else {
                    cout << " ";
                }
                cout << checkboard[i]+1;
            }
            cout << endl;
        }
        counter++;
    });
    cout << counter << endl;
    return 0;
}