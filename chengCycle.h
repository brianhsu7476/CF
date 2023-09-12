void chengCycle(int n, int *to, vi &res){ // res[x]<n: x is on cycle res[x], else x is on the tree rooted at res[x]-n
	static int deg[kN], stk[kN];
	static bool vis[kN];
	int ns=0;
	res.resize(n, -1);
	rep(i, n)deg[i]=vis[i]=0;
	rep(i, n)++deg[to[i]];
	rep(i, n)if(!deg[i])stk[ns++]=i;
	while(ns){
		int x=stk[--ns];
		vis[x]=1;
		if(!--deg[to[x]])stk[ns++]=to[x];
	}
	rep(i, n)if(!vis[i]){
		int x=i;
		do vis[x]=1, res[x]=i, x=to[x]; while(x!=i);
	}
	static vi inv[kN];
	rep(i, n)inv[i].clear();
	rep(i, n)if(!~res[i])inv[to[i]].pb(i); else stk[ns++]=i;
	while(ns){
		int x=stk[--ns];
		for(int u:inv[x])stk[ns++]=u, res[u]=res[x]<n?x+n:res[x];
	}
}
