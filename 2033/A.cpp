#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

signed main(){
	ios::sync_with_stdio(0), cin.tie(0);
	int T;
	cin>>T;
	while(T--){
		int n; cin>>n;
		if(n&1)cout<<"Kosuke";
		else cout<<"Sakurako";
		cout<<endl;
	}
}
