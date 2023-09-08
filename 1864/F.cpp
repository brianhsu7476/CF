#include <bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
#define rep(i,n) for(int i=0; i<(n); ++i)
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
	int x=0, y=0, id;
	P(){}
	P(int x, int y):x(x), y(y){}
	P(int x):x(x){}
	bool operator<(const P r)const{return y<r.y||(y==r.y&&x<r.x);}
	bool operator>(const P r)const{return y>r.y||(y==r.y&&x>r.x);}
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
int n, a[kN], m;
P p[kN];

struct seg{
	int l, r, m, mx=0;
	seg *left=NULL, *right=NULL;
	seg(){}
	seg(int l, int r):l(l), r(r), m(l+r>>1){
		if(r-l>1)left=new seg(l, m), right=new seg(m, r), pull();
		else mx=-1;
	}
	void pull(){
		if(r-l>1)mx=max(left->mx, right->mx);
	}
	void upd(int x, int v){
		if(r-l==1){mx=v; return;}
		if(x<m)left->upd(x, v);
		else right->upd(x, v);
		pull();
	}
	int qry(int ll, int rr){
		if(ll<=l&&r<=rr)return mx;
		int res=-1;
		if(ll<m)res=max(res, left->qry(ll, rr));
		if(m<rr)res=max(res, right->qry(ll, rr));
		return res;
	}
}*root;

vi v[kN];
int bit[kN], ans[kN];
void upd(int x, int v){
	if(x<0)return;
	for(int i=x+1; i<=n; i+=i&-i)bit[i]+=v;
}
int qry(int x){
	int res=0;
	for(int i=x; i; i-=i&-i)res+=bit[i];
	return res;
}

signed main(){
	ios::sync_with_stdio(0), cin.tie(0);
	cin>>n>>m;
	rep(i, n)cin>>a[i], --a[i];
	root=new seg(0, n);
	rep(i, m)cin>>p[i].x>>p[i].y, --p[i].x, --p[i].y, p[i].id=i;
	sort(p, p+m);
	rep(i, n)v[a[i]].pb(i);
	int j=0;
	rep(i, n){
		rep(j, (int)v[i].size()-1)upd(root->qry(v[i][j]+1, v[i][j+1]), 1), debug(i, root->qry(v[i][j]+1, v[i][j+1]));
		rep(j, v[i].size())root->upd(v[i][j], i);
		if(v[i].size())upd(i, 1);
		while(j<m&&p[j].y==i)ans[p[j].id]=qry(p[j].y+1)-qry(p[j].x), ++j;
	}
	rep(i, m)cout<<ans[i]<<endl;
}
