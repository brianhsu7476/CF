#include <bits/stdc++.h>
//#define int long long
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
#define kN 5003
int n, a[kN], mex[kN][kN];
bool used[kN];
bitset<8192> dp[kN];

signed main(){
	//ios::sync_with_stdio(0), cin.tie(0);
	int T; cin>>T;
	while(T--){
		cin>>n;
		inarr(a, a+n);
		rep(i, n){
			rep(j, n+1)used[j]=0;
			int mx=0;
			fup(j, i, n){
				used[a[j]]=1;
				while(used[mx])++mx;
				mex[i][j+1]=mx;
			}
		}
		//cerr<<"here\n";
		rep(i, n){
			dp[i]=i?dp[i-1]:1;
			int j=i, l=i-1;
			while(l>=0&&a[l]!=a[i])--l;
			while(j>l&&mex[j][i+1]<=a[i])--j;
			if(j<=l)continue;
			//cerr<<"hi\n";
			do{
				if(mex[j][i+1]>mex[j+1][i+1]){
					debug(j);
					//debug(j, i+1, mex[j][i+1]);
					bitset<8192> mx;
					//cerr<<"hello\n";
					if(j==0)mx[mex[j][i+1]]=1;
					else rep(k, 8192)/*assert((j^mex[j][i+1])>=0), */mx[k^mex[j][i+1]]=dp[j-1][k];
					//mx[mex[j][i+1]]=mx[mex[j][i+1]]^1;
					//cerr<<"aa\n";
					dp[i]|=mx;
				}
				--j;
			}while(j>l);
			//cout<<i<<": ";
			//rep(j, 10)cout<<dp[i][j];
			//cout<<endl;
		}
		fdn(i, n, -1)if(dp[n-1][i]){cout<<i<<endl; break;}
	}
}
