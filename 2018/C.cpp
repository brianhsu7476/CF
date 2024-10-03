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
#define kN 1000006
int n, a[kN], dep[kN], mxdep[kN], pcnt[kN], dcnt[kN], sdcnt[kN], cnt[kN], spcnt[kN];
bool isl[kN];
vi G[kN];

void dfs(int x, int p){
	dep[x]=~p?dep[p]+1:0;
	for(int u:G[x])if(u!=p)dfs(u, x);
	mxdep[x]=dep[x];
	for(int u:G[x])if(u!=p)mxdep[x]=max(mxdep[x], mxdep[u]);
	isl[x]=mxdep[x]==dep[x];
}

void dfs1(int x, int p, int v){
	pcnt[x]=v+1;
	int w=0;
	for(int u:G[x])if(u!=p&&mxdep[u]==mxdep[x]){w=u; break;}
	for(int u:G[x])if(u!=p)dfs1(u, x, u==w?v+1:0);
}

signed main(){
	ios::sync_with_stdio(0), cin.tie(0);
	int T; cin>>T;
	while(T--){
		cin>>n;
		rep(i, n)G[i].clear();
		rep(i, n-1){
			int u, v; cin>>u>>v, --u, --v;
			G[u].pb(v), G[v].pb(u);
		}
		dfs(0, -1);
		safe;
		dfs1(0, -1, 0);
		safe;
		rep(i, n)dcnt[i]=0;
		rep(i, n)++dcnt[dep[i]];
		rep(i, n)cnt[i]=0;
		rep(i, n)if(isl[i])cnt[dep[i]]+=pcnt[i];
		sdcnt[0]=spcnt[0]=0;
		rep(i, n)sdcnt[i+1]=sdcnt[i]+dcnt[i], spcnt[i+1]=spcnt[i]+cnt[i];
		int ans=oo;
		rep(i, n){
			ans=min(ans, spcnt[i]+sdcnt[n]-sdcnt[i+1]);
		}
		cout<<ans<<endl;
	}
}
