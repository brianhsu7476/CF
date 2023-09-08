#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n; cin >> n;
	vector<int> vc(n);
	for (auto& it : vc) cin >> it;

	vector<int> pos;
	for (int i = 0; i < n; ++i) {
		if (vc[i] != 1) {
			pos.push_back(i);
		}
	}

	if (pos.size() < 2) {
		cout << 1 << " " << 1 << endl;
		return;
	}

	vector<long long> sums(n, 0);
	for (int i = 0; i < n; ++i) {
		sums[i] = vc[i];
		if (i != 0) sums[i] += sums[i - 1];
	}
	const auto get_s = [&sums](int l, int r) {
		if (l == 0) return sums[r];
		return sums[r] - sums[l - 1];
	};

	if (pos.size() > 30) {
		cout << pos.front() + 1 << " " << pos.back() + 1 << endl;
		return;
	}

	long double log_sum = 0;
	for (const auto p : pos) {
		long double cur = vc[p];
		log_sum += log2(cur);
	}

	if (log_sum >= 30) {
		cout << pos.front() + 1 << " " << pos.back() + 1 << endl;
		return;
	}

	long long best = 0;
	pair<int, int> cur_ans = {1, 1};
	for (int li = 0; li < pos.size(); ++li) {
		long long mult = vc[pos[li]];
		for (int ri = li + 1; ri < pos.size(); ++ri) {
			mult *= vc[pos[ri]];
			if (mult - get_s(pos[li], pos[ri]) > best) {
				best = mult - get_s(pos[li], pos[ri]);
				cur_ans = {pos[li] + 1, pos[ri] + 1};
			}
		}
	}

	cout << cur_ans.first << " " << cur_ans.second << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) solve();

	return 0;
}
