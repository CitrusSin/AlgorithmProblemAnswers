#include <bits/stdc++.h>

using namespace std;

int process_line(string_view sv, int k) {
    int ans = -1;
    int dc = 0;
    queue<char> qu;
    for (int i=0; i<sv.size(); i++) {
        char c = sv[i];
        if (c == 'x') {
            while (!qu.empty()) qu.pop();
            dc = 0;
            continue;
        }
        qu.push(c);
        if (c == '.') dc++;
        if (qu.size() > k) {
            if (qu.front() == '.') dc--;
            qu.pop();
        }
        if (qu.size() == k) {
            if (ans == -1 || dc < ans) {
                ans = dc;
            }
        }
    }
    return ans;
}

int main() {
    int h, w, k;
    cin >> h >> w >> k;

    vector<string> mat(h);
    for (int i=0; i<h; i++) cin >> mat[i];

    vector<string> mat2(w);
    for (int i=0; i<w; i++) {
        mat2[i].resize(h, '.');
    }
    for (int i=0; i<h; i++) {
        for (int j=0; j<w; j++) {
            mat2[j][i] = mat[i][j];
        }
    }

    int ans = -1;
    for (int i=0; i<h; i++) {
        int v = process_line(mat[i], k);
        if (v == -1) continue;
        if (ans == -1 || v < ans) ans = v;
    }
    for (int i=0; i<w; i++) {
        int v = process_line(mat2[i], k);
        if (v == -1) continue;
        if (ans == -1 || v < ans) ans = v;
    }

    cout << ans << endl;
}