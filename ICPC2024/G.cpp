#include <bits/stdc++.h>
#define double long double
#define int long long
#define rep(i,n) for(int i=0; i<n; ++i)
using namespace std;
#define kN 100005
#define eps 1e-6

int n, p, a[kN], b[kN];

bool check(double t){
	double c=0;
	rep(i, n)c+=max(t*a[i]-b[i], (double)0.0);
	return t*p>=c;
}

signed main(){
	cin>>n>>p;
	rep(i, n)cin>>a[i]>>b[i];
	int tt=0;
	rep(i, n)tt+=a[i];
	if(tt<=p){cout<<"-1\n"; return 0;}
	double l=0, r=1;
	while(check(r))r*=2;
	while(r-l>eps){
		double m=(l+r)/2;
		if(check(m))l=m;
		else r=m;
	}
	cout<<setprecision(10)<<l<<endl;
}
