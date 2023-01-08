#include <iostream>
#include <cstdio>

using namespace std;

void hanoi_output(int n, int src, int dst, int buf, char *sign_arr) {
    if (n == 1) {
        cout << sign_arr[src] << "->" << n << "->" << sign_arr[dst] << endl;
        return;
    }
    hanoi_output(n-1, src, buf, dst, sign_arr);
    cout << sign_arr[src] << "->" << n << "->" << sign_arr[dst] << endl;
    hanoi_output(n-1, buf, dst, src, sign_arr);
}

int main() {
    int n;
    char sign[3];
    scanf("%d %c %c %c", &n, &sign[0], &sign[1], &sign[2]);

    hanoi_output(n, 0, 1, 2, sign);
    return 0;
}