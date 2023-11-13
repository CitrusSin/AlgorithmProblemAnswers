#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;

char solve(const string& s1, i64 pos) {
    i64 n = s1.size();

    pos++;
    i64 si = ceil(((2*n-1)-sqrt((2*n-1)*(2*n-1)+8*(n-pos)))/2.0);
    si = max<i64>(si, 0);
    
    pos--;
    pos -= si*(2*n-si+1)/2;

    deque<char> deq;
    for (i64 i=0; i<n; i++) {
        while (si > 0 && !deq.empty() && deq.back() > s1[i]) {
            deq.pop_back();
            si--;
        }
        deq.push_back(s1[i]);
    }
    return deq[pos];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        
        i64 i;
        cin >> i;
        
        cout << solve(s, i-1);
    }
    cout << endl;

    return 0;
}