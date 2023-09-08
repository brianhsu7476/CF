#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int tc; cin >> tc;
	while (tc--) {
		int n; cin >> n;
		vector<int> a(n);
		long long sum = 0;
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			sum += a[i];
			if (a[i] > 1) cnt++;
		}
		if (cnt > 100) {
			int st = 0;
			int ed = n - 1;
			while (st < n && a[st] == 1) st++;
			while (ed >= st && a[ed] == 1) ed--;
			cout << st + 1 << ' ' << ed + 1 << "\n";
			continue;
		}
		vector<int> pos;
		for (int i = 0; i < n; i++)
			if (a[i] != 1) pos.push_back(i);
		
		long long mx = sum;
		int st = 1, ed = 1;
		for (int i = 0; i < pos.size(); i++) {
			for (int j = i + 1; j < pos.size(); j++) {
				long long p = 1;
				long long s = sum;
				for (int k = i; k <= j; k++) {
					p *= a[pos[k]];
					s -= a[pos[k]];
				}
				s -= pos[j] - pos[i] - j + i;
				if (mx < p + s) {
					mx = p + s;
					st = pos[i] + 1;
					ed = pos[j] + 1;
				}
			}
		}
		cout << st << ' ' << ed << "\n";
	}
	return 0;
}
