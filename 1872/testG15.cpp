#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define int long long
#define pb push_back
#define pii pair<int,int>
#define F first
#define S second
const int maxn=5e5;
vector<int> ans,val;
int a[maxn],sum[maxn];
int32_t main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin>>t;
	while(t--){
        ans.clear(); val.clear();
        int n; cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            sum[i]=sum[i-1]+a[i];
        }
        for(int i=1;i<=n;i++)
            if(a[i]!=1) ans.pb(i);
        int sz=ans.size(),l=1,r=1;
        if(sz >= 20)
            l = ans[0], r = ans[sz-1];
        else{
            int mx=0,is=0;
            for(int i=0;i<sz;i++){
                int now=1;
                for(int j=i;j<sz;j++){
                    now*=a[ans[j]];
                    if(mx < (now-sum[ans[j]]+sum[ans[i]-1])){
                        mx = now-sum[ans[j]]+sum[ans[i]-1];
                        l = ans[i] , r = ans[j];
                    }
                    if(mx > 1e9) is=1;
                }
                if(is) break;
            }
            if(is)
                l = ans[0], r = ans[sz-1];
        }
        cout<<l<<' '<<r<<'\n';
	}

	return 0;
}
