namespace lca{
	int n, rt, in[kN], out[kN], anc[kN][kL], l;
	int ans[kN][kL];
	vi *G;
	void dfs(int x, int p){
		static int t;
		t=~p?t+1:0, anc[x][0]=~p?p:x, in[x]=t;
		fup(i, 1, l)anc[x][i]=anc[anc[x][i-1]][i-1];
		ans[x][0]=~p?1:0;
		fup(i, 1, l)ans[x][i]=ans[x][i-1]+ans[anc[x][i-1]][i-1];
		for(int u:G[x])dfs(u, x);
		out[x]=++t;
	}
	void build(int nn, vi *GG, int root){
		n=nn, G=GG, rt=root, l=__lg(n)+1, dfs(rt, -1);
	}
	bool isa(int x, int y){return in[x]<=in[y]&&out[x]>=out[y];}
	int lca(int x, int y){
		if(isa(x, y))return x;
		if(isa(y, x))return y;
		fdn(i, l-1, -1)if(!isa(anc[x][i], y))x=anc[x][i];
		return anc[x][0];
	}
	int qry(int x, int y){
		auto f=[](int x, int y){
			int res=0;
			fdn(i, l-1, -1)if(!isa(anc[x][i], y))res+=ans[x][i], x=anc[x][i];
			return res+=ans[x][0];
		};
		int res=0;
		if(!isa(x, y))res+=f(x, y);
		if(!isa(y, x))res+=f(y, x);
		return res;
	}
}
