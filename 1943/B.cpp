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
int n, a[kN], b[kN];

vector<int> manacher_odd(string s) {
	int n = s.size();
	s = "$" + s + "^";
	vector<int> p(n + 2);
	int l = 1, r = 1;
	for(int i = 1; i <= n; i++) {
		p[i] = max(0ll, min(r - i, p[l + (r - i)]));
		while(s[i - p[i]] == s[i + p[i]]) {
			p[i]++;
		}
		if(i + p[i] > r) {
			l = i - p[i], r = i + p[i];
		}
	}
	return vector<int>(begin(p) + 1, end(p) - 1);
}

vector<int> manacher(string s) {
    string t;
    for(auto c: s) {
        t += string("#") + c;
    }
    auto res = manacher_odd(t + "#");
    return vector<int>(begin(res) + 1, end(res) - 1);
}

signed main(){
	ios::sync_with_stdio(0), cin.tie(0);
	int T; cin>>T;
	while(T--){
		int q;
		cin>>n>>q;
		string s; cin>>s;
		vi z=manacher(s);
		for(int &i:z)--i;
		//rep(i, z.size())cout<<z[i]<<' '; cout<<endl;
		a[n-1]=n-1, b[n-1]=n-1, b[n-2]=n-2;
		for(int i=n-2; i>=0; --i){
			if(s[i]==s[i+1])a[i]=a[i+1];
			else a[i]=i;
		}
		for(int i=n-3; i>=0; --i){
			if(s[i]==s[i+2])b[i]=b[i+2];
			else b[i]=i;
		}
		while(q--){
			int l, r; cin>>l>>r, --l;
			int m=r-l, p=0;
			if(z[l+r-1]>=m)p=-m;
			//cout<<z[l+r]<<endl;
			if(r-l<2){cout<<"0\n"; continue;}
			if(s[l]==s[l+1]){
				if(a[l]>=r-1)cout<<"0\n";
				else cout<<m*(m+1)/2-1+p<<endl;
			}
			else{
				if(b[l]>=r-2&&b[l+1]>=r-2){
					int ans=(m/2)*(m/2+1);
					cout<<ans<<endl;
				}
				else cout<<m*(m+1)/2-1+p<<endl;
			}

		}
	}
}
