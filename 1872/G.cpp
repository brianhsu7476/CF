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
int n, a[kN], sa[kN];
__int128 s[kN];
__int128 f(int l, int r){
	//debug(l, r);
	//debug(l, r, s[r], s[l]);
	//debug((int)s[r], (int)s[l]);
	//debug((int)(s[r]/s[l]));
	//debug(s[r]/s[l]);
	return s[r]/s[l]+(__int128)(sa[n]-sa[r]+sa[l]);
}

signed main(){
	ios::sync_with_stdio(0), cin.tie(0);
	int T; cin>>T;
	while(T--){
		cin>>n;
		inarr(a, a+n);
		sa[0]=0;
		__int128 sm=0, mul=1;
		rep(i, n)sm+=(__int128)a[i], sa[i+1]=sm;
		bool ok=0;
		rep(i, n){
			mul*=(__int128)a[i];
			if(mul>=(__int128)0xfffffffffffffff){ok=1; break;}
		}
		if(ok){
			int l=0, r=n-1;
			while(a[l]==1)++l;
			while(a[r]==1)--r;
			cout<<l+1<<' '<<r+1<<endl;
			continue;
		}
		//debug("Here");
		vi b;
		rep(i, n)if(a[i]>1)b.pb(i);
		if(!b.size()){cout<<"1 1\n"; continue;}
		s[0]=1;
		rep(i, n)s[i+1]=s[i]*(__int128)a[i];
		__int128 ans=0;
		//debug("Hello");
		orange(b.begin(), b.end());
		rep(i, b.size())fup(j, i, b.size())ans=max(ans, f(b[i], b[j]+1)), debug(b[i], b[j]+1, (int)ans);
		//debug("Hi");
		ok=0;
		rep(i, b.size()){
			fup(j, i, b.size())if(f(b[i], b[j]+1)==ans){cout<<b[i]+1<<' '<<b[j]+1<<endl, ok=1; break;}
			if(ok)break;
		}
	}
}
