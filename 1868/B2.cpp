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

#define mod 1000000007
#define kN 1000006
#define kLog 31
int n, a[kN], cnt[kLog], b[kLog], c[kLog];
map<int, P> mp;

signed main(){
	ios::sync_with_stdio(0), cin.tie(0);
	rep(i, kLog)rep(j, kLog)if(i!=j)mp[(1ll<<i)-(1ll<<j)]=P(i, j);
	int T; cin>>T;
	while(T--){
		rep(i, kLog)cnt[i]=b[i]=c[i]=0;
		cin>>n;
		inarr(a, a+n);
		int avg=sumarr(a, a+n);
		if(avg%n!=0){cout<<"No\n"; continue;}
		avg/=n;
		bool ok=1;
		rep(i, n)if(a[i]!=avg){
			int x=a[i]-avg;
			if(mp.find(x)==mp.end()){ok=0; break;}
			P p=mp[x];
			++cnt[p.x], --cnt[p.y];
			if(p.x==p.y+1)++b[p.y];
			if(p.x+1==p.y)++c[p.x];
		}
		rep(i, kLog)if(cnt[i]){
			if(cnt[i]&1){ok=0; break;}
			if(cnt[i]>0)while(cnt[i]&&c[i]){
				cnt[i]-=2, --c[i];
				if(i<kLog-1)++cnt[i+1];
			}
			if(cnt[i]<0)while(cnt[i]&&b[i]){
				cnt[i]+=2, --b[i];
				if(i<kLog-1)--cnt[i+1];
			}
			if(cnt[i]){ok=0; break;}
		}
		cout<<(ok?"Yes\n":"No\n");
	}
}
