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
#define kN 4003
int n, k, dp[kN][kN], sm[kN][kN], ans[kN], frac[kN], invf[kN];

int Pow(int a, int b){
	int r=1;
	for(; b; b>>=1, a=a*a%mod)if(b&1)r=r*a%mod;
	return r;
}

int f(int i, int j){
	if(j==k)return frac[k]*Pow(k, i-k)%mod;
	return frac[k]*invf[k-j]%mod*j%mod*Pow(k, i-j-1)%mod*ans[i-j-1]%mod;
}

signed main(){
	ios::sync_with_stdio(0), cin.tie(0);
	frac[0]=1;
	fup(i, 1, kN)frac[i]=frac[i-1]*i%mod;
	invf[kN-1]=Pow(frac[kN-1], mod-2);
	fdn(i, kN-2, -1)invf[i]=invf[i+1]*(i+1)%mod;
	orange(invf, invf+10);
	cin>>n>>k;
	fup(i, 1, n+1){
		fup(j, 1, k)dp[i][j]=((k-j+1)*dp[i-1][j-1]+sm[i-1][j])%mod; // dp[i-1][j]+dp[i-1][j+1]+...+dp[i-1][k]
		if(i>=k)dp[i][k]=(frac[k]*(Pow(k, i-k)+sm[i-k][1]))%mod;
		sm[i][k]=dp[i][k];
		fdn(j, k-1, -1)sm[i][j]=(sm[i][j+1]+dp[i][j])%mod;
	}
	/*fup(i, k, n+1){
		for(int j=1; j<k; ++j)ans[i]+=frac[k]*invf[k-j]%mod*j%mod*Pow(k, i-j-1)%mod*ans[i-j-1]%mod;
		ans[i]+=(1+ans[i-k])*frac[k]%mod*Pow(k, i-k)%mod;
		ans[i]=ans[i]%mod*Pow(k, mod-1-i)%mod;
		//for(int j=1; j<k; ++j)if(i>=j)ans[i]+=dp[i][j]*ans[i-j]*invf[i-j]*
		//if(i>=k)ans[i]=dp[i][k]*(1+ans[i-k]*invf[i-k]);
	}*/
	cout<<sm[n][1]<<endl;
	//if(j==k)dp[i][j]+=1;
	//rep(i, n)dp[i+1]=dp[i]*k+(i+1>=k?dp[i+1-k]*frac[n-i-1+k]:0);
}
