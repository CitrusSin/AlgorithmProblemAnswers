#include <iostream>

using namespace std;

int apple_solution_count(int m, int n, int min) {
    if (n == 1) {
        return (min > m)?0:1;
    }
    int result = 0;
    for (int count = min; count <= m; count++) {
        result += apple_solution_count(m-count, n-1, count);
    }
    return result;
}

int main() {
    int t;
    cin >> t;

    for (int i=0; i<t; i++) {
        int m, n;
        cin >> m >> n;
        cout << apple_solution_count(m, n, 0) << endl;
    }
    return 0;
}