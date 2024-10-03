#include <bits/stdc++.h>
//#define int long long
#define ll long long
#define kN 1503
using namespace std;

int n, x[kN], y[kN], ans[kN], sz[kN], inv[kN];
vector<int> G[kN], child[kN];

bool tri(int a, int b, int c){
	ll dx0=(ll)x[b]-(ll)x[a], dy0=(ll)y[b]-(ll)y[a];
	ll dx1=(ll)x[c]-(ll)x[a], dy1=(ll)y[c]-(ll)y[a];
	return dx0*dy1>dx1*dy0;
}

int dfs0(int x, int p){
	for(int u:G[x])if(u!=p)sz[x]+=dfs0(u, x);
	return ++sz[x];
}

void dfs1(int x, int p){
	sort(child[x].begin(), child[x].end(), [&](int u, int v){
		return tri(ans[x], u, v);
	});
	assert(child[x].size()==sz[x]-1);
	for(int i=0; i<(int)child[x].size()-1; ++i)assert(tri(ans[x], child[x][i], child[x][i+1]));
	if(child[x].size()>1)assert(tri(ans[x], child[x][0], child[x][child[x].size()-1]));
	//cout<<x<<' '<<ans[x]<<endl;
	//for(int u:child[x])cout<<u<<' '; cout<<endl;
	//cout<<"-----\n";
	int cur=0;
	for(int u:G[x])if(u!=p){
		ans[u]=child[x][cur];
		for(int i=1; i<sz[u]; ++i)child[u].push_back(child[x][cur+i]);
		cur+=sz[u];
		dfs1(u, x);
	}
	//for(int u:G[x])if(u!=p)dfs1(u, x);
}

signed main(){
	cin>>n;
	for(int i=0; i<n-1; ++i){
		int u, v;
		cin>>u>>v, --u, --v;
		G[u].push_back(v), G[v].push_back(u);
	}
	for(int i=0; i<n; ++i)cin>>x[i]>>y[i];
	dfs0(0, -1);
	int root=0;
	for(int i=1; i<n; ++i)if(x[i]<x[root])root=i;
	ans[0]=root;
	for(int i=0; i<n; ++i)if(i!=root)child[0].push_back(i);
	dfs1(0, -1);
	for(int i=0; i<n; ++i)inv[ans[i]]=i;
	for(int i=0; i<n; ++i)cout<<inv[i]+1<<" \n"[i==n-1];
}
