#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

#define kN 502
int a[kN][kN], n, b[kN*2];

signed main(){
	ios::sync_with_stdio(0), cin.tie(0);
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=0; i<n; ++i)for(int j=0; j<n; ++j)cin>>a[i][j];
		for(int i=0; i<n; ++i){
			b[i]=0;
			for(int j=0; j<=i; ++j)b[i]=min(b[i], a[j][n-1-i+j]);
		}
		for(int i=0; i<n-1; ++i){
			b[n+i]=0;
			for(int j=0; j<n-1-i; ++j)b[n+i]=min(b[n+i], a[i+1+j][j]);
		}
		int ans=0;
		for(int i=0; i<n*2-1; ++i)ans-=b[i];
		cout<<ans<<endl;
	}
}
