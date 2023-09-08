#include <bits/stdc++.h>
#define Rep(i, j, n) for (int i(j); i <= n; ++i)
#define Per(i, j, n) for (int i = j; i >= n; --i)
#define rep(i, n) for (int i(0); i < n; ++i)
#define per(i, n) for (int i(n - 1); ~i; --i)
#define i64 long long
using namespace std;
int fp =  -1, kcase;
void solve() {
	int n; cin >> n;
	i64 sum = 0;
	long double prod = 1;
	vector <int> v, a(n + 1);
	vector <i64> s(n + 1), prd(n + 1);
	Rep(i, 1, n) cin >> a[i], sum += a[i], s[i] = s[i - 1] + a[i];
	
	Rep(i, 1, n) {
		prod *= a[i];
		if (prod >= 1e18) break;
	}
	if (prod == 1) {cout << 1 << ' ' << 1 << '\n'; return ;}
	Rep(i, 1, n) if (a[i] >= 2) v.emplace_back(i);
	if (prod >= 1e18) {
		cout << v.front() << ' ' << v.back() << '\n';
		return ;
	}
	prd[0] = 1; Rep(i, 1, n) prd[i] = prd[i - 1] * a[i];
	pair <i64, pair <int, int> > ans = make_pair(0, make_pair(1, 1));
	rep(_, (int)v.size()) Rep(__, _, (int)v.size() - 1) {
		int i = v[_], j = v[__];
		ans = max(ans, make_pair(prd[j] / prd[i - 1] - (s[j] - s[i - 1]), make_pair(i, j)));
	}
	cout << ans.second.first << ' ' << ans.second.second << '\n';
}
signed main(void) {
	ios::sync_with_stdio(false); 
	cin.tie(NULL); cout.tie(NULL);
	int T; cin >> T; while (T--) solve();
}
