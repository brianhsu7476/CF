#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>
#include <algorithm>
#define int long long
using namespace std;
int MOD[5]={1000000000+7,1000000000+9,998244353};
int pre[5][5][200005];
int con[30][200005];
char all[5][200005];
int rd[30];
int Hash[5][5];
int l[5],r[5];
int how[5];
int ttt[200005];
int Pow(int a,int b,int xx)
{
    if(b==0) return 1;
    int t=Pow(a,b/2,xx);
    t=t*t%MOD[xx];
    if(b%2) t=t*a%MOD[xx];
    return t;
}
signed main()
{
    //srand(time(NULL));
    int T,N,M,i,ok=0,t=1,j,k,n;
    scanf("%lld",&T);
    for(i=0;i<26;i++) rd[i]=i;
    how[0]=Pow(26,MOD[0]-2,0);
    how[1]=Pow(26,MOD[1]-2,1);
    how[2]=Pow(26,MOD[2]-2,2);
    while(T--)
    {
        //random_shuffle(rd,rd+26);
        scanf("%lld %lld",&N,&M);

        scanf("%s",all[0]+1);
        all[0][0]='@';
        for(i=1;i<=N;i++)
        {
            ttt[i]=i;
            if(i>=2&&all[0][i]!=all[0][i-1])
            {
                ttt[i]=i-1;
                if(i>=3&&all[0][i]==all[0][i-2])
                {
                    ttt[i]=i-2;
                    if(i>=4&&all[0][i-1]==all[0][i-3]) ttt[i]=ttt[i-2];
                }
            }
            //printf("%lld %lld\n",i,ttt[i]);
        }

        for(i=1;i<=N;i++) all[1][i]=all[0][N+1-i];
        for(i=0;i<2;i++) for(j=0;j<3;j++) for(k=1,t=1;k<=N;k++)
        {
            pre[i][j][k]=(pre[i][j][k-1]+rd[all[i][k]-'a']*t)%MOD[j];
            //printf("%lld %lld %lld %lld\n",i,j,k,pre[i][j][k]);
            t=t*26%MOD[j];
        }

        for(i=1;i<=N;i++) for(j=0;j<26;j++) con[j][i]=con[j][i-1]+((all[0][i]-'a')==j);
        while(M--)
        {
            scanf("%lld %lld",&l[0],&r[0]);
            l[1]=N+1-r[0];
            r[1]=N+1-l[0];
            ok=0;

            for(i=0;i<26;i++) if(con[i][r[0]]-con[i][l[0]-1]==r[0]-l[0]+1) ok=1;
            if(ok)
            {
                printf("0\n");
                continue;
            }
            if(ttt[r[0]]<=l[0])
            {
                //printf("aa\n");
                int a=2,b=r[0]-l[0]+1;
                b=b/2*2;
                printf("%lld\n",(a+b)*((b-a)/2+1)/2);
                continue;

            }
            for(i=0;i<2;i++)
            {
                for(j=0;j<3;j++)
                {

                    Hash[i][j]=(pre[i][j][r[i]]-pre[i][j][l[i]-1]+MOD[j])%MOD[j]*Pow(how[j],l[i]-1,j)%MOD[j];
                    //printf("%lld\n",Hash[i][j]);
                }
            }
            n=r[0]-l[0]+1;
            if(Hash[0][0]==Hash[1][0]&&Hash[0][1]==Hash[1][1]&&Hash[0][2]==Hash[1][2]) printf("%lld\n",(2+n-1)*(n-2)/2);
            else printf("%lld\n",(2+n)*(n-1)/2);

        }

    }

    return 0;
}
