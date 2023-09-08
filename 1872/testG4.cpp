#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define MP make_pair
mt19937 rnd(time(0));
const int MAXN=2e5+5;
ld t[MAXN];ll s[MAXN],a[MAXN],n;
ld calc(int l,int r){return t[r]/t[l-1]-(s[r]-s[l-1]);} 
void solve(){
	cin>>n;
	for(int j=1;j<=n;j++){
		cin>>a[j];
		s[j]=s[j-1]+a[j];t[j]=t[j-1]*a[j];
	}
	int l=1,r=1;
	vector<int> sp;
	for(int j=1;j<=n;j++) if(a[j]>=2) sp.push_back(j);
	if(sp.size()>60){
		cout<<sp[0]<<' '<<sp.back()<<endl;
		return;
	}else{
		for(int j:sp) for(int i:sp) if(j<=i)
			if(calc(j,i)>calc(l,r)) l=j,r=i;
	}
	cout<<l<<' '<<r<<endl;
}
int main(){
	ios::sync_with_stdio(false);
	t[0]=1;
	int _;cin>>_;
	while(_--) solve();
}
