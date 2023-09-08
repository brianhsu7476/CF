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
#define kN 1000006
int n, a[kN], c[kN], onc[kN], deg[kN];
vi cyc[kN];
bool vis[kN];

int dfs(int x){
	vis[x]=1;
	if(onc[a[x]]!=-2)return onc[x]=-1;
	if(vis[a[x]])return onc[x]=a[x];
	onc[x]=dfs(a[x]);
	if(x==onc[x])return -1;
	return onc[x];
}

signed main(){
	//ios::sync_with_stdio(0), cin.tie(0);
	int T; cin>>T;
	while(T--){
		cin>>n;
		rep(i, n)vis[i]=0, onc[i]=-2, cyc[i].clear(), deg[i]=0;
		inarr(a, a+n), inarr(c, c+n);
		rep(i, n)--a[i];
		rep(i, n)if(!vis[i])dfs(i);
		rep(i, n)if(~onc[i])cyc[onc[i]].pb(i);
		rep(i, n)if(cyc[i].size()){
			int mnid=0;
			fup(j, 1, cyc[i].size())if(c[cyc[i][j]]<c[cyc[i][mnid]])mnid=j;
			vis[cyc[i][mnid]]=0;
		}
		rep(i, n)if(vis[i])++deg[a[i]];
		set<P> pq;
		rep(i, n)pq.ins(P(deg[i], i));
		while(!pq.empty()){
			P p=*pq.begin();
			pq.erase(p);
			assert(p.x==0);
			cout<<p.y+1<<' ';
			if(vis[p.y])pq.erase(P(deg[a[p.y]], a[p.y])), --deg[a[p.y]], pq.ins(P(deg[a[p.y]], a[p.y]));
		}
		cout<<endl;
	}
}
