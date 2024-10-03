#include <bits/stdc++.h>
using namespace std;
#define kN 102

int n, m, p[kN], sz[kN];
vector<int> rt;
bool a[kN][kN], inv[kN];

int Find(int x){
	while(x!=p[x])x=p[x];
	return x;
}

bool Union(int x, int y){
	x=Find(x), y=Find(y);
	if(x==y)return 0;
	if(sz[x]>sz[y])swap(x, y);
	rt.push_back(x);
	p[x]=y, sz[y]+=sz[x];
	return 1;
}

void unUnion(){
	assert(rt.size());
	int x=rt[rt.size()-1], y=p[x];
	p[x]=x, sz[y]-=sz[x];
	rt.pop_back();
}

int dfs(int x){
	if(x==n)return rt.size()==n-1;
	int ret=0;
	inv[x]=0;
	for(int t=0; t<2; ++t){
		bool ok=1;
		int cnt=0;
		for(int i=0; i<x; ++i)if(a[i][x]^inv[i]^inv[x]){
			if(Union(i, x))++cnt;
			else{ok=0; break;}
		}
		if(ok)ret+=dfs(x+1);
		while(cnt--)unUnion();
		inv[x]=1;
	}
	return ret;
}

signed main(){
	cin>>n>>m;
	for(int i=0; i<n; ++i)p[i]=i, sz[i]=1;
	for(int i=0; i<m; ++i){
		int u, v;
		cin>>u>>v, --u, --v;
		a[u][v]=a[v][u]=1;
	}
	cout<<dfs(0)<<endl;
	//for(int i=0; i<n; ++i)cout<<p[i]<<' '<<sz[i]<<endl;
}
