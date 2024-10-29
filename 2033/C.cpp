#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

#define kN 100005
int n, a[kN];

signed main(){
	ios::sync_with_stdio(0), cin.tie(0);
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=0; i<n; ++i)cin>>a[i];
		for(int i=1; i<n/2; ++i)if(a[i]==a[i-1]||a[n-1-i]==a[n-i])swap(a[i], a[n-1-i]);
		int ans=0;
		for(int i=0; i<n-1; ++i)ans+=a[i]==a[i+1];
		//for(int i=0; i<n; ++i)cout<<a[i]<<" \n"[i==n-1];
		cout<<ans<<endl;
	}
}
