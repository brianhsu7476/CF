void topoSort(int n, vi *G, vi &res){
	static int deg[kN], stk[kN];
	int ns=0;
	res.clear();
	rep(i, n)deg[i]=0;
	rep(i, n)for(int j:G[i])++deg[j];
	rep(i, n)if(!deg[i])stk[ns++]=i;
	while(ns){
		int x=stk[--ns];
		res.pb(x);
		for(int u:G[x])if(!--deg[u])stk[ns++]=u;
	}
}
