#include <bits/stdc++.h>
using namespace std;
#define kN 16
#define oo 1000000007

int n, r[kN], b[kN];
char c[kN];

struct state{
	int a, r, b;
	state(){}
	state(int a, int r, int b):a(a), r(r), b(b){}
	bool operator<(const state rhs)const{return a<rhs.a||a==rhs.a&&r-b<rhs.r-rhs.b;}//||a==rhs.a&&r==rhs.r&&b<rhs.b;}
};

map<state, int> S, T;
//vector<int> v[kN];

int bitcount(int a){
	int r=0;
	for(; a; a>>=1)r+=a&1;
	return r;
}

int haver(int a){
	int r=0;
	for(int i=0; i<n; ++i)if(a>>i&1&&c[i]=='R')++r;
	return r;
}

int haveb(int a){
	int r=0;
	for(int i=0; i<n; ++i)if(a>>i&1&&c[i]=='B')++r;
	return r;
}

signed main(){
	cin>>n;//, m=1<<n;
	for(int i=0; i<n; ++i)cin>>c[i]>>r[i]>>b[i];
	//for(int i=0; i<m; ++i)v[bitcount(i)].push_back(i);
	T[state(0, 0, 0)]=0;
	for(int i=0; i<n; ++i){
		S.clear();
		for(auto j:T)S.insert(j); //cout<<j.first.a<<' '<<j.first.r<<' '<<j.first.b<<endl;
		T.clear();
		for(auto j:S){
			for(int k=0; k<n; ++k){
				int R=j.first.r+haver(j.first.a), B=j.first.b+haveb(j.first.a);
				if(j.first.a>>k&1)continue;
				int c=max(max(r[k]-R, b[k]-B), 0);
				state s=state(j.first.a|1<<k, j.first.r+c-max(r[k]-haver(j.first.a), 0), j.first.b+c-max(b[k]-haveb(j.first.a), 0));
				if(T.find(s)==T.end()||T[s]>j.second+c+1)T[s]=j.second+c+1;
			}
		}
		cerr<<S.size()<<endl;
	}
	int ans=oo;
	for(auto j:T)ans=min(ans, j.second);
	cout<<ans<<endl;
}
