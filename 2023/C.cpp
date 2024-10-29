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

#define mod0 1000000007
#define mod1 998244353
#define kN 1000006
int n, k, dis0[kN], dis1[kN], m0, m1;
bool a0[kN], a1[kN];
vi G0[kN], G1[kN];
int d00[kN], d01[kN], d10[kN], d11[kN], h0[kN], h1[kN], r0, r1;

void dfs0(int x, int d){
	dis0[x]=d;
	for(int u:G0[x])if(!~dis0[u])dfs0(u, d+1);
}

void dfs1(int x, int d){
	dis1[x]=d;
	for(int u:G1[x])if(!~dis1[u])dfs1(u, d+1);
}

int rnd(){
	return (int)rand()<<16^rand();
}

int Pow(int a, int b, int mod){
	int r=1;
	for(; b; b>>=1, a=a*a%mod)if(b&1)r=r*a%mod;
	return r;
}

vector<P> rotate(int *a){
	vector<P> res;
	int s0=0, s1=0, pr0=Pow(r0, k, mod0), pr1=Pow(r1, k, mod1);
	rep(i, k)s0=(s0*r0+h0[a[i]])%mod0, s1=(s1*r1+h1[a[i]])%mod1;
	rep(i, k){
		res.pb(P(s0, s1));
		s0=(s0*r0%mod0-pr0*h0[a[i]]%mod0+h0[a[i]])%mod0, s1=(s1*r1%mod1-pr1*h1[a[i]]%mod1+h1[a[i]])%mod1;
		s0=(s0+mod0)%mod0, s1=(s1+mod1)%mod1;
	}
	assert(P(s0, s1)==res[0]);
	return res;
}

signed main(){
	ios::sync_with_stdio(0), cin.tie(0);
	int T; cin>>T;
	while(T--){
		cin>>n>>k;
		rep(i, n)dis0[i]=dis1[i]=-1, G0[i].clear(), G1[i].clear(), h0[i]=rnd()%mod0, h1[i]=rnd()%mod1;
		rep(i, n)cin>>a0[i];
		rep(i, k)d00[i]=d01[i]=d10[i]=d11[i]=0;
		r0=rnd()%mod0, r1=rnd()%mod1;
		cin>>m0;
		rep(i, m0){
			int u, v; cin>>u>>v, --u, --v;
			G0[u].pb(v);
		}
		rep(i, n)cin>>a1[i];
		cin>>m1;
		rep(i, m1){
			int u, v; cin>>u>>v, --u, --v;
			G1[u].pb(v);
		}
		bool ok=1;
		rep(i, n)if(a0[i]||!a1[i]){ok=0; break;}
		if(ok||k==1){cout<<"YES\n"; continue;}
		ok=1;
		rep(i, n)if(!a0[i]||a1[i]){ok=0; break;}
		if(ok){cout<<"YES\n"; continue;}
		dfs0(0, 0), dfs1(0, 0);
		rep(i, n)dis0[i]%=k, dis1[i]%=k;
		rep(i, n){
			if(a0[i])++d01[dis0[i]];
			else ++d00[dis0[i]];
			if(a1[i])++d11[dis1[i]];
			else ++d10[dis1[i]];
		}
		orange(d00, d00+k), orange(d01, d01+k), orange(d10, d10+k), orange(d11, d11+k);
		vector<P> r00=rotate(d00), r01=rotate(d01), r10=rotate(d10), r11=rotate(d11);
		orange(all(r00)), orange(all(r01)), orange(all(r10)), orange(all(r11));
		ok=0;
		for(int i=0; i<k; ++i)if(r00[(i+1)%k]==r11[0]&&r10[1]==r01[i]){ok=1; break;}
		cout<<(ok?"YES":"NO")<<endl;
	}
}
