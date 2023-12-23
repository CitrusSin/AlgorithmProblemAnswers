#include <iostream>
#include <string>

using namespace std;

int main() {
    int b, g;
    cin >> b >> g;

    string pres = b < g ? "Glove" : "Bat";
    cout << pres << endl;
    return 0;
}