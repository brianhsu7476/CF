#include <bits/stdc++.h>
#define double long double
using namespace std;
#define kN 1003

int n, m, c, a[kN];

signed main(){
	cin>>n>>m>>c, --n, --c;
	for(int i=0; i<m; ++i)cin>>a[i];
	int x=0;
	for(int i=0; i<m; ++i)x+=a[i];
	int y=x-a[c];
	--x;
	if(x<n){cout<<"-1\n"; return 0;}
	//cout<<x<<' '<<y<<endl;
	double ans=1;
	for(int i=0; i<n; ++i){
		ans*=y-i, ans/=x-i;
	}
	cout<<setprecision(10)<<1-ans<<endl;
}
