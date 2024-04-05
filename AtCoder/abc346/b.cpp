#include <bits/stdc++.h>

using namespace std;

int main() {
    const string templ = "wbwbwwbwbwbw";
    int wc = 0, bc = 0;
    for (char c : templ) {
        if (c == 'w') wc++;
        if (c == 'b') bc++;
    }

    int w, b;
    cin >> w >> b;

    int p = min(w / wc, b / bc);
    w -= p * wc;
    b -= p * bc;

    int len = w+b;
    int wcc = 0, bcc = 0;
    for (int i=0; i<len; i++) {
        if (templ[i] == 'w') wcc++;
        if (templ[i] == 'b') bcc++;
    }

    bool found = false;
    for (int i=0; i<templ.size() && !found; i++) {
        if (wcc == w && bcc == b) found = true;
        if (templ[i % templ.size()] == 'w') wcc--; else bcc--;
        if (templ[(i+len) % templ.size()] == 'w') wcc++; else bcc++;
    }

    cout << (found ? "Yes" : "No") << '\n';
    return 0;
}