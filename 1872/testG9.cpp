#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 5;
int a[N],s[N];
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int>v;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            s[i]=s[i-1]+a[i];
            if(a[i]!=1)
            {
                v.push_back(i);
            }
        }
        if(v.size()>=20)
        {
            cout<<v[0]<<" "<<v.back()<<endl;
            continue;
        }
        int ans=s[n],l=1,r=1,size=v.size();
        for(int len=1;len<=size;len++)
        {
            for(int i=0;i+len-1<size;i++)
            {
                int k=1;
                for(int j=0;j<len;j++)
                {
                    k*=a[v[i+j]];
                }
                if(s[v[i]-1]+k+s[n]-s[v[i+len-1]]>ans)
                {
                    ans=s[v[i]-1]+k+s[n]-s[v[i+len-1]];
                    l=v[i],r=v[i+len-1];
                }
            }
        }
        cout<<l<<" "<<r<<endl;
    }

    return 0;
}
