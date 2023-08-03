#include <bits/stdc++.h>

using namespace std;

bool solve(int x, int y, int n, vector<tuple<int, int, int>>& vt);

int merge_rect(int x, int y, int a, int b, vector<tuple<int, int, int>>& vt) {
    int tms = 0;
    if (a > b) {    
        int c = a%b;
        int t = a/b;
        vector<tuple<int, int, int>> vt2;
        solve(x, y, b, vt2);
        for (int i=0; i<t; i++) {
            for (const tuple<int, int, int>& t : vt2) {
                vt.emplace_back(get<0>(t) + i * b, get<1>(t), get<2>(t));
            }
            tms++;
        }
        if (tms > 50) return -1;
        if (c) {
            int tms2 = merge_rect(x+t*b, y, c, b, vt);
            if (tms2 == -1) return -1;
            tms += tms2;
            if (tms > 50) return -1;
        }
    } else if (a < b) {
        int c = b%a;
        int t = b/a;
        vector<tuple<int,int,int>> vt2;
        solve(x, y, a, vt2);
        for (int i=0; i<t; i++) {
            for (const tuple<int, int, int>& t : vt2) {
                vt.emplace_back(get<0>(t), get<1>(t) + i * a, get<2>(t));
            }
            tms++;
        }
        if (tms > 50) return -1;
        if (c) {
            int tms2 = merge_rect(x, y+t*a, a, c, vt);
            if (tms2 == -1) return -1;
            tms += tms2;
            if (tms > 50) return -1;
        }
    }
    return tms;
}

bool solve(int x, int y, int n, vector<tuple<int, int, int>>& vt) {
    if (n <= 7) {
        if (n > 1) vt.emplace_back(x, y, n);
        return true;
    }

    if (n % 2 == 0) {
        vector<tuple<int, int, int>> vt2;
        solve(x, y, n/2, vt2);
        for (int i=0; i<=1; i++) {
            for (int j=0; j<=1; j++) {
                for (const tuple<int, int, int>& t : vt2) {
                    vt.emplace_back(get<0>(t) + i * n/2, get<1>(t) + j * n/2, get<2>(t));
                }
            }
        }
        vt.emplace_back(x, y, n);
        return true;
    }
    
    bool flag = false;
    for (int b=1; b<=n/2 && !flag; b++) {
        int a = n-b;
        vector<tuple<int, int, int>> vt2;
        int tms = merge_rect(b, 0, a, b, vt2);
        if (tms == -1) continue;
        tms = tms * 2 + 2;
        if (tms > 50) continue;
        flag = true;
        
        for (const tuple<int, int, int>& t : vt2) {
            vt.emplace_back(x + get<0>(t), y + get<1>(t), get<2>(t));
            vt.emplace_back(x + get<1>(t), y + get<0>(t), get<2>(t));
        }
        solve(x, y, b, vt);
        solve(x+b, y+b, a, vt);
        vt.emplace_back(x, y, n);
        return true;
    }
    return flag;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    
    vector<tuple<int, int, int>> vt;
    solve(1, 1, n, vt);

    cout << vt.size() << endl;
    for (const tuple<int, int, int>& t : vt) {
        cout << get<0>(t) << ' ' << get<1>(t) << ' ' << get<2>(t) << endl;
    }
    return 0;
}