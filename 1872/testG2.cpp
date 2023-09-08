#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
typedef long long ll;
typedef pair<ll,ll>PLL;
vector<PLL>v;
int n;
ll s[N];
ll ans,l=1,r=1;
 void solve()
 {
  v.clear();ans=0;
  l=1,r=1;
  cin>>n;
  for(int i=1;i<=n;i++)
  {
  	ll c;
  	cin>>c;
  	s[i]=s[i-1]+c;
  	if(c>1)
  	v.push_back({c,i});
  }
  //cout<<s[n]<<'\n';
  ll p=1;
  for(int i=0;i<v.size();i++)
  {
  	p=p*v[i].first;
  	if(p>=1e14)break;
  }
  if(p>=1e14)
  {
  	cout<<v[0].second<<" "<<v.back().second<<'\n';
  	return ;
  }
  //cout<<v.size()<<'\n';
  for(int i=0;i<v.size();i++)
  {
  	ll k=1;
  	for(int j=i;j<v.size();j++)
  	{
  		k=k*v[j].first;
  		ll res=k+s[v[i].second-1]+s[n]-s[v[j].second];
  		if(res>ans)
  		ans=res,l=v[i].second,r=v[j].second;
	  }
  }
  cout<<l<<" "<<r<<'\n';
 }
 int main()
 {
 	ios::sync_with_stdio(false);
 	cin.tie(0),cout.tie(0);
 	int T;
 	cin>>T;
 	while(T--)solve();
 	return 0;
 }
