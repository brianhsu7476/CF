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
}a[kN];

int n, x[kN];
bool used[kN];

signed main(){
	ios::sync_with_stdio(0), cin.tie(0);
	int T; cin>>T;
	while(T--){
		cin>>n;
		rep(i, n){
			used[i]=1;
			int tmp[4];
			inarray(tmp, tmp+4);
			a[i]=P(tmp[0], tmp[3]);
		}
		sort(a, a+n);
		int now=0;
		rep(i, n){
			if(a[i].x>a[now].y)now=i;
			a[now].y=max(a[now].y, a[i].y);
			if(i!=now)used[i]=0;
		}
		vector<P> b;
		rep(i, n)if(used[i])b.pb(a[i]);
		//for(P i:b)cout<<i.x<<' '<<i.y<<endl;
		int q; cin>>q;
		rep(i, q){
			int x; cin>>x;
			int id=lower_bound(b.begin(), b.end(), P(x+1, 0))-b.begin(); --id;
			if(id==-1)cout<<x<<' ';
			else cout<<max(b[id].y, x)<<' ';
		}
		cout<<endl;
	}
}
