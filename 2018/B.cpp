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
int n, a[kN], b[kN], c[kN], bit[kN], d[kN], cnt[kN];

struct seg{ // if use mn not mx, remember to change some -oo to oo
	int l, r, m, mx, sm, lz=0, lzt=-oo;
	seg *left=NULL, *right=NULL;
	seg(){}
	seg(int l, int r, int *a):l(l), r(r), m(l+r>>1){
		if(r-l<2)mx=sm=a[l], left=right=NULL;
		else left=new seg(l, m, a), right=new seg(m, r, a), pull();
	}
	void addlz(int lz1, int lzt1){
		if(lzt1>-oo)mx=lzt=lzt1, sm=mx*(r-l), lz=0;
		else if(lzt>-oo)mx=lzt+=lz1, sm=mx*(r-l), lz=0;
		else mx+=lz1, lz+=lz1, sm+=lz1*(r-l);
	}
	void push(){
		if(lz!=0||lzt!=-oo){
			if(left)left->addlz(lz, lzt);
			if(right)right->addlz(lz, lzt);
			lz=0, lzt=-oo;
		}
	}
	void pull(){
		if(r-l>1)assert(left&&right), left->push(), right->push(), mx=min(left->mx, right->mx), sm=left->sm+right->sm;
	}
	void upd(int ll, int rr, int ad, int to){ // if no to, then to=oo
		//debug(ll, rr, l, r, ad, to);
		push();
		if(ll<=l&&r<=rr){addlz(ad, to); return;}
		push();
		if(ll<=m&&left)left->upd(ll, rr, ad, to);
		if(m<=rr&&right)right->upd(ll, rr, ad, to);
		pull();
	}
	P qry(int ll, int rr){
		push();
		if(ll<=l&&r<=rr)return P(mx, sm);
		auto f=[](P a, P b){return P(min(a.x, b.x), a.y+b.y);};
		P res=P(oo, 0);
		if(ll<=m)res=f(res, left->qry(ll, rr));
		if(m<=rr)res=f(res, right->qry(ll, rr));
		return res;
	}
	void out(){
		push();
		if(r-l<2)cerr<<mx<<' ';
		else left->out(), right->out();
		pull();
	}
};

/*
void init(int n){
	for(int i=1; i<=n; ++i)bit[i]=0;
}
void upd(int x, int v){
	for(int i=x+1; i<=n; i+=i&-i)bit[i]+=v;
}
int qry(int x){
	int r=0;
	for(int i=x+1; i; i-=i&-i)r+=v;
	return r;
}
*/
/*
struct node{
	multiset<int> S;
	int v=0;
	void ins(int x){
		S.insert(x), v+=x;
	}
	void del(int x){
		S.erase(S.find(x)), v-=x;
	}
};
*/

signed main(){
	ios::sync_with_stdio(0), cin.tie(0);
	int T; cin>>T;
	while(T--){
		cin>>n;
		rep(i, n)cin>>a[i];
		b[0]=a[0];
		fup(i, 1, n)b[i]=min(b[i-1], a[i]);
		c[n-1]=a[n-1];
		fdn(i, n-2, -1)c[i]=min(c[i+1], a[i]);
		rep(i, n+1)cnt[i]=0;
		rep(i, n)++cnt[c[i]];
		d[n]=0;
		fdn(i, n-1, -1)d[i]=d[i+1]+cnt[i+1]-1;
		seg *root=new seg(0, n, d);
		orange(d, d+n);
		int ans=0;
		for(int i=0; i<n; ++i){
			int res0=root->qry(0, n).x;
			//if(res>=0)++ans;
			debug(ans, b[i], c[i]);
			//root->out(); cerr<<endl;
			if(b[i]>c[i])root->upd(c[i], b[i], 1, -oo);
			if(b[i]<c[i])root->upd(b[i], c[i], -1, -oo);
			int res1=root->qry(0, n).x;
			if(res0>=0&&res1>=0)++ans;
			//root->out(); cerr<<endl;
		}
		cout<<ans<<endl;
		/*multiset<int> S, T;
		rep(i, n)S.insert(c[i]), T.insert(c[i]-i-1);
		rep(i, n){
			int x=upper_bound(S.begin(), S.end(), c[i])-S.begin();
			T.erase(T.find(c[i]-x));
			S.erase(S.find(c[i]));
			S.insert(b[i]);
			x=upper_
			T.insert(
		}*/
	}
}
