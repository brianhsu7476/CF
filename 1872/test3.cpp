#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <string>
#include <set>
#include <cmath>
#include <limits>
#include <unordered_map>
using namespace std;
 
 
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int> v;
        for(int i=0;i<n;i++){
            int a;cin>>a;
            v.push_back(a);
        }
        string s;cin>>s;
        int xr0=0,xr1=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='1')xr1^=v[i];
            else xr0^=v[i];
        }
        
        
        
        int q;cin>>q;
        for(int i=0;i<q;i++){
            int q1;cin>>q1;
            if(q1==2){
                int a;cin>>a;
                if(a==0)cout<<xr0<<" ";
                else cout<<xr1<<" ";
            }
            else{
                int l,r;cin>>l>>r;
                l--;r--;
                if((r-l)<n/2){
                    for(int i=l;i<=r;i++){xr1^=v[i];xr0^=v[i];}
                }
                else{
                    for(int i=0;i<l;i++){xr1^=v[i];xr0^=v[i];}
                    for(int i=r+1;i<n;i++){xr1^=v[i];xr0^=v[i];}
                    swap(xr0,xr1);
                }
            }
        }
        cout<<endl;
    }
    return 0;
}
