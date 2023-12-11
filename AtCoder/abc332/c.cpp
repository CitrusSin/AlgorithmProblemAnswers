#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    string s;
    cin >> n >> m;
    cin >> s;

    int tshc = 0, ltshc = 0;
    
    int c=0, d=0;
    for (int i=0; i<=n; i++) {
        if (i < n && s[i] >= '1') {
            c++;
            if (s[i] == '2') {
                d++;
            }
        } else {
            tshc = max(tshc, c);
            ltshc = max(ltshc, d);
            c = d = 0;
        }
    }
    int cc = ltshc + max(0, (tshc - (ltshc + m)));
    cout << cc << endl;
    return 0;
}