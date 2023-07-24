#include <bits/stdc++.h>

using namespace std;

#define int long long 
#define x first
#define y second

typedef pair<int,int> PII;
const int N=2e5+10;
int n,m,k;
int a[N];
vector<set<int> > st;
int dp[N][3];//0 mei 1 you 2 xinhao
bool leaf_flag[N];

void dfs(int u,int fa){
	int flag=0;
    set<int> childs;
	for(int ver : st[u]){
		if(ver==fa)	continue;
		dfs(ver,u);
		flag=1;
        childs.insert(ver);
	}
	if(!flag){
        leaf_flag[u] = true;
		dp[u][1]=a[u];
		dp[u][0]=0;
        dp[u][2]=1e13;
	} else {
        dp[u][0] = 0;
        for (int ch : childs) {
            if (leaf_flag[ch]) {
                dp[u][0] += a[ch];
                continue;
            }
            dp[u][0] += dp[ch][2];
        }
        dp[u][1] = a[u];
        for (int ch : childs) {
            dp[u][1] += min(min(dp[ch][0], dp[ch][1]), dp[ch][2]); 
        }
        dp[u][2] = 0;
        int min_increment = numeric_limits<int>::max();
        for (int ch : childs) {
            if (leaf_flag[ch]) {
                dp[u][2] += a[ch];
                min_increment = 0;
                continue;
            }
            if (dp[ch][1] <= dp[ch][2]) {
                min_increment = 0;
                dp[u][2] += dp[ch][1];
                continue;
            }
            dp[u][2] += dp[ch][2];
            min_increment = min(min_increment, dp[ch][1] - dp[ch][2]);
        }
        dp[u][2] += min_increment;
    }
}
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++)	dp[i][0]=dp[i][1]=dp[i][2]=0;
	for(int i=1;i<=n;i++)	cin>>a[i];
    for (int i=1; i<=n; i++) leaf_flag[i] = false;
	st=vector<set<int> >(n+10);
	for(int i=1;i<=n-1;i++){
		int x,y;
		cin>>x>>y;
		st[x].insert(y);
		st[y].insert(x);
	}
	dfs(1,1);
	cout<<min(dp[1][1],dp[1][2])<<'\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cout<<fixed<<setprecision(12);
	int T=1;
    cin>>T;
    while(T--)	solve();
    return 0;
}