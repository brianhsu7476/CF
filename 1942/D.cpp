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
#define ff first
#define ss second
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
#define kN 1003
int n, a[kN][kN], k;

struct kset{
	multiset<int> s;
	void ins(int a){
		s.insert(a);
		if(s.size()>k)s.erase(s.begin());
	}
	void del(int a){
		s.erase(s.find(a));
	}
	int mx(){
		return *s.rbegin();
	}
};

multiset<int>::reverse_iterator it[kN];

struct set2{
	multiset<pii> s;
	void ins(pii a){
		s.insert(a);
	}
	pii del(){
		pii a=*s.rbegin();
		s.erase(--s.rbegin().base());
		return a;
	}
};

kset dp[kN];

signed main(){
	ios::sync_with_stdio(0), cin.tie(0);
	int T; cin>>T;
	while(T--){
		cin>>n>>k;
		rep(i, n)fup(j, i+1, n+1)cin>>a[i][j];
		rep(i, n+2)dp[i].s.clear();
		dp[0].ins(0), dp[1].ins(0);
		//safe;
		fup(i, 2, n+2){
			set2 S;
			rep(j, i)it[j]=dp[j].s.rbegin();
			rep(j, i)S.ins(pii(a[j][i-1]+*it[j], j));
			//debug(i);
			rep(j, k){
				if(S.s.size()==0)break;
				//debug(j);
				pii b=S.del();
				dp[i].ins(b.ff);
				//debug(i, j, b.ss);
				//debug(*it[b.ss]);
				//debug(++it[b.ss]!=dp[b.ss].s.rend()), --it[b.ss];
				if(it[b.ss]!=dp[b.ss].s.rend()&&++it[b.ss]!=dp[b.ss].s.rend()){
					S.ins(pii(a[b.ss][i-1]+*it[b.ss], b.ss));
				}
			}
			//debug(i);
		}
		//safe;
		//debug(n, k, dp[n+1].s.size());
		for(auto it=dp[n+1].s.rbegin(); it!=dp[n+1].s.rend(); ++it){
			cout<<*it<<' ';
		}
		cout<<endl;
	}
}
