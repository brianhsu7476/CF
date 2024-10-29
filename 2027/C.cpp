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

#define oo 1000000007
#define mod 1000000007
#define kN 1000006

int n, a[kN], b[kN];
vector<int> c;
vector<int> G[kN];
bool vis[kN];

int id(int x){
	return lower_bound(c.begin(), c.end(), x)-c.begin();
}

int dfs(int x){
	vis[x]=1;
	int res=c[x];
	for(int u:G[x])if(!vis[u])res=max(res, dfs(u));
	return res;
}

signed main(){
	ios::sync_with_stdio(0), cin.tie(0);
	int T; cin>>T;
	while(T--){
		cin>>n;
		for(int i=0; i<n; ++i)cin>>a[i], b[i]=a[i]-n+i;
		c.clear();
		for(int i=0; i<n; ++i)if(b[i]>=0)c.pb(b[i]), c.pb(b[i]+i);
		sort(c.begin(), c.end());
		c.resize(unique(c.begin(), c.end())-c.begin());
		int m=c.size();
		for(int i=0; i<m; ++i)G[i].clear(), vis[i]=0;
		for(int i=0; i<n; ++i)if(b[i]>=0)G[id(b[i])].pb(id(b[i]+i));
		for(int i=0; i<m; ++i)orange(G[i].begin(), G[i].end());
		orange(c.begin(), c.end());
		if(c[0])cout<<n<<endl;
		else cout<<n+dfs(0)<<endl;
	}
}
