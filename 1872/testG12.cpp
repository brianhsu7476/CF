# include <bits/stdc++.h>
using namespace std;
typedef long long ll;

# define int long long
# define For(i, n) for(int i=0; i<n; i++)
# define Fori(i, n) for(int i=1; i<=n; i++)
# define Each(x, v) for(auto x : v)

int solve(){
  int n; cin >> n;
  int arr[n+1];
  int sum = 0;

  int psum[n+1];
  psum[0] = 0;

  vector<int> num;
  for(int i=1; i<=n; i++) {
    cin >> arr[i];
    sum += arr[i];
    psum[i] = sum;
    if(arr[i] > 1) num.push_back(i);
  }

  int prod = 1;
  int pprod[n+1];
  pprod[0] = 1;
  for(int i=1; i<=n; i++){
    prod *= arr[i];
    if(prod > 1e14){
      cout << num[0] << " " << num.back() << endl;
      return 0;
    }
    pprod[i] = prod;
  }

  // assume prod <= sum
  int maxDiff = 0;
  int l = 1, r = 1;
  for(int i=0; i<num.size(); i++){
    for(int j=i; j<num.size(); j++){
      int p = pprod[num[j]] / pprod[num[i]-1];
      int s = psum[num[j]] - psum[num[i]-1];
      // cerr << num[i] << " " << num[j] << " = " << s << " " << p << endl;
      if(p-s < 0) continue;
      if(p-s > maxDiff){
        maxDiff = p-s;
        l = num[i];
        r = num[j];
      }
    }
  }

  cout << l << " " << r << endl;
  return 0;
}

signed main(){
  ios_base :: sync_with_stdio(false);
  int t; cin >> t;
  while(t--){
    int ans = solve();
  }
}
