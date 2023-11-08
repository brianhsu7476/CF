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
#define kN 100005
#define kM 100000000000000017
int m, n[kN], l[kN], r[kN], s[kN];
vector<int> a[kN], c[kN];
unordered_map<int, vector<P>> mp;

signed main(){
	ios::sync_with_stdio(0), cin.tie(0);
	int T; cin>>T;
	while(T--){
		mp.clear();
		cin>>m;
		rep(i, m){
			a[i].clear(), c[i].clear();
			cin>>n[i]>>l[i]>>r[i];
			rep(j, n[i]){int x; cin>>x, a[i].pb(x);}
			rep(j, n[i]){int x; cin>>x, c[i].pb(x);}
			s[i]=0;
			rep(j, n[i])s[i]+=c[i][j];
		}
		__int128 sm=0, smr=0;
		rep(i, m)sm+=r[i]-l[i], smr+=r[i];
		if(sm>(__int128)kN||smr>(__int128)kM){cout<<"0\n"; continue;}
		int sl=0, sr=0;
		rep(i, m)sl+=l[i], sr+=r[i];
		rep(i, m)rep(j, n[i])if(sl<=a[i][j]&&a[i][j]<=sr)mp[a[i][j]].pb(P(i, j));
		int ans=kM;
		fup(i, sl, sr+1){
			int ssr=sr, ssl=0;
			for(auto j:mp[i])
				ssr-=r[j.x], ssr+=min(max(l[j.x], s[j.x]-c[j.x][j.y]), r[j.x]),
				ssl+=max(c[j.x][j.y]-s[j.x]+l[j.x], 0ll);
			debug(i, ssl, ssr);
			ans=min(ans, max(i-ssr, 0ll)+ssl);
		}
		cout<<ans<<endl;
	}
}
