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
#define kN 300005
int n, a[kN], p[kN], q[kN], in[kN], out[kN], sz[kN], mx[kN], mxch[kN], b[kN], B[kN];
vi G[kN], S[kN];

void dfs0(int x){
	sz[x]=1;
	b[x]=B[a[x]], B[a[x]]=x;
	for(int i:G[x])dfs0(i), sz[x]+=sz[i];
	sort(all(G[x]), [](int i, int j){return sz[i]>sz[j];});
	B[a[x]]=b[x];
}

void dfs1(int x, int cnt, bool f){
	in[x]=cnt++;
	S[a[x]].insert(x);
	if(x){
		if(f)q[x]=q[p[x]];
		else q[x]=p[x];
	}
	bool ok=1;
	for(int i:G[x])dfs(i, cnt, ok), ok=0;
	out[x]=cnt;
}

void dfs2(int x){
	int y=x;
	while(y){
		y=q[x];
		upd(in[y], in[x], 1);
	}
}

signed main(){
	ios::sync_with_stdio(0), cin.tie(0);
	int T; cin>>T;
	while(T--){
		cin>>n;
		rep(i, n)G[i].clear(), S[i].clear(), B[i]=-1;
		fup(i, 1, n)cin>>p[i], --p[i], G[p[i]].pb(i);
		rep(i, n)cin>>a[i], --a[i];
		dfs0(0);
		dfs1(0, 0, 0);
		
		/*rep(i, n)sort(all(S[i]), [](int x, int y){return in[x]<in[y];});
		rep(i, n){
			if(S[a[i]][0]==i){b[i]=-1; break;}
			int l=0, r=S[a[i]].size();
			while(r-l>1){
				int m=l+r>>1;
				if(in[S[a[i]][m]]>=in[i])r=m;
				if(out[S[a[i]][m]]
			}
		}*/
	}
}
