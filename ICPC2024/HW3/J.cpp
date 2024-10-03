#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC optimize("no-math-errno,unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4")
//#pragma GCC target("popcnt,abm,mmx,avx,arch=skylake")

#include <bits/stdc++.h>
//#define int long long
#define ll long long
#define endl '\n'
using namespace std;
#define kN 50004
#define kM 100005

int ttcnt=0;

struct edge{
	int v, w;
	edge(){}
	edge(int v, int w):v(v), w(w){}
};

struct state{
	char p[8], n=0;
	int e;
	void encode(){
		e=0;
		for(int i=0; i<n; ++i)e=(e<<3)|p[i];
	}
	state(){
		n=0;
		for(int i=0; i<8; ++i)p[i]=i;
		encode();
	}
	/*state(int n):n(n){
		for(int i=0; i<8; ++i)p[i]=i;
		encode();
	}*/
	void updn(int nn){
		if(nn<n)for(int i=nn; i<n; ++i)p[i]=i;
		n=nn, encode();
	}
	/*int Find(int x){
		return x==p[x]?x:p[x]=Find(p[x]);
	}*/
	void init(){
		//for(int i=0; i<n; ++i)p[i]=Find(i);
		for(int i=2; i<n; ++i)while(p[p[i]]!=p[i])p[i]=p[p[i]];
		encode();
	}
	bool Union(int u, int v){
		u=p[u], v=p[v];
		if(u==v)return 0;
		if(u>v)swap(u, v);
		p[v]=u, init();
		return 1;
	}
	bool operator<(const state &r)const{
		//for(int i=n; i<8; ++i)assert(p[i]==i&&r.p[i]==i);
		return e<r.e;
		/*for(int i=0; i<n; ++i){
			++ttcnt;
			if(p[i]<r.p[i])return 1;
			if(p[i]>r.p[i])return 0;
		}
		return 0;*/
	}
	void out(){
		cout<<"state: ";
		for(int i=0; i<n; ++i)cout<<p[i]<<" \n"[i==n-1];
	}
};

vector<int> all;
//pair<int, ll> dp[kM*4][1000];
map<state, pair<int, ll> > dp[kM+kN];
int n, m, now, dep[kN];
vector<edge> G[kN];

int idx(state &s){
	return lower_bound(all.begin(), all.end(), s.e)-all.begin();
}

void upd(int now, state &t, pair<int, ll> cnt){
	auto i=dp[now].find(t);
	if(i==dp[now].end())dp[now][t]=cnt;
	else if(i->second.first==cnt.first)i->second.second+=cnt.second, i->second.second&=(1<<30)-1;
	else if(cnt.first<i->second.first)i->second=cnt;
	//if(dp[now].find(t)==dp[now].end())dp[now][t]=cnt;
	//else if(dp[now][t].first==cnt.first)dp[now][t].second+=cnt.second, dp[now][t].second&=(1<<30)-1;
	//else if(cnt.first<dp[now][t].first)dp[now][t]=cnt;
	//t.out();
	//cout<<cnt.first<<' '<<cnt.second<<endl;
	//++ttcnt;
}

void dfs(int x, int p){
	dep[x]=~p?dep[p]+1:0;
	vector<edge> v;
	for(edge u:G[x])if(~dep[u.v])v.push_back(u);
	int nv=1<<v.size();
	for(edge u:v){
		//assert(dep[u.v]<dep[x]);
		++now;
		for(auto s:dp[now-1]){
			state t=s.first; t.updn(dep[x]+1);
			auto cnt=s.second;
			upd(now, t, cnt);
			if(t.Union(dep[x], dep[u.v]))cnt.first+=u.w, upd(now, t, cnt);
		}
	}
	/*++now;
	for(auto s:dp[now-1])for(int i=0; i<nv; ++i){
		state t=s.first; t.updn(dep[x]+1);
		t.p[dep[x]]=dep[x];
		auto cnt=s.second;
		bool ok=1;
		for(int j=0; j<v.size(); ++j)if(i>>j&1){
			if(t.Union(dep[x], dep[v[j].v]))cnt.first+=v[j].w;
			else{ok=0; break;}
		}
		if(ok)upd(now, t, cnt);
	}*/
	for(edge u:G[x])if(!~dep[u.v])dfs(u.v, x);
	++now;
	for(auto s:dp[now-1])if(dep[x]==0||s.first.p[dep[x]]!=dep[x]){
		state t=s.first; t.updn(dep[x]);
		upd(now, t, s.second);
		//dp[now].insert(make_pair(t, s.second));
	}
}

void initall(int x, state &s){
	if(x==8)return;
	all.push_back(s.e);
	for(int i=0; i<x; ++i){
		state t=s; t.updn(x+1);
		initall(x+1, t);
		if(t.Union(x, i))initall(x+1, t);
	}
}

signed main(){
	ios::sync_with_stdio(0), cin.tie(0);
	//state s;
	//s.updn(1);
	//initall(0, s);
	//sort(all.begin(), all.end());
	//all.resize(unique(all.begin(), all.end())-all.end());
	int T;
	cin>>T;
	while(T--){
		cin>>n>>m, now=0;
		for(int i=0; i<=(m+n); ++i)dp[i].clear();
		for(int i=0; i<n; ++i)G[i].clear(), dep[i]=-1;
		for(int i=0; i<m; ++i){
			int u, v, w;
			cin>>u>>v>>w, --u, --v;
			G[u].push_back(edge(v, w)), G[v].push_back(edge(u, w));
		}
		state s=state();
		dp[0][s]=make_pair(0, 1);
		dfs(0, -1);
		//for(int i=0; i<=now; ++i)cout<<dp[i].size()<<endl;
		for(auto i:dp[now])cout<<(i.second.first*i.second.second&(1<<30)-1)<<endl;
		//cout<<now<<endl;
		//if(!(T&127))cerr<<T<<' '<<ttcnt<<endl;
	}
}
