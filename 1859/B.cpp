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
using namespace std;
#ifdef brianhsu7476
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
void inarray(I L, I R){for(; L!=R; ++L)cin>>*L;}
template <typename I>
void outarray(I L, I R){
	for(int f=0; L!=R; ++L)cout<<(f++?" ":"")<<*L;
	cout<<endl;
}

#define oo 1000000007
#define mod 1000000007
#define kN 1000006

struct P{
	int x, y;
	P(){}
	P(int x, int y):x(x), y(y){}
	bool operator<(const P r)const{return x<r.x||(x==r.x&&y<r.y);}
};

int n, m[kN];
vi a[kN];

signed main(){
	ios::sync_with_stdio(0), cin.tie(0);
	int T; cin>>T;
	while(T--){
		cin>>n;
		rep(i, n)cin>>m[i], a[i].resize(m[i]), inarray(a[i].begin(), a[i].end()), sort(a[i].begin(), a[i].end());
		vi b, c;
		rep(i, n)b.pb(a[i][1]), c.pb(a[i][0]);
		sort(b.begin(), b.end()), sort(c.begin(), c.end());
		int s=c[0];
		fup(i, 1, n)s+=b[i];
		cout<<s<<endl;
	}
}
