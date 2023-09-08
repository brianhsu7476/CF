#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<ll>
#define vvll vector<vll>

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        vll a(n);
        __int128_t prod = 1;
        bool dall = false;
        vll non_ones;
        for (ll i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] != 1) non_ones.push_back(i);
        }
        for (ll v : a) {
            prod *= v;
            if (prod > 1e15) {
                dall = true;
                break;
            }
        }
        if (dall) {
            cout << non_ones[0]+1 << ' ' << non_ones.back()+1 << '\n';
            continue;
        }
        ll maxv = 0;
        pair<ll,ll> maxp = {0, 0};
        for (ll l : non_ones) {
            ll prod = 1;
            ll sum = 0;
            ll cnt = 0;
            for (ll r : non_ones) {
                if (l <= r) {
                    prod *= a[r];
                    sum += a[r];
                    cnt++;

                    ll sugv = prod - (sum + r-l+1 - cnt );
                    if (sugv > maxv) {
                        maxv = sugv;
                        maxp = {l, r};
                    }
                }
            }
        }
        cout << maxp.first+1 << ' ' << maxp.second+1 << '\n';
        
    }
}
