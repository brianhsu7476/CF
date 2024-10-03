#include <bits/stdc++.h>
using namespace std;
#define kN 2003

int n, m;
bool a[kN][kN], b[kN][kN], ans[kN][kN];
bool now[kN];

signed main(){
	cin>>n>>m;
	for(int i=0; i<n; ++i)for(int j=0; j<m; ++j){
		char c; cin>>c;
		a[i][j]=b[i][j]=c=='#';
	}
	for(int i=0; i<n; ++i){
		for(int j=0; j<m; ++j)if(now[j])b[i][j]=1;
		for(int j=0; j<m; ++j){
			if(a[i][j])now[j]=0;
			if(!b[i][j]){
				ans[i][j]=now[j]=1;
				for(int k=j; k<m&&!a[i][k]; ++k)b[i][k]=1;
			}
		}
	}
	for(int i=0; i<n; ++i){
		for(int j=0; j<m; ++j){
			if(a[i][j])cout<<"#";
			else if(ans[i][j])cout<<"L";
			else cout<<".";
		}
		cout<<endl;
	}
}
