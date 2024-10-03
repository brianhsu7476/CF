#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC optimize("no-math-errno,unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4")
//#pragma GCC target("popcntmabm,mmx,avx,arch-skylake")
//__builtin_ia32_ldmxcsr(__builtin_ia32_stmxcsr()|0x8040)
#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<n; ++i)
#define vec vector
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
using namespace std;
#define kN 1000006
#define oo 1000000007
#define endl '\n'

map<int, int> Last;
int last[kN], a[kN], n, sa[kN];

struct seg{
	seg *left, *right;
	int l, r, m, all;
	vec<pii> v;
	seg(){}
	seg(int l, int r):l(l), r(r), m(l+r>>1){
		if(r-l>1){
			left=new seg(l, m), right=new seg(m, r);
			//map<int, int> S;
			//for(int i=r-1; i>=l; --i)S[a[i]]=last[i];
			//vec<pii> u;
			int allxor=0;
			//for(auto i:S)u.pb(mp(i.second, i.first)), allxor^=i.first;
			for(int i=0, j=0; i<left->v.size()||j<right->v.size(); ){
				if(j==right->v.size()||i<left->v.size()&&left->v[i]<right->v[j]){
					v.pb(left->v[i]), ++i;
				}
				else{
					if(right->v[j].first<l)v.pb(right->v[j]);
					++j;
				}
			}
			for(int i=l; i<r; ++i)if(last[i]<l){
				//if(last[i]>=0)v.pb(mp(last[i], a[i]));
				allxor^=a[i];
			}
			all=allxor;
			//sort(v.begin(), v.end()); //reverse(v.begin(), v.end());
			/*for(int i=(int)v.size()-1; i>=0; --i){
				if(v[i].first<0)break;
				v[i]=mp(v[i].first, allxor^=v[i].second);
			}*/
			/*for(pii &i:v){
				if(i.first==l)continue;
				if(i.first<0)break;
				allxor^=i.second;
				i=mp(i.first, allxor);
			}
			reverse(v.begin(), v.end());*/
			//for(pii i:v)cout<<l<<' '<<r<<' '<<i.first<<' '<<i.second<<endl;
		}
		else{
			left=right=NULL;
			if(last[l]>=0)v.pb(mp(last[l], a[l]));
			all=a[l];
			//v.pb(mp(l, a[l]));
		}
	}
	void cal(){
		int allxor=all;
		for(int i=(int)v.size()-1; i>=0; --i){
			if(v[i].first<0)break;
			v[i]=mp(v[i].first, allxor^=v[i].second);
		}
		if(r-l>1)left->cal(), right->cal();
	}
	int qry(int ll, int rr){
		if(ll<=l&&r<=rr){
			int id=v.size();
			if(id==0||v[id-1].first<ll)return all;
			id=lower_bound(v.begin(), v.end(), mp(ll, -oo))-v.begin();
			//if(id==v.size())return all;
			return v[id].second;
		}
		int ans=0;
		if(ll<m)ans^=left->qry(ll, rr);
		if(m<rr)ans^=right->qry(ll, rr);
		return ans;
	}
};

seg *root;

signed main(){
	ios::sync_with_stdio(0), cin.tie(0);
	cin>>n, sa[0]=0;
	rep(i, n)cin>>a[i], sa[i+1]=sa[i]^a[i];
	rep(i, n){
		if(Last.find(a[i])!=Last.end())last[i]=Last[a[i]];
		else last[i]=-1;
		Last[a[i]]=i;
	}
	//rep(i, n)cout<<last[i]<<" \n"[i==n-1];
	root=new seg(0, n);
	root->cal();
	int m; cin>>m;
	//assert(n<1000000||m<1000000);
	while(m--){
		int l, r; cin>>l>>r, --l;
		cout<<(sa[r]^sa[l]^root->qry(l, r))<<endl;
	}
}
