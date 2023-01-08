#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        string p1, p2;
        string s1;
        while (s1 != "START") getline(cin, s1);
        getline(cin, s1);
        while (s1 != "END") {
            p1.append(s1);
            p1.push_back('\n');
            getline(cin, s1);
        }
        while (s1 != "START") getline(cin, s1);
        getline(cin, s1);
        while (s1 != "END") {
            p2.append(s1);
            p2.push_back('\n');
            getline(cin, s1);
        }

        if (p1 == p2) {
            cout << "Accepted" << endl;
            continue;
        }

        for (auto it = p1.begin(); it != p1.end();) {
            if (*it == ' ' || *it == '\t' || *it == '\n') {
                it = p1.erase(it);
            } else {
                it++;
            }
        }
        for (auto it = p2.begin(); it != p2.end();) {
            if (*it == ' ' || *it == '\t' || *it == '\n') {
                it = p2.erase(it);
            } else {
                it++;
            }
        }

        if (p1 == p2) {
            cout << "Presentation Error" << endl;
        } else {
            cout << "Wrong Answer" << endl;
        }
    }
    return 0;
}