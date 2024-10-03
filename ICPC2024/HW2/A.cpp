#include <bits/stdc++.h>
#define int long long
#define double long double
using namespace std;

int n;
double a;

signed main(){
	ios::sync_with_stdio(0), cin.tie(0);
	cin>>n>>a;
	//cout<<setprecision(12)<<a<<endl;
	double ans=0, l=(double)(n-1)/n;
	for(int i=1; i<n; l*=(double)(n-1-i)/(n+i), ++i){
		double k=1.0/i;
		for(int j=0; j<=i; k*=(double)(i-j)/(double)(n+j), ++j)ans+=j&1?-k:k;
		//cout<<i<<' '<<ans<<endl;
		ans+=i&1?l/i:-l/i;
	}
	//cout<<ans/(n-1)<<endl;
	cout<<setprecision(12)<<a+(1-a*n)*ans/(n-1)<<endl;
}
