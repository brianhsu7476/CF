#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<n; ++i)
#define pii pair<int, int>
#define mp make_pair
using namespace std;
#define kN 1000006
#define endl '\n'

map<int, int> Nxt;
int n, a[kN], nxt[kN], sa[kN];

struct seg{
	seg *left, *right;
	int l, r, m, v;
	seg(){}
	seg(int l, int r):l(l), r(r), m(l+r>>1){
		if(r-l>1){
			left=new seg(l, m), right=new seg(m, r), pull();
		}
		else{
			left=right=NULL, v=a[l];
		}
	}
	void pull(){
		v=left->v^right->v;
	}
	void upd(int x, int u){
		if(l<=x&&x<r){
			v^=u;
			if(r-l>1){
				if(x<m)left->upd(x, u);
				else right->upd(x, u);
			}
		}
	}
	int qry(int ll, int rr){
		if(ll<=l&&r<=rr){
			return v;
		}
		int ans=0;
		if(ll<m)ans^=left->qry(ll, rr);
		if(m<rr)ans^=right->qry(ll, rr);
		return ans;
	}
};

seg *root;

struct query{
	int l, r, id;
	query(){}
	query(int l, int r, int id):l(l), r(r), id(id){}
};

query q[kN];
int ans[kN];

signed main(){
	ios::sync_with_stdio(0), cin.tie(0);
	cin>>n;
	rep(i, n)cin>>a[i], sa[i+1]=sa[i]^a[i];
	for(int i=n-1; i>=0; --i){
		if(Nxt.find(a[i])==Nxt.end())Nxt[a[i]]=i, nxt[i]=n;
		else nxt[i]=Nxt[a[i]], Nxt[a[i]]=i;
	}
	//rep(i, n)cout<<nxt[i]<<" \n"[i==n-1];
	root=new seg(0, n);
	int m; cin>>m;
	rep(i, m){
		int l, r;
		cin>>l>>r, --l;
		q[i]=query(l, r, i);
	}
	sort(q, q+m, [](query a, query b){
		return a.l>b.l||a.l==b.l&&a.r<b.r;
	});
	int nowl=n;
	rep(i, m){
		while(nowl>q[i].l)--nowl, root->upd(nxt[nowl], a[nowl]);
		ans[q[i].id]=root->qry(q[i].l, q[i].r)^sa[q[i].l]^sa[q[i].r];
	}
	rep(i, m)cout<<ans[i]<<endl;
}
