#include <bits/stdc++.h>

using namespace std;

int main() {
    int a[6], b[6]={1, 2, 3, 5, 10, 20};
    bitset<1020> s;
    for (int i=0; i<6; i++) cin >> a[i];
    s[0] = 1;
    for (int i=0; i<6; i++)
        for (int j=0; j<a[i]; j++)
            s |= s << b[i];
    cout << "Total=" << s.count()-1 << endl;
    return 0;
}