#include <bits/stdc++.h>

using namespace std;

void my_memcopy(string& s, int src, int dst, int size) {
    for (int i=0; i<size; i++) {
        int a = src + i;
        int b = dst + i;
        if (a < s.size() && b < s.size()) {
            s[b] = s[a];
        }
    }
}

void my_memmove(string& s, int src, int dst, int size) {
    if (src <= dst) {
        for (int i=size-1; i>=0; i--) {
            int a = src+i, b = dst+i;
            if (a < s.size() && b < s.size()) {
                s[b] = s[a];
            }
        }
    } else {
        for (int i=0; i<size; i++) {
            int a = src + i;
            int b = dst + i;
            if (a < s.size() && b < s.size()) {
                s[b] = s[a];
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    size_t n;
    cin >> n;

    string s;
    cin >> s;

    int a, b, c;
    cin >> a >> b >> c;
    a--;
    b--;

    string s2 = s;
    my_memcopy(s, a, b, c);
    my_memmove(s2, a, b, c);

    cout << s << endl << s2 << endl;
    return 0;
}