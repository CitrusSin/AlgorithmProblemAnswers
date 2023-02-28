#include <iostream>
#include <cstdio>

using namespace std;

long long split_count(int n, int max) {
    if (n == 1) {
        return max >= n;
    }

    int counter = 0;
    for (int i=min(max, n-1); i>0; i--) {
        counter += split_count(n-i, i);
    }
    if (max >= n) {
        counter++;
    }
    return counter;
}

int main() {
    int c;
    while (scanf("%d", &c) == 1) {
        cout << split_count(c, c) << endl;
    }
    return 0;
}