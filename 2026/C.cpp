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

int n;
string s;
bool a[kN], used[kN];

signed main(){
	ios::sync_with_stdio(0), cin.tie(0);
	int T; cin>>T;
	while(T--){
		cin>>n>>s;
		for(int i=0; i<n; ++i)a[i]=s[i]=='1';
		set<int> A, B;
		for(int i=0; i<n; ++i)if(a[i])A.insert(i); else B.insert(-i);
		int ans=n*(n+1)/2;
		for(int i=n-1; i>=0; --i)if(A.find(i)!=A.end()){
			A.erase(i);
			debug(i, *A.begin(), B.size());
			while(B.size()&&-*B.begin()>i)B.erase(B.begin());
			if(B.size()){B.erase(B.begin()), ans-=i+1, debug(i+1, i+1); continue;}
			if(A.size()){A.erase(A.begin()), ans-=i+1, debug(i+1); continue;}
		}
		cout<<ans<<endl;
	}
}
