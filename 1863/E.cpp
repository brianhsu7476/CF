#include <bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
#define rep(i,n) for(int i=0; i<(int)(n); ++i)
#define fup(i,a,b) for(int i=(a); i<(b); ++i)
#define fdn(i,a,b) for(int i=(a); i>(b); --i)
#define vi vector<int>
#define pb push_back
#define ins insert
#define SZ(a) (int)(a).size()
#define pii pair<int, int>
#define mp(a,b) make_pair((a), (b))
#define all(a) (a).begin(), (a).end()
using namespace std;
#ifdef brianhsu_codeforces_template
#define safe cerr<<__PRETTY_FUNCTION__<<" line "<<__LINE__<<" safe\n"
#define debug(a...) debug_(#a, a)
#define orange(a...) orange_(#a, a)
template <typename ...T>
void debug_(const char *s, T ...a){
	cerr<<"\e[1;32m("<<s<<") = (";
	int cnt=sizeof...(T);
	(...,(cerr<<a<<(--cnt?", ":")\e[0m\n")));
}
template <typename I>
void orange_(const char *s, I L, I R){
	cerr<<"\e[1;32m[ "<<s<<" ] = [ ";
	for(int f=0; L!=R; ++L)cerr<<(f++?", ":"")<<*L;
	cerr<<" ]\e[0m\n";
}
#else
#define safe ((void)0)
#define debug(...) safe
#define orange(...) safe
#endif
template <typename I>
void inarr(I L, I R){for(; L!=R; ++L)cin>>*L;}
template <typename I>
void outarr(I L, I R){
	for(int f=0; L!=R; ++L)cout<<(f++?" ":"")<<*L;
	cout<<endl;
}
#define oo 1000000000000000018
template <typename I>
auto maxarr(I L, I R){
	if(L==R)return -oo;
	auto r=*L;
	for(; L!=R; ++L)r=max(r, *L);
	return r;
}
template <typename I>
auto minarr(I L, I R){
	if(L==R)return oo;
	auto r=*L;
	for(; L!=R; ++L)r=min(r, *L);
	return r;
}
template <typename I>
auto sumarr(I L, I R){
	typename I::value_type r=0;
	for(; L!=R; ++L)r=r+*L;
	return r;
}
template <typename I>
void cparr(I L, I R, I L2){
	for(; L!=R; ++L, ++L2)*L2=*L;
}
struct P{
	int x=0, y=0;
	P(){}
	P(int x, int y):x(x), y(y){}
	P(int x):x(x){}
	bool operator<(const P r)const{return x<r.x||(x==r.x&&y<r.y);}
	bool operator>(const P r)const{return x>r.x||(x==r.x&&y>r.y);}
	bool operator==(const P r)const{return x==r.x&&y==r.y;}
	bool operator!=(const P r)const{return x!=r.x||y!=r.y;}
	P operator+(const P r)const{return P(x+r.x, y+r.y);}
	P operator*(const int r)const{return P(x*r, y*r);}
	int dis()const{return abs(x)+abs(y);}
	int abs2()const{return x*x+y*y;}
};
istream &operator>>(istream &in, P &a){return in>>a.x>>a.y;}
ostream &operator<<(ostream &out, const P a){return out<<'('<<a.x<<", "<<a.y<<')';}

#define mod 1000000007
#define kN 200005
int n, m, k, h[kN], deg[kN];
P l[kN];
P dis[kN];
vector<P> G[kN], e;
set<P> S;
int p[kN];
int Find(int x){return x==p[x]?x:p[x]=Find(p[x]);}
void Union(int x, int y){p[Find(x)]=Find(y);}

signed main(){
	ios::sync_with_stdio(0), cin.tie(0);
	int T; cin>>T;
	while(T--){
		cin>>n>>m>>k;
		rep(i, n)G[i].clear(), deg[i]=0, p[i]=i;
		inarr(h, h+n);
		rep(i, m){
			int u, v; cin>>u>>v, --u, --v;
			Union(u, v);
			int w=(h[v]-h[u]+k)%k;
			debug(w);
			G[u].pb(P(v, w)), ++deg[v];
		}
		S.clear();
		rep(i, n)S.insert(P(deg[i], i));
		rep(i, n)dis[i]=P(0, i);
		while(!S.empty()){
			P u=*S.begin();
			//assert(deg[u.y]==0);
			S.erase(u);
			rep(i, G[u.y].size()){
				int v=G[u.y][i].x;
				S.erase(S.find(P(deg[v], v)));
				--deg[v], S.insert(P(deg[v], v));
				dis[v]=max(dis[v], dis[u.y]+P(G[u.y][i].y, 0));
			}
		}
		rep(i, n)l[i]=P(h[dis[i].y], dis[i].x);
		/*rep(i, n)l[i]=P(-1, -1);
		rep(i, n){
			int u=Find(i);
			if(dis[i].x>l[u].y)l[u]=P(h[dis[i].y], dis[i].x);
		}*/
		e.clear();
		rep(i, n)if(~l[i].x)e.pb(l[i]);
		sort(all(e));
		orange(all(e));
		int mx=0, ans=oo;
		rep(i, e.size())mx=max(mx, e[i].y+e[i].x-e[0].x);
		ans=min(ans, mx);
		rep(i, (int)e.size()-1){
			mx-=e[i+1].x-e[i].x;
			mx=max(mx, e[i].y+(k+e[i].x-e[i+1].x)%k);
			ans=min(ans, mx);
		}
		cout<<ans<<endl;
	}
}
