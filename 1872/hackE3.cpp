#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

#define kN 100005
int a[kN], n;

signed main(){
	n=100000;
	cout<<"1\n"<<n<<endl;
	for(int i=0; i<n; ++i)a[i]=rand()%1000000000+1;
	for(int i=0; i<n; ++i)cout<<a[i]<<" \n"[i==n-1];
	for(int i=0; i<n; ++i)cout<<0;
	cout<<endl;
	cout<<n<<endl;
	for(int i=0; i<n; ++i)cout<<"2 0\n";
}
