#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 decode(const string &s) {
    i64 result = 0;
    for (const char &c : s) {
        result *= 26;
        result += c-'a';
    }
    return result;
}

i64 fast_pow(i64 base, int ex) {
    if (ex == 0) return 1;
    if (ex == 1) return base;
    
    i64 res = fast_pow(base, ex/2);
    if (ex % 2 == 1) {
        return res*res*base;
    } else {
        return res*res;
    }
}

int main() {
    int t;
    cin >> t;
    for (int r=0; r<t; r++) {
        string s;
        cin >> s;
        
        int spare_bit = s.find_first_not_of('a');
        string eff = s.substr(spare_bit);
        i64 d = decode(eff);
        
        for (int b=0; b<eff.size(); b++) {
            i64 base = fast_pow(26, b);
            
        }
    }
    return 0;
}