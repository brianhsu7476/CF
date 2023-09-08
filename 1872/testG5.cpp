#include<bits/stdc++.h>
using namespace std;
#define int long long
int t,n,a[200005],b[200005],l,r;
void work(){
    l = r = 1;
    cin >> n;vector<int> acc;int res = 1,sm = 0,ans = 0;
    for(int i = 1;i <= n;i ++) cin >> a[i],b[i] = 0;
    for(int i = 1;i <= n;i ++) if(a[i] != 1) r = i,acc.push_back(i);
    for(int i = n;i >= 1;i --) if(a[i] != 1) l = i;
    for(int i = 1;i <= n;i ++){
        res *= a[i];
        if(res > 2e15) return cout << l << " " << r << "\n",void();
    }
    for(int i = 1;i <= n;i ++) b[i] = b[i-1] + a[i];
    for(int i = 0;i < acc.size();i ++){
        for(int j = i,tl = acc[i],tr,v,tres = 1,ts = 0;j < acc.size();j ++){
            tr = acc[j],tres *= a[tr],v = b[n]-b[tr]+b[tl-1]+tres;
            if(v > ans) ans = v,l = tl,r = tr; 
        }
    }cout << l << " " << r <<  "\n";
}
signed main(){
    cin >> t;
    while(t --) work();
}
