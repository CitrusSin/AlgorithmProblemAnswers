#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int as = 0, bs = 0;
    for (int i=0; i<n; i++) {
        int a, b;
        cin >> a >> b;
        as += a;
        bs += b;
    }

    cout << (as == bs ? "Draw" : (as > bs ? "Takahashi" : "Aoki")) << endl;
    return 0;
}