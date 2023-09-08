#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;

  vector<int> a(n + 1), pos;
  vector<long long> pref(n + 1), prod(n + 1);
  prod[0] = 1;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    prod[i] = prod[i - 1] * a[i];
    pref[i] = pref[i - 1] + a[i];
    if (a[i] > 1) pos.push_back(i);
  }

  if ((int)pos.size() > 30) {
    cout << pos[0] << ' ' << pos.back() << '\n';
    return;
  }

  auto calc = [&](int i, int j) {
    return prod[j] / prod[i - 1] - pref[j] + pref[i - 1];
  };

  int l = 1, r = 1;
  for (int i : pos) {
    for (int j : pos) {
      if (j >= i && calc(i, j) > calc(l, r)) {
        l = i, r = j;
      }
    }
  }

  cout << l << ' ' << r << '\n';
}

int main() {
  cin.tie(0)->sync_with_stdio(false);

  int tt = 1;
  cin >> tt;

  while (tt--) {
    solve();
  }

  return 0;
}
