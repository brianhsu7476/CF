#include <bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
#define rep(i,n) for(int i=0; i<(int)(n); ++i)
#define fup(i,a,b) for(int i=(a); i<(int)(b); ++i)
#define fdn(i,a,b) for(int i=(a); i>(int)(b); --i)
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
#define oo 1000000007
template <typename I>
auto maxarr(I L, I R){
	auto r=*L;
	if(L==R)return r=-oo;
	for(; L!=R; ++L)r=max(r, *L);
	return r;
}
template <typename I>
auto minarr(I L, I R){
	auto r=*L;
	if(L==R)return r=oo;
	for(; L!=R; ++L)r=min(r, *L);
	return r;
}
template <typename I>
auto sumarr(I L, I R){
	auto r=*L;
	if(L==R)return r-*L;
	for(++L; L!=R; ++L)r=r+*L;
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
#define kN 30004
#define kL 20
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
int n, q;
vi G[kN];
bool used[kN];

signed main(){
	ios::sync_with_stdio(0), cin.tie(0);
	//int T; cin>>T;
	//while(T--){
		cin>>n>>q;
		rep(i, n)used[i]=0;
		rep(i, n){
			G[i].clear();
			while(1){
				int x; cin>>x;
				if(!x)break;
				G[i].pb(--x), used[x]=1;
			}
		}
		int rt;
		rep(i, n)if(!used[i])rt=i;
		lca::build(n, G, rt);
		while(q--){
			int u, v; cin>>u>>v, --u, --v;
			cout<<lca::lca(u, v)+1<<' '<<lca::qry(u, v)<<endl;
		}
	//}
}
