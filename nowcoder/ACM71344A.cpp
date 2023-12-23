#include <iostream>
#include <string>
#include <array>

using namespace std;

array<int, 128> chrs;
const string hole1 = "ADOPQRabdegopq0469";
const string hole2 = "B8";

int main() {
    chrs.fill(0);
    for (char c : hole1) {
        chrs[c] = 1;
    }
    for (char c : hole2) {
        chrs[c] = 2;
    }

    string s;
    cin >> s;

    int cnt = 0;
    for (char c : s) {
        cnt += chrs[c];
    }
    cout << cnt << endl;
    return 0;
}