#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

#define oo 1000000007
#define kN 200005
#define kL 20
int p[kN][kL], n, dep[kN], pd[kN], mx[kN][kL];
vector<int> G[kN], ds[kN];

void dfs(int x, int P){
	p[x][0]=P, dep[x]=x?dep[P]+1:0;
	ds[x].push_back(0);
	for(int u:G[x])if(u!=P)dfs(u, x), ds[x].push_back(ds[u][0]+1);
	sort(ds[x].begin(), ds[x].end());
	reverse(ds[x].begin(), ds[x].end());
	for(int i=1; i<kL; ++i)p[x][i]=p[p[x][i-1]][i-1];
}

void dfs1(int x){
	if(!x)pd[x]=-oo;
	else pd[x]=ds[p[x][0]][0]+1;
	if(pd[x]==ds[x][0]+2)pd[x]=ds[p[x][0]][1]+1;
	mx[x][0]=pd[x];
	for(int i=1; i<kL; ++i){
		if(!x)mx[x][i]=-oo;
		else mx[x][i]=max(mx[x][i-1], mx[p[x][i-1]][i-1]+(1<<i-1));
		//if((1<<i-1)>dep[x])mx[x][i]=mx[x][i-1];
	}
	for(int u:G[x])if(u!=p[x][0])dfs1(u);
}

int query(int x, int k){
	k=min(k, dep[x]);
	int j=0, res=0, now=x;
	for(int i=0; i<kL; ++i)if(k>>i&1)res=max(res, j+mx[now][i]), now=p[now][i], j+=1<<i;
	//return res;
	return max(res, ds[x][0]);
}

signed main(){
	//ios::sync_with_stdio(0), cin.tie(0);
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=0; i<n; ++i)G[i].clear(), ds[i].clear();
		for(int i=0; i<n-1; ++i){
			int u, v; cin>>u>>v, --u, --v;
			G[u].push_back(v), G[v].push_back(u);
		}
		dfs(0, 0);
		dfs1(0);
		/*for(int i=0; i<n; ++i){
			cout<<i+1<<": ";
			for(int j=0; j<n; ++j)cout<<query(i, j)<<" \n"[j==n-1];
		}*/
		//for(int i=0; i<n; ++i)cout<<dep[i]<<" \n"[i==n-1];
		int q; cin>>q;
		while(q--){
			int v, k;
			cin>>v>>k, --v;
			cout<<query(v, k)<<' ';
		}
		cout<<endl;
	}
}
