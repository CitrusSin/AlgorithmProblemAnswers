#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define x first
#define y second
#define mp make_pair

typedef pair<int,int> PII;
const int N=2e6+10;
const int mod1=1e9+7,mod2=1e9+9;
PII P={13331,23333};
PII p[N];
PII h[N];
PII t[N];
int n;
 
PII operator + (PII h1,PII h2){
	int x=h1.x+h2.x;
	int y=h1.y+h2.y;
	if(x>=mod1)	x-=mod1;
	if(y>=mod2)	y-=mod2;
	return mp(x,y);
}

PII operator - (PII h1,PII h2){
	int x=h1.x-h2.x;
	int y=h1.y-h2.y;
	if(x<0)	x+=mod1;
	if(y<0)	y+=mod2;
	return mp(x,y);
}

PII operator * (PII h1,PII h2){
	int x=h1.x*h2.x%mod1;
	int y=h1.y*h2.y%mod2;
	return mp(x,y);
}

vector<int> kmp_next(const string& pat) {
    int n = pat.size();
    vector<int> next(n+1);
    next[0] = -1;
    for (int i=1, j=0; i<=n; i++, j++) {
        next[i] = j;
        if (i < n) {
            while (j >= 0 && pat[i] != pat[j]) {
                j = next[j];
            }
        }
    }
    return next;
}

PII get1(int l,int r){
	return h[r]-h[l-1]*p[r-l+1];
}

PII get2(int l,int r){
	return t[l]-t[r+1]*p[r+1-l];
}

bool check(int l,int r){
	int mid=l+r>>1;
    PII a = get1(l, mid);
    PII b = get2(l, mid);
	if(a==b)	return true;
	return false;
}

void solve() {
    string s;
    cin >> s;
	
    int n = s.size();
	
	string ss=" "+s;
	p[0]=mp(1,1);
	for(int i=1;i<=n;i++){
		h[i]=h[i-1]*P+mp(ss[i],ss[i]);
		p[i]=p[i-1]*P;
	}
	for(int i=n;i>=1;i--)	t[i]=t[i+1]*P+mp(ss[i],ss[i]);//倒过来存s[i] 
	
    vector<int> next = kmp_next(s);
    
    set<pair<int, int>> areas;
    for (int i=0; i<n; i++) {
        int prev = next[i+1]-1;
        int len = i - prev;
        if (len * 2 <= i+1) {
            int l = i+1-len*2, r=i;
            if (check(l+1, r+1)) {
                areas.emplace(l, r);
            }
        }
    }

    for (const pair<int, int>& p : areas) {
        cout << p.first << ' ' << p.second << endl;
    }

    unordered_map<int, set<pair<int, int>>> query;
    for (const pair<int, int>& p : areas) {
        query[p.first].emplace(p);
    }

    int total_counter = 0;
    while (!areas.empty()) {
        pair<int, int> region = *areas.begin();
        int len = (region.second - region.first + 1)/2;
        int counter = 2;
        for (int i=1; region.first + len*i + len <= n; i++) {
            pair<int, int> r2(region.first + len * i, region.second + len * i);
            if (query[r2.first].count(r2)) {
                counter++;
                areas.erase(r2);
                query[r2.first].erase(r2);
            }
        }
        areas.erase(region);
        
    }

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}