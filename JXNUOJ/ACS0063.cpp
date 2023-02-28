#include <iostream>

using namespace std;

typedef unsigned long long int ull;
int main() {
    ull n, m;
    cin >> n >> m;

    ull sum = 0;
    char data[10] = "ILOVEACS!";
    for (int i=0;i<9;i++) {
        sum += (ull)data[i];
    }

    ull result = (n*sum)%m;
    cout << result << endl;
    return 0;
}