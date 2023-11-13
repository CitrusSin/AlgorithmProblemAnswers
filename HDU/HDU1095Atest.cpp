#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;

int mex(const unordered_set<int>& values) {
    int s = values.size(), i=0;
    while (i < s) {
        if (!values.count(i)) {
            return i;
        }
        i++;
    }
    return i;
}

int k = 0;
unordered_map<int, int> memory;
int sg(int x) {
    if (x <= k) return x != 0;
    if (memory.count(x)) return memory[x];
    
    unordered_set<int> values;
    int lim = x-k;
    for (int i=1; i<=lim-i; i++) {
        values.insert(sg(i)^sg(lim-i));
    }

    return memory[x] = mex(values);
}

int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (k=2; k<=10; k++) {
        memory.clear();
        cout << k << ": ";
        int last_x = 0;
        for (int x=1; x<=1000; x++) {
            if (sg(x) == 0) {
                cout << (x-last_x) << ' ';
                last_x = x;
            }
        }
        cout << endl;
    }
    return 0;
}