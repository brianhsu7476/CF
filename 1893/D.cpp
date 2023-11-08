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
#define kN 200005
int n, m, a[kN], s[kN], d[kN], cnt[kN], b[kN], p[kN], rr[kN];
vi ans[kN];

struct shelf{
	int sz, x, y;
	shelf(){}
	shelf(int sz, int x, int y):sz(sz), x(x), y(y){}
	bool operator<(const shelf r)const{return sz>r.sz||sz==r.sz&&x<r.x||sz==r.sz&&x==r.x&&y<r.y;}
};

set<shelf> S;

signed main(){
	ios::sync_with_stdio(0), cin.tie(0);
	int T; cin>>T;
	while(T--){
		cin>>n>>m;
		rep(i, n)cnt[i]=0;
		rep(i, n)cin>>a[i], --a[i], ++cnt[a[i]];
		rep(i, n)p[i]=i;
		sort(p, p+n, [](int x, int y){return cnt[x]>cnt[y];});
		rep(i, m)cin>>s[i], ans[i].resize(s[i], 0);
		rep(i, m)cin>>d[i];
		S.clear();
		rep(i, m){
			for(int j=0; j<s[i]; j+=d[i])S.ins(shelf(min(s[i]-j, d[i]), i, j));
		}
		bool ok=1;
		rep(i, n){
			vector<shelf> v;
			rep(j, cnt[p[i]]){
				if(S.empty()){ok=0; break;}
				shelf x=*S.begin();
				S.erase(x);
				if(x.sz>1)v.pb(shelf(x.sz-1, x.x, x.y+1));
				ans[x.x][x.y]=p[i];
			}
			if(!ok)break;
			for(shelf j:v)S.ins(j);
		}
		if(!ok){cout<<"-1\n"; continue;}
		rep(i, m){
			//assert(ans[i].size()==s[i]);
			for(int j:ans[i])rr[j]=oo;
			//for(int j=0; j<s[i]; ++j)rr[ans[i][j]]=max(rr[ans[i][j]], j/d[i]);
			//for(int j=s[i]-s[i]%d[i]; j<s[i]; ++j)used[ans[i][j]]=1;
			//safe;
			for(int j=s[i]/d[i]*d[i]; j>=0; j-=d[i]){
				sort(ans[i].begin()+j, ans[i].begin()+min(j+d[i], s[i]), [](int x, int y){return rr[x]<rr[y]||rr[x]==rr[y]&&x<y;});
				for(int k=j; k<min(j+d[i], s[i]); ++k)rr[ans[i][k]]=k;
			}
			//for(int j=0; j<s[i]; j+=d[i])sort(ans[i].begin()+j, ans[i].begin()+min(j+d[i], s[i]), [](int x, int y){return rr[x]>rr[y]||rr[x]==rr[y]&&x<y;});
			//safe;
			for(int j:ans[i])cout<<j+1<<' ';
			cout<<endl;
			//debug(i);
		}
	}
}
