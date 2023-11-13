#include <bits/stdc++.h>

using namespace std;

const int N = 2e6;
int da[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }

    //map<int, int> mapd;
    int max_idx = 0;
    for (int a : arr) {
        //array<bool, 20> ab = int_to_bits<20>(a), xb = {};
        int ab = a, xb = 0;
        for (int i=19; i>=0; i--) {
            //if (kb[i]) {
            if (k & (1<<i)) {
                //xb[i] = ab[i];
                xb &= ~(1<<i);
                xb |= (1<<i) & ab;
                //int min_val = bits_to_int<20>(xb);
                int min_val = xb;
                int max_val = min_val + ~((-1)<<i);
                //mapd[min_val]++;
                //mapd[max_val+1]--;
                da[min_val]++;
                da[max_val+1]--;
                if (max_val+1 > max_idx) max_idx = max_val+1;
                //xb[i] = !ab[i];
                xb &= ~(1<<i);
                xb |= (1<<i) & (~ab);
            } else {
                //xb[i] = ab[i];
                xb &= ~(1<<i);
                xb |= (1<<i) & ab;
            }
        }
        //mapd[a^k]++;
        //mapd[(a^k)+1]--;
        da[a^k]++;
        da[(a^k)+1]--;
        if ((a^k)+1 > max_idx) max_idx = (a^k)+1;
    }

    int max_cnt = 0, cnt = 0;
    //for (const pair<int, int>& p : mapd) {
    for (int i=0; i<=max_idx; i++) {
        //cnt += p.second;
        cnt += da[i];
        if (cnt > max_cnt) max_cnt = cnt;
    }

    cout << max_cnt << endl;
    return 0;
}