#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        
        int alph_cnt[26] = {0};
        size_t n = s.size();
        int i = 0, j = 0, max_len = 0;
        while (j < n) {
            alph_cnt[s[j++]-'a']++;
            while (alph_cnt[s[j-1]-'a']>1) {
                alph_cnt[s[i++]-'a']--;
            }
            int len = j-i;
            if (len > max_len) max_len = len;
        }
        cout << max_len << endl;
    }
    return 0;
}