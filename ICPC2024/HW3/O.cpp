#include <bits/stdc++.h>
#define int long long
using namespace std;
#define oo 1000000007
#define INF oo
#define kN 52
#define MAXN kN*kN
#define pb push_back

struct MaxFlow { // 0-base
  struct edge {
    int to, cap, flow, rev;
  };
  vector<edge> G[MAXN];
  int s, t, dis[MAXN], cur[MAXN], n;
  int dfs(int u, int cap) {
    if (u == t || !cap) return cap;
    for (int &i = cur[u]; i < (int)G[u].size(); ++i) {
      edge &e = G[u][i];
      if (dis[e.to] == dis[u] + 1 && e.flow != e.cap) {
        int df = dfs(e.to, min(e.cap - e.flow, cap));
        if (df) {
          e.flow += df;
          G[e.to][e.rev].flow -= df;
          return df;
        }
      }
    }
    dis[u] = -1;
    return 0;
  }
  bool bfs() {
    fill_n(dis, n, -1);
    queue<int> q;
    q.push(s), dis[s] = 0;
    while (!q.empty()) {
      int tmp = q.front();
      q.pop();
      for (auto &u : G[tmp])
        if (!~dis[u.to] && u.flow != u.cap) {
          q.push(u.to);
          dis[u.to] = dis[tmp] + 1;
        }
    }
    return dis[t] != -1;
  }
  int maxflow(int _s, int _t) {
    s = _s, t = _t;
    int flow = 0, df;
    while (bfs()) {
      fill_n(cur, n, 0);
      while ((df = dfs(s, INF))) flow += df;
    }
    return flow;
  }
  void init(int _n) {
    n = _n;
    for (int i = 0; i < n; ++i) G[i].clear();
  }
  void reset() {
    for (int i = 0; i < n; ++i)
      for (auto &j : G[i]) j.flow = 0;
  }
  void add_edge(int u, int v, int cap) {
    G[u].pb(edge{v, cap, 0, (int)G[v].size()});
    G[v].pb(edge{u, 0, 0, (int)G[u].size() - 1});
  }
};

int n, m, k, c, p[kN][kN], b=1000006;

signed main(){
	ios::sync_with_stdio(0), cin.tie(0);
	cin>>n>>m>>k>>c;
	MaxFlow mf;
	int s=n*m, t=n*m+1;
	mf.init(n*m+2);
	for(int i=0; i<n; ++i)for(int j=0; j<m; ++j){
		int u=i*m+j;
		cin>>p[i][j];
		if(j)mf.add_edge(s, u, b-p[i][j]+p[i][j-1]), mf.add_edge(u, t, b), mf.add_edge(u-1, u, oo);
		else mf.add_edge(s, u, b-p[i][j]), mf.add_edge(u, t, oo);
	}
	for(int i=0; i<k; ++i){
		int u, v;
		cin>>u>>v, --u, --v;
		for(int j=0; j<m; ++j)mf.add_edge(u*m+j, v*m+j, c), mf.add_edge(v*m+j, u*m+j, c);
	}
	cout<<n*m*b-mf.maxflow(s, t)<<endl;
}
