#include <bits/stdc++.h>
using namespace std;

struct fire {
    int b;
    int e;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    vector<fire> seg_arr(n);
    for (int i=0; i<n; i++) {
        cin >> seg_arr[i].b >> seg_arr[i].e;
    }
    
    sort(seg_arr.begin(), seg_arr.end(), [](fire& a, fire& b){
        return a.b < b.b;
    });
    
    int total_len = 0, lst = -2147483647;
    for (int i=0; i<n; i++) {
        int l = max(lst, seg_arr[i].b);
        total_len += max(0, seg_arr[i].e - l);
        lst = max(lst, seg_arr[i].e);
    }
    
    cout << total_len << endl;
    return 0;
}