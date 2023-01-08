#include <iostream>
#include <string>
#include <functional>

using namespace std;

void full_permutation(const string &s, const function<void(const string&)> &callback) {
    if (s.length() == 0) {
        return;
    }
    if (s.length() == 1) {
        callback(s);
        return;
    }
    string remain = s;
    for (string::iterator iter = remain.begin(); iter < remain.end(); iter++) {
        char ch = *iter;
        remain.erase(iter);
        full_permutation(remain, [ch, &callback](const string &str) -> void {
            callback(ch+str);
        });
        remain.insert(iter, ch);
    }
}

int main() {
    char buf[7];
    cin >> buf;

    full_permutation(buf, [](const string& str) -> void {
        cout << str << endl;
    });
    return 0;
}