#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    int n;
    cin >> n;

    int time = 24;
    for (int i=0; i<n; i++) {
        int a, b;
        scanf("%d:00:00 %d:00:00", &a, &b);
        time -= b-a;
    }
    cout << time << endl;
    return 0;
}