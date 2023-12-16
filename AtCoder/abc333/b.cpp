#include <iostream>

using namespace std;

int main() {
    char s1c, s2c, t1c, t2c;
    cin >> s1c >> s2c;
    cin >> t1c >> t2c;

    int s1, s2, t1, t2;
    s1 = s1c-'A';
    s2 = s2c-'A';
    t1 = t1c-'A';
    t2 = t2c-'A';

    int d1 = min(abs(s1-s2), 5-abs(s1-s2));
    int d2 = min(abs(t1-t2), 5-abs(t1-t2));

    cout << (d1 == d2 ? "Yes" : "No") << endl;
    return 0;
}