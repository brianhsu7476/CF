#include <bits/stdc++.h>
using namespace std;
#define kN 1000006

int a[kN];

signed main(){
	int n=1000000;
	cout<<n<<endl;
	for(int i=0; i<n; ++i)a[i]=rand()%100;
	for(int i=0; i<n; ++i)cout<<a[i]<<" \n"[i==n-1];
	cout<<n<<endl;
	for(int i=0; i<n; ++i){
		int l=rand()%n+1, r=rand()%n+1;
		if(l>r)swap(l, r);
		cout<<l<<' '<<r<<endl;
	}
}
