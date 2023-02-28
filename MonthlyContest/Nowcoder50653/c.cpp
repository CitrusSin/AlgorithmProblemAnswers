/*
链接：https://ac.nowcoder.com/acm/contest/50653/C
来源：牛客网

题目描述
现在有n个人 编号从0开始(0,1,…,n−1)(0,1,…,n−1)  这n个人之间存在一些关系 确保这些关系形成一棵树
有关系的这些人会相互传染病毒 相互之间不存在关系的则不会相互传染 且不会重复感染 已被感染的人也不会被治愈
被感染的人一天之后才能继续感染其他人
现在出现了0号病人 即下标为0的人被感染 且这个病人第二天才能感染其他人
现在有多次询问 
查询第x天有多少人被感染

输入描述:
第1行为正整数n(1≤n≤105)(1≤n≤105)
第2行有 n-1个数字 第i个数字 aiai​ 表示ii 与 aiai​ 有关系 确保 (ai<i)(ai​<i)
第3行为正整数q代表有q次查询
接下来q行 每行有一个正整数 x(1≤x≤105)x(1≤x≤105) 

输出描述:
对于每一行的x输出一个整数
表示第x天有多少人感染
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    
    vector< vector<int> > fw_lst(n);
    for (int i=1; i<=n-1; i++) {
        int j;
        cin >> j;
        fw_lst[i].push_back(j);
        fw_lst[j].push_back(i);
    }
    vector<char> status(n, 0);
    vector<size_t> day_simu_cnt;
    deque<int> bfsq;
    
    // No.0 patient
    bfsq.push_back(0);
    status[0] = 1;
    day_simu_cnt.push_back(1);
    // BFS
    while (!bfsq.empty()) {
        size_t s = bfsq.size();
        while (s--) {
            int idx = bfsq.front();
            bfsq.pop_front();
            for (int np : fw_lst[idx]) {
                if (!status[np]) {
                    bfsq.push_back(np);
                    status[np] = 1;
                }
            }
        }
        day_simu_cnt.push_back(bfsq.size() + day_simu_cnt.back());
    }
    
    size_t day_cnt = day_simu_cnt.size();
    
    int q;
    cin >> q;
    while (q--) {
        int x;
        cin >> x;
        x--;
        if (x >= day_cnt) {
            cout << day_simu_cnt.back() << endl;
        } else {
            cout << day_simu_cnt[x] << endl;
        }
    }
    return 0;
}