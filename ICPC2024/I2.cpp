#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC optimize("no-math-errno,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define kN 16
#define oo 1000000007

int n, m, r[kN], b[kN];
char c[kN];

struct state{
	int r, b;
	state(){}
	state(int r, int b):r(r), b(b){}
	bool operator<(const state rhs)const{return r<rhs.r||r==rhs.r&&b<rhs.b;}
};

map<state, int> S[1<<kN];

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

state stand(pair<state, int> p){
	return state(p.first.r+oo-p.second, p.first.b+oo-p.second);
}

signed main(){
	cin>>n, m=1<<n;
	for(int i=0; i<n; ++i)cin>>c[i]>>r[i]>>b[i];
	S[0][state(0, 0)]=0;
	for(int i=0; i<m-1; ++i){
		vector<pair<state, int>> v;
		vector<bool> used;
		for(auto j:S[i])v.push_back(j), used.push_back(1);
		for(int j=0; j<v.size(); ++j)if(used[j]){
			state J=stand(v[j]);
			for(int k=j+1; k<v.size(); ++k)if(used[k]){
				state K=stand(v[k]);
				if(J.r<=K.r&&J.b<=K.b){used[j]=0; break;}
				if(J.r>=K.r&&J.b>=K.b)used[k]=0;
			}
		}
		S[i].clear();
		for(int j=0; j<v.size(); ++j)if(used[j])S[i][v[j].first]=v[j].second;
		for(auto j:S[i]){
			for(int k=0; k<n; ++k){
				if(i>>k&1)continue;
				int R=j.first.r+haver(i), B=j.first.b+haveb(i);
				int c=max(max(r[k]-R, b[k]-B), 0), ik=i|1<<k;
				state s=state(j.first.r+c-max(r[k]-haver(i), 0), j.first.b+c-max(b[k]-haveb(i), 0));
				if(S[ik].find(s)==S[ik].end()||S[ik][s]>j.second+c+1)S[ik][s]=j.second+c+1;
			}
		}
	}
	int ans=oo;
	for(auto j:S[m-1])ans=min(ans, j.second);
	cout<<ans<<endl;
}
