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
int n, a[kN], p[kN];

struct evt{
	int l, r;
	bool x[2]={0};
	evt(){}
	evt(int l, int r, int y):l(l), r(r){if(~y)x[y&1]=1;}
	bool ok()const{
		return x[l&1];
	}
	int len()const{
		return r-l+1>>1;
	}
	bool operator<(const evt rhs)const{return l<rhs.l||l==rhs.l&&r<rhs.r;}
};

evt merge(evt a, evt b){
	evt c=evt(a.l, b.r, -1);
	c.x[0]=a.x[0]|b.x[0], c.x[1]=a.x[1]|b.x[1];
	return c;
}

signed main(){
	ios::sync_with_stdio(0), cin.tie(0);
	int T; cin>>T;
	while(T--){
		cin>>n;
		rep(i, n)cin>>a[i], p[i]=i;
		set<evt> S;
		sort(p, p+n, [](int x, int y){return a[x]>a[y]||a[x]==a[y]&&x<y;});
		int ok=0, ans=0, len=0;
		rep(i, n){
			evt k=evt(p[i], p[i]+1, a[p[i]]==a[p[0]]?p[i]:-1);
			auto j=lower_bound(S.begin(), S.end(), k);
			if(j!=S.begin()){
				--j;
				if(j->r==k.l)k=merge(*j, k), ok-=j->ok(), len-=j->len(), S.erase(j);
			}
			j=lower_bound(S.begin(), S.end(), k);
			if(j!=S.end()){
				if(j->l==k.r)k=merge(k, *j), ok-=j->ok(), len-=j->len(), S.erase(j);
			}
			S.insert(k), ok+=k.ok(), len+=k.len();
			ans=max(ans, a[p[0]]+(int)(ok>0)+len-1+a[p[i]]);
			for(auto i:S)cerr<<i.l<<' '<<i.r<<' '<<i.x[0]<<' '<<i.x[1]<<endl;
			debug(ans);
		}
		cout<<ans<<endl;
	}
}
