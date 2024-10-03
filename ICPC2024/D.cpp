#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<n; ++i)
#define pb push_back
using namespace std;
#define kN 1000006
#define kK 1003

struct edge{
	int u, v, w;
	edge(){}
	edge(int u, int v, int w):u(u), v(v), w(w){}
	bool operator<(const edge r)const{return w<r.w||w==r.w&&v<r.v;}
};

int n, a[kN], k, d[kK], c[kK][kK];
edge src[kK];
vector<edge> G[kK];
set<edge> b[11];

signed main(){
	cin>>n>>k;
	rep(i, n){
		cin>>a[i];
		int c=a[i], d=0;
		while(c)++d, c/=10;
		if(!d)++d;
		b[d].insert(edge(i, 0, a[i]%k));
	}
	int r[11];
	r[0]=1;
	rep(i, 10)r[i+1]=r[i]*10%k;
	for(int i=10; i>0; --i){
		for(edge j:b[i])rep(K, k)G[K].pb(edge(K, (K*r[i]+j.w)%k, i)), c[K][(K*r[i]+j.w)%k]=j.u;
	}
	rep(K, k)c[k][K]=c[0][K];
	for(edge i:G[0])G[k].pb(i);
	//rep(i, k+1){cout<<i<<": "; for(edge j:G[i])cout<<j.v<<','<<j.w<<' '; cout<<endl;}
	set<edge> S;
	S.insert(edge(k, k, 0));
	while(!S.empty()){
		edge x=*S.begin();
		S.erase(x);
		if(d[x.v])continue;
		d[x.v]=x.w, src[x.v]=edge(x.u, x.v, x.w-d[x.u]);
		for(edge i:G[x.v])if(!d[i.v])S.insert(edge(x.v, i.v, x.w+i.w));
	}
	if(!d[0]){cout<<"NO\n"; return 0;}
	//rep(i, k)cout<<d[i]<<" \n"[i==k-1];
	vector<edge> path;
	int now=0;
	while(now!=k)path.pb(src[now]), now=src[now].u;
	reverse(path.begin(), path.end());
	//for(edge i:path)cout<<i.u<<' '<<i.v<<' '<<i.w<<endl;
	//cout<<d[0]<<endl;
	cout<<"YES\n";
	for(edge i:path){
		cout<<a[c[i.u][i.v]];
	}
	cout<<endl;
}
