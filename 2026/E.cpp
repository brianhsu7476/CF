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
#define SZ(a) (int)(a).size()
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
#define N 102

struct Bipartite_Matching { // 0-base
  int mp[N], mq[N], dis[N + 1], cur[N], l, r;
  vector<int> G[N + 1];
  bool dfs(int u) {
    for (int &i = cur[u]; i < SZ(G[u]); ++i) {
      int e = G[u][i];
      if (mq[e] == l || (dis[mq[e]] == dis[u] + 1 && dfs(mq[e])))
        return mp[mq[e] = u] = e, 1;
    }
    return dis[u] = -1, 0;
  }
  bool bfs() {
    queue<int> q;
    fill_n(dis, l + 1, -1);
    for (int i = 0; i < l; ++i)
      if (!~mp[i])
        q.push(i), dis[i] = 0;
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      for (int e : G[u])
        if (!~dis[mq[e]])
          q.push(mq[e]), dis[mq[e]] = dis[u] + 1;
    }
    return dis[l] != -1;
  }
  int matching() {
    int res = 0;
    fill_n(mp, l, -1), fill_n(mq, r, l);
    while (bfs()) {
      fill_n(cur, l, 0);
      for (int i = 0; i < l; ++i)
        res += (!~mp[i] && dfs(i));
    }
    return res; // (i, mp[i] != -1)
  }
  void add_edge(int s, int t) { G[s].pb(t); }
  void init(int _l, int _r) {
    l = _l, r = _r;
    for (int i = 0; i <= l; ++i)
      G[i].clear();
  }
}bm;

int n, m=60;
vector<int> a;

signed main(){
	ios::sync_with_stdio(0), cin.tie(0);
	int T; cin>>T;
	while(T--){
		cin>>n, a.resize(n);
		for(int i=0; i<n; ++i)cin>>a[i];
		while(1){
			n=a.size();
			bm.init(m, n);
			int m0=0, x=0;
			for(int i=0; i<n; ++i)x|=a[i];
			for(int i=0; i<m; ++i)if(x>>i&1)++m0;
			for(int i=0; i<n; ++i)for(int j=0; j<m; ++j)if(a[i]>>j&1)bm.add_edge(j, i);
			if(bm.matching()==m0)break;
			for(int j=0; j<m; ++j)if(bm.mp[j]==-1){
				vector<int> b;
				for(int i:a)if(!(i>>j&1))b.pb(i);
				a.clear();
				for(int i:b)a.pb(i);
			}
		}
		int m0=0, x=0;
		for(int i:a)x|=i;
		for(int i=0; i<m; ++i)if(x>>i&1)++m0;
		orange(a.begin(), a.end());
		debug(x);
		cout<<a.size()-m0<<endl;
	}
}
