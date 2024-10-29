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

#define oo 1000000000000000018
#define mod 1000000007
#define kN 1000006

int n, a[kN], b[kN];

signed main(){
	ios::sync_with_stdio(0), cin.tie(0);
	int T; cin>>T;
	while(T--){
		cin>>n;
		for(int i=0; i<n; ++i)cin>>a[i];
		int ans=1;
		if(n&1){
			ans=oo;
			for(int i=0; i<n; ++i){
				for(int j=0; j<i; ++j)b[j]=a[j];
				b[i]=a[i];
				for(int j=i+1; j<=n; ++j)b[j]=a[j-1];
				int ans1=1;
				for(int j=0; j<(n+1)/2; ++j)ans1=max(ans1, b[j*2+1]-b[j*2]);
				ans=min(ans, ans1);
			}
		}
		else{
			for(int i=0; i<n/2; ++i)ans=max(ans, a[i*2+1]-a[i*2]);
		}
		cout<<ans<<endl;
	}
}
