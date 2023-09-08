#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<ld, ld> pd;
 
template<class T, class U> 
ostream& operator << (ostream& out, const pair<T, U> pi) {
	out << "(" << pi.first << "," << pi.second << ") ";
	return out;
}
template<class T> 
ostream& operator << (ostream& out, const vector<T>& v) {
	for (auto x : v) cout << x << " ";
	return out;
}
 
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
const auto start_time = chrono::steady_clock::now();
void time_elapsed() {
	auto diff = chrono::steady_clock::now() - start_time;
	cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
}


const int MAXN = 1e5 + 5;
int arr0[MAXN];
int arr1[MAXN];

void solve() {
	int n; cin >> n;
	vector<int> v(n);
	for (int i=0; i<n; i++) {
		cin >> v[i];
	}

	string s; cin >> s;
	for (int i=0; i<n; i++) {
		if (s[i] == '0') {
			arr0[i] = v[i];
			arr1[i] = 0;
		} else {
			arr0[i] = 0;
			arr1[i] = v[i];
		}
	}

	int q; cin >> q;
	for (int i=0; i<q; i++) {
		int t; cin >> t;
		if (t == 1) {
			int a, b;
			cin >> a >> b;
			a--; b--;
			for (int j=a; j<=b; j++) {
				if (arr0[j] == 0) {
					arr0[j] = arr1[j];
					arr1[j] = 0;
				} else {
					arr1[j] = arr0[j];
					arr0[j] = 0;
				}
			}
		} else {
			int x; cin >> x;
			int xr = 0;
			if (x == 0) {
				for (int j=0; j<n; j++) {
					xr = (xr ^ arr0[j]);
				} 
			} else {
				for (int j=0; j<n; j++) {
					xr = (xr ^ arr1[j]);
				}
			}
			cout << xr << " ";
		}
	}
	cout << endl;
}
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		solve();
	}
}
