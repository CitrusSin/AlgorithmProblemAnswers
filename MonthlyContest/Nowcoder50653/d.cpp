/*
链接：https://ac.nowcoder.com/acm/contest/50653/D
来源：牛客网

题目描述
简单的统计题，给出 n 个数，统计区间和是114514的倍数的区间个数。

输入描述:
第一行一个整数 n，表示数字个数。
第二行 n 个数字，a1 ...... an。

输出描述:
一个整数，表示区间和是114514的倍数的区间个数。
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int rem_cnt[114514] = {};
    
    int n;
    cin >> n;
    
    int total_cnt = 0, last_rem = 0;
    for (int i=0; i<n; i++) {
        int rem;
        cin >> rem;
        rem += last_rem;
        rem %= 114514;
        last_rem = rem;
        
        if (rem == 0) total_cnt++;
        total_cnt += rem_cnt[rem];
        rem_cnt[rem]++;
    }
    
    cout << total_cnt << endl;
    return 0;
}