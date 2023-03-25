#include <bits/stdc++.h>

using namespace std;
using u64 = uint64_t;

u64 factorial(int x) {
    u64 result = 1;
    while (x) {
        result *= x--;
    }
    return result;
}

template <typename SIter>
u64 permutation_count(SIter t0, SIter t1, string sample) {
    if (t0 == t1) return 0;
    auto s0 = sample.begin(), s1 = sample.end();
    int index = lower_bound(s0, s1, *t0) - s0;
    u64 base = index*factorial(t1-t0-1);
    sample.erase(sample.find_first_of(*t0), 1);
    return base + permutation_count(++t0, t1, sample);
}


int main() {
    string s;
    cin >> s;

    string s0 = s;
    sort(s0.begin(), s0.end());

    cout << permutation_count(s.begin(), s.end(), s0) << endl;
    return 0;
}