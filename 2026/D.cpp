#include <bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'
#define vi vector<int>
#define pb push_back
#define ins insert
#define pii pair<int, int>
#define mp(a,b) make_pair((a), (b))
#define all(a) (a).begin(), (a).end()
using namespace std;
#ifdef rmfr
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

#define oo 1000000007
#define mod 1000000007
#define kN 1000006

int n, a[kN], b[kN], sb[kN], sa[kN], s[kN], sa0[kN];

int f(int i, int j){
	if(j>=n)return 0;
	return (sa0[j+1]-sa0[i])*(n-j)+sb[n]-sb[j+1];
}

signed main(){
	ios::sync_with_stdio(0), cin.tie(0);
	cin>>n;
	for(int i=0; i<n; ++i)cin>>a[i];
	s[0]=0;
	for(int i=0; i<n; ++i)s[i+1]=s[i]+n-i;
	sa0[0]=0;
	for(int i=0; i<n; ++i)sa0[i+1]=sa0[i]+a[i];
	for(int i=0; i<n; ++i)b[i]=a[i]*(n-i);
	sb[0]=0;
	for(int i=0; i<n; ++i)sb[i+1]=sb[i]+b[i];
	sa[0]=0;
	for(int i=0; i<=n; ++i)sa[i+1]=sa[i]+sb[n]-sb[i];
	int q; cin>>q;
	while(q--){
		int l, r; cin>>l>>r, ++r;
		int L=lower_bound(s+1, s+n+1, l)-s-1, R=lower_bound(s+1, s+n+1, r)-s-1;
		debug(sa[R+1], sa[L+1]);
		debug(L, R);
		int ans=sa[R+1]-sa[L+1];
		debug(ans);
		debug(f(L, l-s[L]+L), f(R, r-s[R]+R));
		ans+=f(L, l-s[L]+L-1)-f(R, r-s[R]+R-1);
		cout<<ans<<endl;
	}
}
