#include <bits/stdc++.h>
#define deb(val) cout<<#val<<":"<<val<<endl;
using namespace std;
const int N=2e5+10,M=4e5+10;
int e[M],ne[M],h[N];
int idx;
void add(int a,int b){
    e[idx]=b;
    ne[idx]=h[a];
    h[a]=idx++;
}
int l[N];
int bl[N];
int f[N];
bool lx[N];
bool bx[N];
void dfs(int x,int fa){
    f[x]=fa;
    int pl=1;
    int pb=0;
    for(int i=h[x];i!=-1;i=ne[i]){
        int j=e[i];
        if(j!=fa){
            dfs(j,x);
        pl+=min(l[j],bl[j]);
        pb+=l[j];
        }
    }
    l[x]=pl;
    bl[x]=pb;
}
int iiddx;
void ddfs(int x,int fa,int zhi){
    iiddx++;
    if(zhi==1){
        int mi=min(l[x],bl[x]);
        if(mi==l[x]){
            if(lx[x]==true){
                ;
            }else{
            lx[x]=true;
            for(int i=h[x];i!=-1;i=ne[i]){
                if(e[i]!=fa)
                ddfs(e[i],x,1);
            }
            }
        }
        if(mi==bl[x]){
            if(bx[x]==true){
                ;
            }else{
            bx[x]=true;
            for(int i=h[x];i!=-1;i=ne[i]){
                if(e[i]!=fa)
                ddfs(e[i],x,0);
            }
            }
        }
    }
    if(zhi==0){
        if(lx[x]==true){
            ;
        }else{
        lx[x]=true;
        for(int i=h[x];i!=-1;i=ne[i]){
            int j=e[i];
            if(j!=fa){
                ddfs(j,x,1);
            }
        }
        }
    }
}
int a[N];
int b[N];
void solve() {
    int n;
    scanf("%d",&n);
    idx=0;
    for(int i=1;i<=n;i++){
        h[i]=-1;
        lx[i]=false;
        bx[i]=false;
    }
    for(int i=1;i<n;i++){
        scanf("%d%d",&a[i],&b[i]);
        add(a[i],b[i]);
        add(b[i],a[i]);
    }
    dfs(1,0);
    ddfs(1,0,1);
    int ans=min(l[1],bl[1]);
    for(int i=1;i<n;i++){
        int pa=a[i];
        int pb=b[i];
        if(f[pa]!=pb){
            swap(pa,pb);
        }
        //pb fu
        int mi=min(l[pb],bl[pb]);
        int nans=0;
        for(int i=h[pb];i!=-1;i=ne[i]){
            int j=e[i];
            if(j!=f[pb]){
                if(j==pa){
                    nans+=min(l[pa],bl[pa]);
                }else{
                    nans+=l[j];
                }
            }
        }
        if(nans<mi&&bx[pb]==true){
            printf("%d ",n-ans+1);
        }else{
            printf("%d ",n-ans);
        }
    }
    printf("\n");
    // deb(iiddx);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}