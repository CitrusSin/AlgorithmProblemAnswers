#include <bits/stdc++.h>

using namespace std;

char opposite(char c) {
    switch (c) {
    case 'U':
        return 'D';
    case 'D':
        return 'U';
    case 'L':
        return 'R';
    case 'R':
        return 'L';
    default:
        return '\0';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, a, b;
    cin >> n >> a >> b;

    int spl = n/2;
    a--, b--;
    char hf = 'U';
    char vf = 'L';

    string seq;
    if (a <= spl && b <= spl) {
        hf = 'U', vf = 'L';
    } else if (a <= spl && b > spl) {
        hf = 'D', vf = 'L';
        b = n - b - 1;
    } else if (a > spl && b <= spl) {
        hf = 'U', vf = 'R';
        a = n - a - 1;
    } else if (a > spl && b > spl) {
        hf = 'D', vf = 'R';
        a = n - a - 1;
        b = n - b - 1;
    }
    for (int i=0; i<n-1; i++) {
        seq.push_back(hf);
        seq.push_back(vf);
    }
    for (int i=0; i<a; i++) {
        seq.push_back(opposite(vf));
    }
    for (int i=0; i<b; i++) {
        seq.push_back(opposite(hf));
    }
    cout << seq << endl;
    return 0;
}