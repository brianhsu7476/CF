#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
using namespace std;
#define kN 2003
#define oo 1000000007

int n, a[kN][kN], l[kN], r[kN], ans[kN][kN];
int dx[6]={0, -1, -1, 0, 1, 1}, dy[6]={1, 0, -1, -1, 0, 1};
vector<int> G[kN];

int id(int i, int j){
	return i*(2*n-1)+j;
}

pii pos(int i){
	return mp(i/(2*n-1), i%(2*n-1));
}

bool in(int x, int y){
	return 0<=x&&x<2*n-1&&l[x]<=y&&y<r[x];
}

signed main(){
	cin>>n;
	cout<<n<<endl;
	for(int i=0; i<2*n-1; ++i){
		l[i]=i<n?0:i-n+1, r[i]=i<n?n+i:n*2-1;
		for(int j=l[i]; j<r[i]; ++j)cout<<1<<' ';
		cout<<endl;
	}
	/*
	queue<int> bfs;
	for(int i=0; i<2*n-1; ++i)for(int j=l[i]; j<r[i]; ++j){
		for(int d=0; d<6; ++d){
			int i1=i+dx[d], j1=j+dy[d];
			if(in(i1, j1)&&a[i][j]==a[i1][j1])G[id(i, j)].push_back(id(i1, j1));
			else bfs.push(id(i, j));
		}
	}
	while(!bfs.empty()){
		int i=bfs.front(), ix=pos(i).first, iy=pos(i).second;
		bfs.pop();
		if(ans[ix][iy])continue;
		ans[ix][iy]=oo;
		if(G[i].size()<6)ans[ix][iy]=1;
		for(int j:G[i]){
			int jx=pos(j).first, jy=pos(j).second;
			if(G[i].size()<6)bfs.push(j);
			else if(ans[jx][jy])ans[ix][iy]=min(ans[ix][iy], ans[jx][jy]+1);
			else bfs.push(j);
		}
	}
	for(int i=0; i<n*2-1; ++i){
		for(int j=l[i]; j<r[i]; ++j)cout<<ans[i][j]<<' ';
		cout<<endl;
	}
	*/
}
