#include <bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
#define vi vector<int>
#define pb push_back
#define ins insert
#define pii pair<int, int>
#define mp(a,b) make_pair((a), (b))
#define all(a) (a).begin(), (a).end()
using namespace std;
#ifdef rmfr
#define safe cerr<<__PRETTY_FUNCTION__<<" line "<<__LINE__<<" safe\n"
#define debug(a...) debug_(#a, a)
#define orange(a...) orange_(#a, a)
template <typename ...T>
void debug_(const char *s, T ...a){
	cerr<<"\e[1;32m("<<s<<") = (";
	int cnt=sizeof...(T);
	(...,(cerr<<a<<(--cnt?", ":")\e[0m\n")));
}
template <typename I>
void orange_(const char *s, I L, I R){
	cerr<<"\e[1;32m[ "<<s<<" ] = [ ";
	for(int f=0; L!=R; ++L)cerr<<(f++?", ":"")<<*L;
	cerr<<" ]\e[0m\n";
}
#else
#define safe ((void)0)
#define debug(...) safe
#define orange(...) safe
#endif

const int oo=1000000000000015;
#define mod 1000000007
#define kN 300005

int n, m, a[kN], b[kN], sa[kN];
vector<int> dp[kN];

signed main(){
	ios::sync_with_stdio(0), cin.tie(0);
	int T; cin>>T;
	while(T--){
		cin>>n>>m;
		sa[0]=0;
		for(int i=0; i<n; ++i)cin>>a[i], sa[i+1]=sa[i]+a[i];
		for(int i=0; i<m; ++i)cin>>b[i];
		for(int i=0; i<=n; ++i)dp[i].resize(m+1);
		dp[0][0]=0;
		for(int i=1; i<=m; ++i)dp[0][i]=0;
		for(int i=0; i<n; ++i)for(int j=0; j<m; ++j){
			int l=lower_bound(sa, sa+n+1, sa[i+1]-b[j])-sa;
			if(l==i+1)dp[i+1][j]=oo;
			else dp[i+1][j]=dp[l][j]+m-j-1, debug(j, l);
			if(j)dp[i+1][j]=min(dp[i+1][j], dp[i+1][j-1]);
			dp[i+1][j]=min(dp[i+1][j], oo);
			if(j==m-1)orange(dp[i+1].begin(), dp[i+1].end());
		}
		int ans=oo;
		for(int j=0; j<m; ++j)ans=min(ans, dp[n][j]);
		if(ans==oo)cout<<-1<<endl;
		else cout<<ans<<endl;
	}
}
