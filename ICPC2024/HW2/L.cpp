#include <bits/stdc++.h>
#define ll long long
#define int long long
using namespace std;
#define mod 1000000007
#define kN 100005
#define klog 20

/* x: a[j], y: a[j + (L >> 1)]
or: (y += x * op), and: (x += y * op)
xor: (x, y = (x + y) * op, (x - y) * op)
invop: or, and, xor = -1, -1, 1/2 */
void fwt(ll *a, int n, ll op) { //or
  for (int L = 2; L <= n; L <<= 1)
    for (int i = 0; i < n; i += L)
      for (int j = i; j < i + (L >> 1); ++j){
        ll x=a[j], y=a[j+(L>>1)];
		if(~op)a[j]=(x+y)*op, a[j+(L>>1)]=(x-y)*op;
		else a[j]=x+y>>1, a[j+(L>>1)]=x-y>>1;
		//a[j + (L >> 1)] += a[j] * op;
      }
}
/*const int N = 21;
ll f[N][1 << N], g[N][1 << N], h[N][1 << N], ct[1 << N];
void subset_convolution(ll *a, ll *b, ll *c, ll L) {
  // c_k = \sum_{i | j = k, i & j = 0} a_i * b_j
  int n = 1 << L;
  for (int i = 1; i < n; ++i)
    ct[i] = ct[i & (i - 1)] + 1;
  for (int i = 0; i < n; ++i)
    f[ct[i]][i] = a[i], g[ct[i]][i] = b[i];
  for (int i = 0; i <= L; ++i)
    fwt(f[i], n, 1), fwt(g[i], n, 1);
  for (int i = 0; i <= L; ++i)
    for (int j = 0; j <= i; ++j)
      for (int x = 0; x < n; ++x)
        h[i][x] += f[j][x] * g[i - j][x];
  for (int i = 0; i <= L; ++i)
    fwt(h[i], n, -1);
  for (int i = 0; i < n; ++i)
    c[i] = h[ct[i]][i];
}*/

int m, C, n, p[kN], y[kN], c[kN], dep[kN], anc[kN][klog], bitv[kN*2], bit[kN*2], in[kN], out[kN];
ll cng[1<<(klog+1)], pt[1<<(klog+1)], cnt[1<<(klog+1)], res[1<<(klog+1)];
vector<int> G[kN];

void upd(int x, int v){
	for(int i=x+1; i<=n*2+1; i+=i&-i)bit[i]^=v;
}

int qry(int x){
	int res=0;
	for(int i=x+1; i; i-=i&-i)res^=bit[i];
	return res;
}

void init(){
	//for(int i=1; i<=n*2+1; ++i)bit[i]=0;
	for(int i=0; i<=n*2; ++i)upd(i, i?bitv[i-1]^bitv[i]:bitv[0]);
}

void dfs0(int x, int p){
	static int cnt=0;
	in[x]=cnt++, bitv[in[x]]=(1<<c[x])^(~p?bitv[in[p]]:0);
	anc[x][0]=~p?p:x;
	dep[x]=~p?dep[p]+1:0;
	for(int i=1; i<klog; ++i)anc[x][i]=anc[anc[x][i-1]][i-1];
	for(int u:G[x])if(u!=p)dfs0(u, x);
	out[x]=cnt++;
}

int par(int x, int d){
	for(int i=0; i<klog; ++i)if(d>>i&1)x=anc[x][i];
	return x;
}

int lca(int x, int y){
	if(dep[x]<dep[y])y=par(y, dep[y]-dep[x]);
	else x=par(x, dep[x]-dep[y]);
	if(x==y)return x;
	for(int i=klog-1; i>=0; --i)if(anc[x][i]!=anc[y][i])x=anc[x][i], y=anc[y][i];
	return anc[x][0];
}

void modify(int x, int v){
	upd(in[x], (1<<c[x])^(1<<v)), upd(out[x], (1<<c[x])^(1<<v));
	c[x]=v;
}

int ans(int x, int y){
	return qry(in[x])^qry(in[y])^(1<<c[lca(x, y)]);
}

ll point(int v){
	int cnt=0;
	vector<int> a;
	for(int i=0; i<C; ++i)if(v>>i&1)a.push_back(p[i]);
	if(!a.size())return 0;
	if(a.size()==1)return a[0];
	int res=__gcd(a[0], a[1]);
	for(int i=2; i<a.size(); ++i)res=__gcd(res, a[i]);
	return res;
}

signed main(){
	ios::sync_with_stdio(0), cin.tie(0);
	cin>>m>>C>>n;
	for(int i=0; i<C; ++i)cin>>p[i];
	for(int i=0; i<m; ++i){
		int x, z; cin>>x;
		for(int j=0; j<x; ++j)cin>>z, y[i]^=(1<<z);
	}
	for(int i=0; i<n; ++i)cin>>c[i];
	for(int i=0; i<n-1; ++i){
		int u, v;
		cin>>u>>v;
		G[u].push_back(v), G[v].push_back(u);
	}
	dfs0(0, -1);
	init();
	//for(int i=0; i<m; ++i)cout<<y[i]<<" \n"[i==m-1];
	//for(int i=0; i<n; ++i)cout<<bitv[in[i]]<<" \n"[i==n-1];
	//for(int i=0; i<n; ++i)cout<<qry(in[i])<<" \n"[i==n-1];
	for(int i=0; i<m; ++i){
		//cout<<"i: "; for(int i=0; i<n; ++i)cout<<qry(in[i])<<" \n"[i==n-1];
		int u, v, w, Y;
		cin>>u>>v>>w>>Y;
		cng[i]=ans(u, v);
		//pt[i]=point(ans(u, v)^y[i]);
		//cout<<lca(u, v)<<' '<<ans(u, v)<<endl;
		modify(w, Y);
	}
	for(int i=0; i<(1<<C); ++i)pt[i]=point(i);
	//for(int i=0; i<(1<<C); ++i)cout<<pt[i]<<" \n"[i==(1<<C)-1];
	for(int i=0; i<m; ++i)++cnt[y[i]];
	//for(int i=0; i<(1<<C); ++i)cout<<cnt[i]<<" \n"[i==(1<<C)-1];
	fwt(pt, 1<<C, 1), fwt(cnt, 1<<C, 1);
	for(int i=0; i<(1<<C); ++i)res[i]=pt[i]*cnt[i];
	fwt(res, 1<<C, -1);
	//subset_convolution(pt, cnt, res, C);
	//for(int i=0; i<(1<<C); ++i)cout<<res[i]<<" \n"[i==(1<<C)-1];
	int s=0;
	for(int i=0; i<m; ++i){
		s^=cng[i];
		cout<<res[s]%mod<<" \n"[i==m-1];
	}
	//for(int i=0; i<m; ++i)cout<<pt[i]<<" \n"[i==m-1];
	//s0[0]=s[0]=0;
	//for(int i=0; i<m; ++i)s0[i+1]=(s0[i]+pt0[i])%mod, s[i+1]=(s[i]+pt[i])%mod;
	//for(int i=0; i<m; ++i){
	//	int k=((s[i+1]+s0[m]-s0[i+1])%mod+mod)%mod;
	//	cout<<k<<" \n"[i==m-1];
	//}
}
