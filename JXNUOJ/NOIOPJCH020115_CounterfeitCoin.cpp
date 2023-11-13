#include <iostream>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;

void solve() {
    string real_coins;
    string lefts[3], rights[3], status[3];

    for (int i=0;i<3;i++) {
        char str1[13], str2[13], st[5];
        scanf("%s %s %s", str1, str2, st);
        string s1 = str1, s2 = str2, state = st;
        lefts[i] = s1;
        rights[i] = s2;
        status[i] = state;
    }
    
    for (char coin = 'A'; coin <= 'L'; coin++) {
        bool result = true;
        // check heavy
        for (int i=0; i<3; i++) {
            if (lefts[i].find(coin) != string::npos) {
                if (status[i] != "up") {
                    result = false;
                    break;
                }
            } else if (rights[i].find(coin) != string::npos) {
                if (status[i] != "down") {
                    result = false;
                    break;
                }
            } else {
                if (status[i] != "even") {
                    result = false;
                    break;
                }
            }
        }
        if (result) {
            cout << coin << " is the counterfeit coin and it is heavy." << endl;
            return;
        }

        result = true;
        for (int i=0; i<3; i++) {
            if (lefts[i].find(coin) != string::npos) {
                if (status[i] != "down") {
                    result = false;
                    break;
                }
            } else if (rights[i].find(coin) != string::npos) {
                if (status[i] != "up") {
                    result = false;
                    break;
                }
            } else {
                if (status[i] != "even") {
                    result = false;
                    break;
                }
            }
        }
        if (result) {
            cout << coin << " is the counterfeit coin and it is light." << endl;
            return;
        }
    }
}

int main() {
    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        solve();
    }
    return 0;
}