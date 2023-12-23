#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;

    int cnt = 0;
    for (size_t pos = 0; pos != string::npos; pos++, cnt++) {
        pos = s.find("hzy", pos);
        if (pos == string::npos) break;
    }
    for (size_t pos = 0; pos != string::npos; pos++, cnt++) {
        pos = s.find("zzy", pos);
        if (pos == string::npos) break;
    }
    for (size_t pos = 0; pos != string::npos; pos++, cnt++) {
        pos = s.find("syh", pos);
        if (pos == string::npos) break;
    }
    
    cout << (cnt * 3) << endl;
    return 0;
}