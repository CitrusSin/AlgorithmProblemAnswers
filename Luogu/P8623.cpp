#include <bits/stdc++.h>

using namespace std;

int main() {
    int w, m, n;
    cin >> w >> m >> n;

    int rm = m/w, rn = n/w;
    bool invm = rm%2, invn = rn%2;
    int cm = m%w, cn = n%w;
    if (cm == 0) cm = w;
    if (cn == 0) cn = w;
    if (invm) cm = w+1-cm;
    if (invn) cn = w+1-cn;
    cm--;
    cn--;

    int dist = abs(rm-rn) + abs(cm-cn);

    cout << dist << endl;
    return 0;
}