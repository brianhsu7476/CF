#include <bits/stdc++.h>
using namespace std;
#define kN 16

int n, r[kN], b[kN];
char c[kN];

signed main(){
	cin>>n;
	for(int i=0; i<n; ++i)r[i]=rand()%10, b[i]=rand()%10, c[i]=rand()&1?'R':'B';
	cout<<n<<endl;
	for(int i=0; i<n; ++i)cout<<c[i]<<' '<<r[i]<<' '<<b[i]<<endl;
}
