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

#define mod 998244353
#define kN 100005
#define kLog 64
int n, m, a[kLog*2], b[kN];

int Pow(int a, int b){
	int r=1;
	for(; b; b>>=1, a=a*a%mod)if(b&1)r=r*a%mod;
	return r;
}

signed main(){
	ios::sync_with_stdio(0), cin.tie(0);
	int T; cin>>T;
	while(T--){
		cin>>n>>m;
		fup(i, 1, m+1)b[i]=1;
		rep(k, kLog*2){
			if(k>n)break;
			a[k]=b[m]*m;
			rep(i, m)a[k]-=b[i];
			a[k]=(a[k]%mod+mod)%mod;
			a[k]=a[k]*Pow(m, n-k)%mod;
			rep(i, m+1)b[i]=b[i]*i%mod;
			assert(a[k]>=0);
		}
		orange(a, a+10);
		int hb=62;
		while(!(n>>hb))--hb;
		//debug(hb);
		int ans=0;
		rep(i, kLog)rep(j, kLog){
			int n0=(n^(1ll<<hb))+1, k=max(i, j);
			if(k>hb)continue;
			if(k==0){ans=(ans+n%mod*a[1])%mod; continue;}
			//debug(n0);
			int cnt=((1ll<<hb-k)-1)%mod;
			cnt=(cnt+(n0>>k))%mod;
			int r=n0&(1ll<<k)-1, cnt2=0;
			//debug(k, r);
			auto f=[](int k){return k?(1ll<<k-1)%mod:1ll;};
			if(r<(1ll<<k-1)){
				if(j==k)cnt2=0;
				else cnt2=r%mod*f(j)%mod;
			}
			else{
				r^=1ll<<k-1;
				if(j<k)cnt2=f(i)*f(j)%mod;
				else cnt2=r%mod*f(i)%mod;
			}
			debug(i, j, cnt, f(i), f(j), cnt2);
			cnt=(cnt*f(i)%mod*f(j)%mod+cnt2)%mod;
			//debug(i, j, cnt);
			ans=(ans+cnt*a[i+j+1])%mod;
		}
		cout<<ans<<endl;
	}
}
