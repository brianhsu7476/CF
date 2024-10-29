#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

#define kN 100005
int n, a[kN], s[kN];

signed main(){
	ios::sync_with_stdio(0), cin.tie(0);
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=0; i<n; ++i)cin>>a[i];
		s[0]=0;
		for(int i=0; i<n; ++i)s[i+1]=s[i]+a[i];
		set<int> S;
		int ans=0;
		for(int i=0; i<=n; ++i){
			if(S.find(s[i])!=S.end())++ans, S.clear();
			S.insert(s[i]);
		}
		cout<<ans<<endl;
	}
}
