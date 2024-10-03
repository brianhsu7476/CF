#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
using namespace std;
#define kN 4003

int n, m, l[kN], r[kN], cnt0[kN], cnt1[kN];

bool in(int x, int l, int r){
	if(l<r)return l<=x&&x<=r;
	if(l>r)return x<=r||l<=x;
}

int diff(int i, int j){ // return j-i
	return i<=j?j-i:j-i+m;
}

int add(int i, int j){
	return i+j<m?i+j:i+j-m;
}

signed main(){
	cin>>n, m=n<<1;
	for(int i=0; i<n; ++i)cin>>l[i]>>r[i];
	int ans=0;
	for(int i=0; i<m; ++i){
		int i0=i?i-1:i+m-1, j0=n, j1=n;
		for(int j=0; j<n; ++j){
			if(l[j]==i)j0=j;
			if(r[j]==i0)j1=j;
		}

		/*
		vector<int> a, b;
		for(int j=0; j<n; ++j){
			if(in(i, l[j], r[j]))a.push_back(j);
			if(in(i0, l[j], r[j]))b.push_back(j);
		}
		sort(a.begin(), a.end(), [](int x, int y){
			return diff(i, r[x])<diff(i, r[y]);
		});
		sort(b.begin(), b.end(), [](int x, int y){
			return diff(i0, l[x])<diff(i0, l[y]);
		});
		for(int j=0; j<m; ++j)cnt0[j]=cnt1[j]=0;
		int cnt0=0, cnt1=0, cnt=0;
		for(int j=0; j<m; ++j){
			if(add(i+j)>r[a[cnt0]])++cnt0;
			if(add(i+j)<=l[b[cnt1]])++cnt1;
			int cnt=n-cnt0+cnt1;
			if(cnt>ans){
				ans=cnt, idi=i, idj=j;
			}
			cnt=max(cnt, n-cnt0+cnt1);
		}
		*/
	}
}
