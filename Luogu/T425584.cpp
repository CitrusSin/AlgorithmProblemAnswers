#include <bits/stdc++.h>

using namespace std;

uint64_t qpow(uint64_t base, uint64_t exp, uint64_t mod) {
    uint64_t r = base % mod, rst = 1;
    while (exp) {
        if (exp & 1) rst = rst * r % mod;
        r = r * r % mod;
        exp >>= 1;
    }
    return rst;
}

vector<uint64_t> str_hash(string_view sv) {
    const uint64_t mod = 998244353;

    size_t n = sv.size();

    vector<uint64_t> hsh(n, 0);
    for (size_t i=0; i<n; i++) {
        if (i > 0) hsh[i] = hsh[i-1];
        hsh[i] *= 29;
        hsh[i] %= mod;
        hsh[i] += sv[i] - 'a';
        hsh[i] %= mod;
    }

    return hsh;
}

uint64_t sub_hash(const vector<uint64_t>& hsh, size_t l, size_t r) {
    const uint64_t mod = 998244353;

    uint64_t hp = mod + hsh[r];
    if (l > 0) hp -= hsh[l-1] * qpow(29, r-l+1, mod) % mod;
    hp %= mod;

    //hp *= inv(qpow(29, l, mod), mod);
    //hp %= mod;

    return hp;
}

int main() {
    string s;
    getline(cin, s);

    string srev(s.rbegin(), s.rend());

    string_view sv(s), srevv(srev);

    vector<uint64_t> hasht = str_hash(sv);
    vector<uint64_t> revhasht = str_hash(srevv);

    map<char, uint64_t> record;
    size_t l = 0;
    size_t ans = 0;
    for (size_t r=0; r<s.size(); r++) {
        record[s[r]]++;
        while (record[s[r]] > 1) {
            record[s[l]]--;
            if (record[s[l]] == 0) record.erase(s[l]);
            l++;
        }

        auto cmp = [&](size_t l1, size_t r1, size_t l2, size_t r2) -> bool {
            //uint64_t h1 = sub_hash(hasht, l1, r1);
            //uint64_t h2 = sub_hash(revhasht, s.size()-r2-1, s.size()-l2-1);
            //if (h1 != h2) return false;

            return sv.substr(l1, r1-l1+1) == srevv.substr(s.size()-r2-1, r2-l2+1);
        };

        size_t maxlen = min(r-l+1, s.size()-r), minlen = 1;
        while (maxlen > minlen) {
            size_t mid = minlen + (maxlen - minlen) / 2;
            if ((maxlen - minlen) % 2) mid++;
            if (cmp(r-mid+1, r, r, r+mid-1)) {
                minlen = mid;
            } else {
                maxlen = mid - 1;
            }
        }
        ans += maxlen;
        if (r >= s.size()-1 || s[r] != s[r+1]) continue;
        maxlen = min(r-l+1, s.size()-r-1), minlen = 1;
        if (maxlen == 0) continue;
        while (maxlen > minlen) {
            size_t mid = minlen + (maxlen - minlen) / 2;
            if ((maxlen - minlen) % 2) mid++;
            if (cmp(r-mid+1, r, r+1, r+mid)) {
                minlen = mid;
            } else {
                maxlen = mid - 1;
            }
        }
        ans += maxlen;
    }

    cout << ans << endl;
    return 0;
}