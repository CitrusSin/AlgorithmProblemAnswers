#include <bits/stdc++.h>

using namespace std;
void solve(){
    int n;
    cin>>n;
    string a;
    cin>>a;
    vector<int>a0;
    vector<int>a1;
    int len=a.length();
    for(int i=0;i<len;i++){
        if(a[i]=='0'){
            a0.push_back(i+1);
        }else{
            a1.push_back(i+1);
        }
    }
    vector<int>sm;
    vector<int>bi;
    if(a0.size()<a1.size()){
        sm=a0;
        bi=a1;
    }else{
        sm=a1;
        bi=a0;
    }
    if(sm.size()==0){
        for(int i=0;i<bi.size()-1;i++){
            cout<<bi[i]<<" "<<bi[i+1]<<endl;
        }
        cout<<bi[0]<<" "<<bi[bi.size()-1]<<endl;
    }else{
        if(sm.size()==1){
            for(int j=0;j<bi.size();j++){
                cout<<sm[0]<<" "<<bi[j]<<endl;
            }
            cout<<bi[0]<<" "<<bi[1]<<endl;
        }else{
            for(int j=0;j<bi.size();j++){
                cout<<sm[0]<<" "<<bi[j]<<endl;
            }
            for(int j=1;j<sm.size();j++){
                cout<<bi[0]<<" "<<sm[j]<<endl;
            }
            cout<<bi[1]<<" "<<sm[1]<<endl;
        }
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}