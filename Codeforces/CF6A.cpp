#include <bits/stdc++.h>
using namespace std;

int main() {
    int lens[4];
    for (int i=0; i<4; i++) {
        cin >> lens[i];
    }

    string res = "IMPOSSIBLE";
    for (int ig=0; ig<4; ig++) {
        int tri[3];
        for (int i=0; i<3; i++) {
            tri[i] = i<ig?lens[i]:lens[i+1];
        }
        if (tri[0]+tri[1]>tri[2] && tri[1]+tri[2]>tri[0] && tri[2]+tri[0]>tri[1]) {
            res = "TRIANGLE";
            break;
        } else if (tri[0]+tri[1]==tri[2] || tri[1]+tri[2]==tri[0] || tri[2]+tri[0]==tri[1]) {
            res = "SEGMENT";
        }
    }
    cout << res << endl;
    return 0;
}