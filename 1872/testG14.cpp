#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int,int> ;
#define ls u<<1
#define rs u<<1|1
template<class T> T lowbit(T x) {return x&-x;}
//#define int long long
#define endl '\n'
const int eps = 1e-5;
const int INF = 0x3f3f3f3f;
const long long LNF = 0x3f3f3f3f3f3f3f3f;
ll n,m,k,q;
const int mod = 1e9+7;
const int N = 2e5+10;
const int M = N<<1;
int debug=1;
ll a[N];
ll sum[N];
ll mx=1e10;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	int l=1,r=n;
	while(a[l]==1&&l<n) l++;
	while(a[r]==1&&l<r) r--;
	ll mut=1;
	int flag=0;
	for(int i=l;i<=r;i++)
	{
		mut*=a[i];
		if(mut>mx)
		{
			flag=1;
			break;
		}
	}
	if(flag)
	{
		cout<<l<<' '<<r<<endl;
	}
	else
	{
		vector<int> pos;
		ll mx=sum[n];
		l=1,r=1;
		for(int i=1;i<=n;i++)
		{
			if(a[i]>1) pos.push_back(i);
		}
		for(int i=0;i<pos.size();i++)
		{
			for(int j=i+1;j<pos.size();j++)
			{
				ll val=1;
				for(int k=i;k<=j;k++)
				{
					val*=a[pos[k]];
				}
				ll k=sum[pos[i]-1]+sum[n]-sum[pos[j]]+val;
				//cout<<i<<' '<<j<<' '<<k<<endl;
				if(k>mx)
				{
					mx=k;
					l=pos[i],r=pos[j];
				}
			}
		}
		cout<<l<<' '<<r<<endl;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int t=1;
	if(debug) cin>>t;
	while(t--) solve();
}
