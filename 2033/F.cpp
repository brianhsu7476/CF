#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

#define kN 1000006
#define mod 1000000007
int f[kN];

struct mat{
	int a[2][2]={{1, 0}, {0, 1}};
	mat operator*(const mat b)const{
		mat c;
		for(int i=0; i<2; ++i)for(int j=0; j<2; ++j){
			c.a[i][j]=0;
			for(int k=0; k<2; ++k)c.a[i][j]+=a[i][k]*b.a[k][j]%mod;
			c.a[i][j]%=mod;
		}
		return c;
	}
};

mat Pow(mat a, int b){
	mat r;
	for(; b; b>>=1, a=a*a)if(b&1)r=r*a;
	return r;
}

int F(int n){
	mat a;
	a.a[0][0]=a.a[0][1]=a.a[1][0]=1, a.a[1][1]=0;
	return Pow(a, n).a[1][0];
}

signed main(){
	ios::sync_with_stdio(0), cin.tie(0);
	int T;
	cin>>T;
	while(T--){
		int m, n, k;
		cin>>n>>k;
		f[0]=0, f[1]=1;
		for(int i=2; i<kN; ++i){
			f[i]=(f[i-1]+f[i-2])%k;
			if(!f[i]){m=i; break;}
		}
		if(k==1)m=1;
		cout<<n%mod*m%mod<<endl;
		//cout<<F(n%(mod+1)*m%(mod+1))<<endl;
		//for(int i=0; i<10; ++i)cout<<F(i)<<" \n"[i==9];

		//cout<<F(mod+1)<<endl;
	}
}
