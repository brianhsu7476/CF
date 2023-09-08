#include<iostream>
#include<algorithm>
const int sz=2e5+10;
int a[sz],p[sz];
__int128 mul[sz],sum[sz];
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin>>t;
    while(t--){
        int n;
        std::cin>>n;
        int cnt=0;
        for(int i=1;i<=n;i++){
            std::cin>>a[i];
            if(a[i]!=1)p[++cnt]=i;
        }
        if(cnt>20){
            int l=1,r=n;
            while(a[l]==1)l++;
            while(a[r]==1)r--;
            std::cout<<l<<" "<<r<<"\n";
        }else{
            mul[0]=1;
            for(int i=1;i<=n;i++)
                sum[i]=sum[i-1]+a[i],mul[i]=mul[i-1]*a[i];
            std::pair<int,int>cur=std::make_pair(1,1);
            long long max=0;
            for(int l=1;l<=cnt;l++)
                for(int r=l;r<=cnt;r++)
                    if(mul[p[r]]/mul[p[l]-1]-sum[p[r]]+sum[p[l]-1]>max)
                        max=mul[p[r]]/mul[p[l]-1]-sum[p[r]]+sum[p[l]-1],cur=std::make_pair(p[l],p[r]);
            std::cout<<cur.first<<" "<<cur.second<<"\n";
        }
    }
    return 0;
}
