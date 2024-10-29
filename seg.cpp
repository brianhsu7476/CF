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
int n, a[kN];

/*
1e6: 2.3s
5e5: 0.98s
2e5: 0.33s
1e5: 0.14s
*/
struct seg{
	const int o=-oo;
	int l=-1, r=-1, m=-1, sm=0, mx=0, lz=0, lzt=o;
	seg *left=NULL, *right=NULL;
	seg(){}
	seg(int l, int r):l(l), r(r), m(l+r>>1){
		if(r-l<2)left=right=NULL, sm=mx=lz=0, lzt=o;
		else left=new seg(l, m), right=new seg(m, r), pull();
	}
	void updlz(int lz1, int lzt1){
		if(lzt1==o){
			if(lzt==o)lz+=lz1;
			else lzt+=lz1;
		}
		else lzt=lzt1;
	}
	void push(){
		if(lzt==o)sm+=lz*(r-l), mx+=lz;
		else sm=lzt*(r-l), mx=lzt;
		if(r-l>1)left->updlz(lz, lzt), right->updlz(lz, lzt);
		lz=0, lzt=o;
	}
	void pull(){
		if(r-l>1)left->push(), right->push(), sm=left->sm+right->sm, mx=max(left->mx, right->mx);
	}
	void upd(int ll, int rr, int ad, int to){
		if(ll<=l&&r<=rr){updlz(ad, to); return;}
		push();
		if(ll<m)left->upd(ll, rr, ad, to);
		if(m<rr)right->upd(ll, rr, ad, to);
		pull();
	}
	P qry(int ll, int rr){
		push();
		if(ll<=l&&r<=rr)return P(sm, mx);
		P res=P(0, o);
		auto f=[](P a, P b){
			return P(a.x+b.x, max(a.y, b.y));
		};
		if(ll<m)res=f(res, left->qry(ll, rr));
		if(m<rr)res=f(res, right->qry(ll, rr));
		return res;
	}
};

vector<int> ans, ans1;

signed main(){
	ios::sync_with_stdio(0), cin.tie(0);
	n=100000;
	srand(time(0));
	for(int i=0; i<n; ++i)a[i]=rand();
	seg *root=new seg(0, n);
	for(int i=0; i<n; ++i)root->upd(i, i+1, 0, a[i]);
	for(int i=0; i<n; ++i){
		int q=rand()&3, l=rand()%n, r=rand()%n, v=rand();
		if(l>r)swap(l, r);
		++r;
		if(q==0)root->upd(l, r, v, root->o);
		if(q==1)root->upd(l, r, 0, v);
		if(q==2)ans.pb(root->qry(l, r).x);
		if(q==3)ans.pb(root->qry(l, r).y);
		/*
		if(q==0)for(int j=l; j<r; ++j)a[j]+=v;
		if(q==1)for(int j=l; j<r; ++j)a[j]=v;
		if(q==2){
			int sm=0;
			for(int j=l; j<r; ++j)sm+=a[j];
			ans1.pb(sm);
		}
		if(q==3){
			int mx=-oo;
			for(int j=l; j<r; ++j)mx=max(mx, a[j]);
			ans1.pb(mx);
		}
		*/
	}
	debug(ans.size());
	//for(int i=0; i<ans.size(); ++i)assert(ans[i]==ans1[i]);
	//for(int i=0; i<10; ++i)debug(ans[i], ans1[i]);
}
