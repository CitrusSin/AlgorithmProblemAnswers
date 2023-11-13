#include <bits/stdc++.h>

using namespace std;

#define int long long
#define l first
#define r second
#define mp make_pair

typedef pair<int,int> PII;
const int N=1010,mod = 998244353;
int a[N][N],n;
int qmi(int a,int b)
{
	int res = 1;
	while(b)
	{
		if(b&1) res = res*a%mod;
		a = a*a%mod;
		b >>= 1;
	}
	return res;
}
void solve(){	
	cin >> n;
	int x = (int)sqrt(n);
	int a = n%mod;
	int b = (n+1)%mod;
	int c = (2*n+1)%mod;
	int ans = 0;
	ans =  b*((a-x+mod)%mod)%mod*((n+x+1)%mod)%mod*qmi(2,mod-2)%mod + x*(x+1)%mod*(x*2+1)*qmi(6,mod-2)%mod - a*b%mod*c%mod*qmi(6,mod-2)%mod;
	ans = (ans+mod)%mod;
	cout << ans;
	int j = 1;
	while(1)
	{
		int r = qmi(j,2);
		int l = qmi(j,1);
		if(l > x) break;
		if(r > n) r = n+1;
		ans = (ans+(r-l)*j%mod)%mod;
		j++;
	}
	cout << x;
	for(int i = 2;i <= x;i++)
	{
		int tmp = 0;
		int j = 2;
		while(1)
		{
			int r = qmi(j,i+1);
			int l = qmi(j,i);
			if(l > n) break;
			if(r > n) r = n+1;
			tmp = (tmp+(r-l)*j%mod)%mod;
			j++;
		}
		ans = (ans+tmp*i%mod)%mod;
	}
	cout << ans;
}

signed main(){
	//ios::sync_with_stdio(0);
	//cin.tie(0),cout.tie(0);
//	cout<<fixed<<setprecision(12);
	int T=1;
//	cin>>T;
	while(T--)	solve();
	return 0;
}