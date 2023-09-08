#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
#define all(x) x.begin(),x.end()
#define ff first
#define ss second
#define pb push_back
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;

int32_t main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int arr[n+5];
		int cnt=0,s=0,pre[n+5],pre2[n+5];
		pre[0]=0;
		pre2[0]=1;
		vector<int>v;
		for(int i=1;i<=n;i++){
			cin>>arr[i];
			cnt+=(arr[i]!=1);
			pre[i]=pre[i-1]+arr[i];
			pre2[i]=pre2[i-1]*arr[i];
			s+=arr[i];
			if(arr[i]!=1)v.pb(i);
		}
		if(cnt>=60){
			int l=1,r=n;
			while(arr[l]==1)l++;
			while(arr[r]==1)r--;
			cout<<l<<" "<<r<<endl;	
		}
		else{
			int mx=s,ans=1,ans2=1;
			for(int i=0;i<v.size();i++){
				for(int j=i;j<v.size();j++){
					if(mx<s-(pre[v[j]]-pre[v[i]-1])+pre2[v[j]]/pre2[v[i]-1]){
						mx=s-(pre[v[j]]-pre[v[i]-1])+pre2[v[j]]/pre2[v[i]-1];
						ans=v[i];
						ans2=v[j];
					}
				}
			}
			cout<<ans<<" "<<ans2<<endl;
		}
	}
}
