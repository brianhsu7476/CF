#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

#define kN 1000006
int a[kN], n, l[kN];

signed main(){
	ios::sync_with_stdio(0), cin.tie(0);
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=0; i<n; ++i)cin>>a[i], --a[i], l[i]=-1;
		int ans=0;
		for(int i=0; i<n; ++i)if(!~l[i]){
			l[i]=1;
			int cur=a[i];
			while(cur!=i)l[cur]=0, cur=a[cur], ++l[i];
			ans+=l[i]-1>>1;
		}
		//for(int i=0; i<n; ++i)cout<<l[i]<<" \n"[i==n-1];
		cout<<ans<<endl;
	}
}
