#include <bits/stdc++.h>
using namespace std;

const int N = 1e8+1;

bool vis[N];
int prime[N/2];
int cnt = 0;

void count(int n) {
    for (int i=2; i<=n; i++) {
        if (!vis[i]) prime[cnt++] = i;
        for (int j=0; j<cnt; j++) {
            if ((long long)i*prime[j] > n) break;
            vis[i*prime[j]] = true;
            if (i % prime[j] == 0) break;
        }
    }
}

int main() {
    int n;
    cin >> n;
    count(n);

    cout << cnt << endl;   
    return 0;
}