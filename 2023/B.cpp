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
#define oo 10000000000000016
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
int n, a[kN], b[kN], c[kN], sa[kN], bit[kN];

struct seg{
	int v, l, r, m;
	seg *left, *right;
	seg(){}
	seg(int l, int r):l(l), r(r), m(l+r>>1){
		if(r-l<2)v=oo;
		else left=new seg(l, m), right=new seg(m, r), pull();
	}
	void pull(){
		v=min(left->v, right->v);
	}
	void upd(int x, int w){
		if(r-l<2){v=w; return;}
		if(x<m)left->upd(x, w);
		else right->upd(x, w);
		pull();
	}
	int qry(int ll, int rr){
		if(ll<=l&&r<=rr)return v;
		int res=oo;
		if(ll<m)res=min(res, left->qry(ll, rr));
		if(m<rr)res=min(res, right->qry(ll, rr));
		return res;
	}
};

signed main(){
	ios::sync_with_stdio(0), cin.tie(0);
	int T; cin>>T;
	while(T--){
		cin>>n;
		rep(i, n)cin>>a[i];
		sa[0]=0;
		rep(i, n)sa[i+1]=sa[i]+a[i];
		//rep(i, n+1)bit[i]=0;
		rep(i, n)cin>>b[i], --b[i];
		rep(i, n)c[i]=oo;
		c[0]=0;
		seg *root=new seg(0, n);
		root->upd(0, 0);
		rep(i, n){
			c[i]=root->qry(i, n);
			if(b[i]>i){
				c[b[i]]=min(c[b[i]], c[i]+a[i]);
				root->upd(b[i], c[b[i]]);
			}
		}
		int ans=0;
		rep(i, n)ans=max(ans, sa[i+1]-c[i]);
		cout<<ans<<endl;
	}
}
