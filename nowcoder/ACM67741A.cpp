#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        
        string s;
        cin >> s;
        
        int ac=0, bc=0;
        for (char c : s) {
            if (ac == 0 && c == 'd') ac++;
            else if (ac == 1 && c == 'f') ac++;
            else if (ac == 2 && c == 's') ac++;
            if (bc == 0 && c == 'D') bc++;
            else if (bc == 1 && c == 'F') bc++;
            else if (bc == 2 && c == 'S') bc++;
        }
        
        cout << (ac == 3) << ' ' << (bc == 3) << endl;
    }
}