#include <bits/stdc++.h>

using namespace std;
using u64 = uint64_t;

inline void u64_to_str(char* c, u64 x) {
    char *c2 = c;
    while (x) {
        *c2++ = x%10+'0';
        x/=10;
    }
    *c2-- = '\0';
    while (c < c2) {
        char sw = *c;
        *c = *c2;
        *c2 = sw;
        c++;
        c2--;
    }
}

inline int lucky_value(u64 x) {
    char buf[100];
    u64_to_str(buf, x);
    char minc = '9', maxc = '0';
    for (char* p = buf; *p >= '0' && *p <= '9'; p++) {
        if (*p > maxc) maxc = *p;
        if (*p < minc) minc = *p;
    }
    return maxc-minc;
}

inline void align_str(char* a, char* b) {
    size_t na = strlen(a), nb = strlen(b);
    if (na == nb) return;
    if (na < nb) {
        swap(a, b);
        swap(na, nb);
    }
    size_t dif = na-nb;
    memmove(b+dif, b, nb+1);
    memset(b, '0', dif);
}

inline u64 str2u64(const char* s, size_t max_len) {
    u64 res = 0;
    size_t len = 0;
    while (len++ < max_len && *s) {
        res *= 10;
        res += (*s-'0');
        s++;
    }
    return res;
}

u64 solve(u64 l, u64 r) {
    if (r<l) swap(l, r);
    if (r==l) return l;

    char a[100], b[100];
    u64_to_str(a, l);
    u64_to_str(b, r);
    align_str(a, b);

    size_t n = strlen(a);
    for (size_t len=1; len<n-1; len++) {
        u64 x = str2u64(a, len), y = str2u64(b, len);
        if (y-x>=2) {
            int min_lucky = 10;
            vector<u64> chosen_prefixes;
            vector<int> arr(y-x+1);
            for (u64 i=x; i<=y; i++) {
                int lucky = lucky_value(i);
                arr[i-x] = lucky;
                if (lucky < min_lucky) {
                    min_lucky = lucky;
                    chosen_prefixes.clear();
                    chosen_prefixes.push_back(i);
                } else if (lucky == min_lucky) {
                    chosen_prefixes.push_back(i);
                }
            }

            optional<u64> pfo;
            for (u64 p : chosen_prefixes) {
                if (p != x && p != y) {
                    pfo = p;
                }
            }

            char buf[100];
            if (pfo.has_value()) {
                u64 pf = pfo.value();
                u64_to_str(buf, pf);
                string ress(buf);
                for (size_t k=0; k<n-len; k++) ress.push_back(ress.front());
                return str2u64(ress.c_str(), ress.size());
            } else {
                u64_to_str(buf, x);
                string lim_a(buf);
                u64_to_str(buf, y);
                string lim_b(buf);

                for (size_t k=0; k<n-len; k++) {
                    lim_a.push_back('9');
                    lim_b.push_back('0');
                }

                u64 lx = str2u64(lim_a.c_str(), lim_a.size());
                u64 ly = str2u64(lim_b.c_str(), lim_b.size());
                u64 result_left = solve(l, lx);
                u64 result_right = solve(ly, r);
                arr.front() = lucky_value(result_left);
                arr.back() = lucky_value(result_right);

                chosen_prefixes.clear();
                int min_lucky = 10;
                for (u64 offs=0; offs<=y-x; offs++) {
                    if (arr[offs] < min_lucky) {
                        min_lucky = arr[offs];
                        chosen_prefixes.clear();
                        chosen_prefixes.push_back(x+offs);
                    } else if (arr[offs] == min_lucky) {
                        chosen_prefixes.push_back(x+offs);
                    }
                }

                optional<u64> pfo;
                for (u64 p : chosen_prefixes) {
                    if (p != x && p != y) {
                        pfo = p;
                    }
                }

                if (pfo.has_value()) {
                    u64 pf = pfo.value();
                    u64_to_str(buf, pf);
                    string ress(buf);
                    for (size_t k=0; k<n-len; k++) ress.push_back(ress.front());
                    return str2u64(ress.c_str(), ress.size());
                } else {
                    if (arr.front() < arr.back()) {
                        return result_left;
                    } else {
                        return result_right;
                    }
                }
            }
        }
    }

    u64 min_val = l;
    int min_lucky = lucky_value(l);
    for (size_t i=l+1; i<=r; i++) {
        int lucky = lucky_value(i);
        if (lucky < min_lucky) {
            min_val = i;
            min_lucky = lucky;
        }
    }
    return min_val;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        u64 l, r;
        cin >> l >> r;
        cout << solve(l, r) << endl;
    }
    return 0;
}