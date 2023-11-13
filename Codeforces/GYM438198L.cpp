#include <bits/stdc++.h>

using namespace std;

const uint64_t MOD = 2147483647, RADIX = 31;

int64_t gcd(int64_t a, int64_t b) {
    return b ? gcd(b, a%b) : a;
}

/*
int qpow(int base, int exp) {
    if (exp == 0) {
        return 1;
    } else if (exp == 1) {
        return base % MOD;
    }
    int64_t part = qpow(base, exp/2);
    part *= part;
    part %= MOD;
    if (exp % 2) {
        part *= base;
        part %= MOD;
    }
    return part;
}
*/

int64_t strhash(const string& s) {
    int64_t res = 0;
    for (char c : s) {
        res *= RADIX;
        res %= MOD;
        res += c-'a';
        res %= MOD;
    }
    return (int)res;
}

/*
void exgcd(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1, y = 0;
        return;
    }
    exgcd(b, a%b, x, y);
    int tmp = x;
    x = y;
    y = tmp-(a/b)*y;
}

int inv(int a) {
    // a*x+MOD*y = 1, MOD prime
    int x, y;
    exgcd(a, MOD, x, y);
    while (x<0) x+=MOD;
    return x%MOD;
}
*/

void rev(string& str) {
    int n = str.size();
    int i = 0, j = n-1;
    while (i < j) {
        swap(str[i], str[j]);
        i++, j--;
    }
}

string rol(const string& s, int x) {
    string a = s.substr(0, x), b = s.substr(x);
    return b+a;
}

string proc(const string& s, int x) {
    size_t n = s.size();
    string a = s.substr(0, x), b = s.substr(x);
    string res;
    res.reserve(n);
    for (auto iter = a.rbegin(); iter != a.rend(); iter++) {
        res.push_back(*iter);
    }
    for (auto iter = b.rbegin(); iter != b.rend(); iter++) {
        res.push_back(*iter);
    }
    return res;
}

int64_t radix_pow(int exp) {
    static vector<int64_t> pows;

    if (pows.size() == 0) {
        pows.push_back(1);
    }
    
    if (exp == 0) {
        return pows[0];
    }

    for (int ex2 = pows.size(); ex2 <= exp; ex2++) {
        int64_t val = (pows[ex2-1] * RADIX) % MOD;
        pows.push_back(val);
    }
    return pows[exp];
}

bool solve(const string& s1, const string& s2, int a, int b) {
    /*
    unordered_map<char, int> mp1, mp2;
    for (char c : s1) mp1[c]++;
    for (char c : s2) mp2[c]++;
    for (auto p : mp1) {
        if (!mp2.count(p.first) || mp2[p.first] != p.second) {
            return false;
        }
    }
    */

    int64_t n = s1.size();

    vector<int64_t> prefix_hash(n, 0), suffix_hash(n, 0);
    //vector<int64_t> prefix_rev_hash(n, 0), suffix_rev_hash(n, 0);
    /*
    for (int i=0; i<n; i++) {
        string sub = s1.substr(0, i);
        prefix_hash[i] = strhash(sub);
        //rev(sub);
        //prefix_rev_hash[i] = strhash(sub);

        sub = s1.substr(i);
        suffix_hash[i] = strhash(sub);
        //rev(sub);
        //suffix_rev_hash[i] = strhash(sub);
    }
    */
    int64_t hsh = 0;
    for (int i=0; i<n; i++) {
        hsh *= RADIX;
        hsh %= MOD;
        hsh += s1[i]-'a';
        hsh %= MOD;
        if (i+1 < n) prefix_hash[i+1] = hsh;
    }
    prefix_hash[0] = 0;
    for (int i=0; i<n; i++) {
        suffix_hash[i] = hsh - prefix_hash[i] * radix_pow(n-i);
        while (suffix_hash[i] < 0) suffix_hash[i] += MOD;
        suffix_hash[i] %= MOD;
    }

    int64_t count = n/gcd(n, abs(a-b));
    int64_t rdelta = abs(a-b);
    string s2a = proc(s2, a), s2b = proc(s2, b);
    int64_t s2h = strhash(s2), s2ah = strhash(s2a), s2bh = strhash(s2b);
    for (int i=0; i<count; i++) {
        int64_t rlen = (i*rdelta)%n;
        int64_t h = (prefix_hash[rlen] + (suffix_hash[rlen]*radix_pow(rlen)) % MOD) % MOD;
        //int64_t h = strhash(sp);

        if (s2h == h) {
            string sp = rol(s1, rlen);
            if (sp == s2) return true;
        }
        if (s2ah == h) {
            string sp = rol(s1, rlen);
            if (sp == s2a) return true;
        }
        if (s2bh == h) {
            string sp = rol(s1, rlen);
            if (sp == s2b) return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2;
        int a, b;
        cin >> a >> b;
        cout << (solve(s1, s2, a, b)?"yes":"no") << endl;
    }
    return 0;
}