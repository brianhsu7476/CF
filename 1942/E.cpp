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
#define kN 2000006

int Pow(int a, int b){
	int r=1;
	for(; b; b>>=1, a=a*a%mod)if(b&1)r=r*a%mod;
	return r;
}

int l, n, frac[kN], invf[kN];

int C(int n, int k){
	if(k<0||k>n)return 0;
	return frac[n]*invf[k]%mod*invf[n-k]%mod;
}

signed main(){
	ios::sync_with_stdio(0), cin.tie(0);
	frac[0]=1;
	fup(i, 1, kN)frac[i]=frac[i-1]*i%mod;
	invf[kN-1]=Pow(frac[kN-1], mod-2);
	fdn(i, kN-1, 0)invf[i-1]=invf[i]*i%mod;
	//rep(i, 10)cout<<frac[i]<<' ';
	//rep(i, 10)cout<<invf[i]<<' ';
	int T; cin>>T;
	while(T--){
		cin>>l>>n;
		int ans=C(l, n*2);
		rep(k, l){
			ans-=C(n+k-1, n-1)*C(l-n-k*2, n)%mod;
			//debug(n+(l-i-n*2)/2, n);
			//if(l-i-n*2>=0)ans-=C(n+(l-i-n*2)/2, n);
			//debug(ans);
		}
		ans=(ans*2%mod+mod)%mod;
		cout<<ans<<endl;
		//debug(C(l, n*2));
		//debug(n+(l-n*2)/2, n);
		//cout<<(C(l, n*2)-C(n+(l-n*2)/2, n)+mod)%mod*2%mod<<endl;
	}
}
