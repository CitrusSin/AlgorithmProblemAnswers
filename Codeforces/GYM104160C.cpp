#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> PII;
const int N = 5e5+10;
int n,d,a[N];
vector<int> v;
void solve(){
	cin >> n >> d;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
		v.push_back(a[i]);
	}
	sort(v.begin(),v.end());
	v.push_back(v[0]-1);
	v.push_back(v[n-1]+1);
	sort(v.begin(),v.end());
	int ans = 0;
	for(auto i : v)
	{
		int l = i,r = i+d,tmp = 0;
		for(int j = 1;j < n;j++)
		{
			int x = a[j],y = a[j+1];
			if(a[j] < l) x = l;
			if(a[j] > r) x = r;
			if(a[j+1] < l) y = l;
			if(a[j+1] > r) y = r;
			tmp += abs(x-y);
		}
		ans = max(ans,tmp);
	}
	cout << ans;
}


signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--)	solve();
	return 0;
}