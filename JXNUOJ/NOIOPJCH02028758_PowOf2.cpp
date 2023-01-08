#include <iostream>
#include <string>

using namespace std;

void powof2_recursive(unsigned int x, string &s) {
    if (x == 0) {
        s.push_back('0');
        return;
    }
    bool is_first = true;
    for (int d=30; d>=0; d--) {
        if ((x>>d)&1) {
            if (is_first) {
                is_first = false;
            } else {
                s.push_back('+');
            }
            s.push_back('2');
            if (d != 1) {
                s.push_back('(');
                powof2_recursive(d, s);
                s.push_back(')');
            }
        }
    }
}

string powof2(unsigned int x) {
    string s;
    powof2_recursive(x, s);
    return s;
}

int main() {
    unsigned int x;
    cin >> x;
    cout << powof2(x) << endl;
    return 0;
}