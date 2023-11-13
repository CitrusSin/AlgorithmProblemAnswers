#include <iostream>

using namespace std;

void print_seq(int n) {
    for (int i=1; i<=n; i++) {
        cout << i;
        if (i < n) {
            cout << " ";
        } else {
            cout << endl;
        }
    }
}

int main() {
    int t;
    cin >> t;

    for (int tr=0; tr<t; tr++) {
        int n;
        cin >> n;

        for (int i=n; i>1; i--) {
            int spaces = n-i;
            for (int r=0; r<spaces; r++) {
                cout << " ";
            }
            print_seq(i);
        }
        for (int i=1; i<=n; i++) {
            int spaces = n-i;
            for (int r=0; r<spaces; r++) {
                cout << " ";
            }
            print_seq(i);
        }
    }
    return 0;
}
