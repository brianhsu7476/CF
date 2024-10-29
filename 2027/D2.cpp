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

const int oo=1000000000000015;
#define mod 1000000007
#define kN 300005

int n, m, a[kN], b[kN], sa[kN];
vector<int> dp[kN], cnt[kN], dp2[kN];

struct seg{
	int l, r, mid, v, lz;
	seg *left, *right;
	seg(){}
	seg(int l, int r):l(l), r(r), mid(l+r>>1){
		lz=0;
		if(r-l<2)left=right=NULL, v=lz=0;
		else left=new seg(l, mid), right=new seg(mid, r), pull();
	}
	void pull(){
		left->push(), right->push(), v=(left->v+right->v)%mod;
	}
	void push(){
		if(r-l>1)left->lz+=lz, right->lz+=lz;
		v+=lz, lz=0;
	}
	/*void upd(int ll, int rr, int v){
		if(ll<=l&&r<=rr){lz+=v, push(); return;}
		push();
		if(ll<mid)left->upd(ll, rr, v);
		if(mid<rr)right->upd(ll, rr, v);
		pull();
	}*/
	void upd(int x, int vv){
		if(r-l==1){v+=vv; return;}
		if(x<mid)left->upd(x, vv);
		else right->upd(x, vv);
		pull();
	}
	int qry(int ll, int rr){
		push();
		if(ll<=l&&r<=rr)return v;
		int res=0;
		if(ll<mid)res+=left->qry(ll, rr);
		if(mid<rr)res+=right->qry(ll, rr);
		return res%mod;
	}
};

/*
void upd(int i, int j, int v){
	for(int x=j+1; x<=n+1; x+=x&-x)cnt2[i][x]+=v;
}

int qry(int i, int j){
	int res=0;
	for(int x=j+1; x; x-=x&-x)res+=cnt2[i][x];
	return res;
}
*/

signed main(){
	ios::sync_with_stdio(0), cin.tie(0);
	int T; cin>>T;
	while(T--){
		cin>>n>>m;
		sa[0]=0;
		for(int i=0; i<n; ++i)cin>>a[i], sa[i+1]=sa[i]+a[i];
		for(int i=0; i<m; ++i)cin>>b[i];
		for(int i=0; i<=n; ++i)dp[i].resize(m+1), cnt[i].resize(m+1);
		for(int i=0; i<=m; ++i)dp2[i].resize(n+1);
		dp[0][0]=0;
		for(int i=1; i<=m; ++i)dp[0][i]=0;
		for(int i=0; i<n; ++i)for(int j=0; j<m; ++j){
			int l=lower_bound(sa, sa+n+1, sa[i+1]-b[j])-sa;
			if(l==i+1)dp[i+1][j]=oo;
			else dp[i+1][j]=dp[l][j]+m-j-1;
			if(j)dp[i+1][j]=min(dp[i+1][j], dp[i+1][j-1]);
			dp[i+1][j]=min(dp[i+1][j], oo);
			if(j==m-1)orange(dp[i+1].begin(), dp[i+1].end());
		}
		int ans=oo;
		for(int j=0; j<m; ++j)ans=min(ans, dp[n][j]);
		if(ans==oo){cout<<"-1"<<endl; continue;}
		cout<<ans<<' ';
		for(int i=0; i<=n; ++i)for(int j=0; j<=m; ++j)dp2[j][i]=dp[i][j];
		for(int i=0; i<=m; ++i)cnt[0][i]=1;
		for(int j=0; j<m; ++j){
			seg *root=new seg(0, n+1);
			root->upd(0, cnt[0][j]);
			for(int i=0; i<n; ++i){
				cnt[i+1][j]=0;
				int l=lower_bound(sa, sa+n+1, sa[i+1]-b[j])-sa;
				int r=lower_bound(dp2[j].begin(), dp2[j].end(), dp2[j][l]+1)-dp2[j].begin();
				if(l<=i&&dp[i+1][j]==dp[l][j]+m-j-1)cnt[i+1][j]+=root->qry(l, r), cnt[i+1][j]%=mod;
				if(j&&dp[i+1][j]==dp[i+1][j-1])cnt[i+1][j]+=cnt[i+1][j-1], cnt[i+1][j]%=mod;
				//l=lower_bound(dp2[j].begin(), dp2[j].end(), dp2[j][i+1])-dp2[j].begin();
				root->upd(i+1, cnt[i+1][j]);
			}
			//vector<int> tmp;
			//for(int i=0; i<=n; ++i)cout<<cnt[i][j]<<" \n"[i==n];
			//orange(tmp.begin(), tmp.end());
		}
		int ans2=0;
		for(int j=0; j<m; ++j)if(dp[n][j]==ans)ans2+=cnt[n][j];
		cout<<cnt[n][m-1]<<endl;
	}
}
