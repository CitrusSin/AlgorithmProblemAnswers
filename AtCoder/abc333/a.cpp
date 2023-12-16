#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main() {
    char* endptr;
    string s;
    cin >> s;

    int v = s[0] & 0x0f;
    stringstream ss;
    for (int i=0; i<v; i++) {
        ss << s;
    }
    s = ss.str();
    cout << s << endl;
    return 0;
}