#include <bits/stdc++.h>
#define int long long
#define rep(i,n) for(int i=0; i<n; ++i)
using namespace std;
#define kN 10004
#define oo 1000000007

int n, a[kN], b[kN];

int isGeo(int n){
	// x 0 0 0 0 ...
	int cnt0=0;
	for(int i=1; i<n; ++i)if(b[i])++cnt0;
	// a b ...
	int cnt1=0;
	if(b[0]==0||b[1]==0)cnt1=oo;
	int c=b[1];
	for(int i=2; i<n; ++i){
		if(b[i]*b[0]==c*b[1])c=b[i];
		else ++cnt1;
	}
	return min(cnt0, cnt1);
}

signed main(){
	cin>>n;
	rep(i, n)cin>>a[i];
	/*if(n==2&&a[0]==0&&a[1]){cout<<"1\n"; return 0;}
	if(n<=2){cout<<"0\n"; return 0;}
	if(n==3){
		if(a[0]==0&&a[1]==0&&a[2])cout<<"1\n";
		else if(a[0]*a[2]==a[1]*a[1])cout<<"0\n";
		else cout<<"1\n";
		return 0;
	}
	bool ok=a[0]&&a[1];
	for(int i=2; i<n; ++i)if(a[i]){ok=0; break;}
	if(ok){cout<<"1\n"; return 0;}*/
	/*rep(t, 2){
		int b=a[1], cnt=0;
		if(a[0]==0&&a[1]){reverse(a, a+n); continue;}
		if(a[0]==0&&a[1]==0){
			rep(i, n)if(a[i])++cnt;
		}
		else{
			if(t==1&&b==0)break;
			for(int i=2; i<n; ++i){
				if(a[i]*a[0]==b*a[1])b=a[i];
				else ++cnt;
			}
		}
		if(cnt==0){cout<<"0\n"; return 0;}
		if(cnt==1){cout<<"1\n"; return 0;}
		reverse(a, a+n);
	}*/
	rep(i, n)b[i]=a[i];
	int cnt0=isGeo(n);
	for(int i=0; i<n-1; ++i)b[i]=a[i+1];
	int cnt1=isGeo(n-1)+1;
	b[0]=a[0];
	int cnt2=isGeo(n-1)+1, ans=min(min(cnt0, cnt1), cnt2);
	cout<<(ans<2?ans:2)<<endl;
}
