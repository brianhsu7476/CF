#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pii pair<int, int>
#define f first
#define s second

const int MOD = 1000000007;

const ll INF = 2e14;


void solve() {
    int n;
    ll prod = 1;
    scanf("%d", &n);
    vector<ll> a(n);
    for (ll& i : a) {
        scanf("%lld", &i);
        if (prod <= INF) prod *= i;
    }
    if (prod > INF) {
        int l = 0, r = n - 1;
        while (a[l] == 1) l++;
        while (a[r] == 1) r--;
        printf("%d %d\n", l+1, r+1);
        return;
    }

    ll best = 0, ansL = 1, ansR = 1;
    for (int l=0; l<n; l++) {
        if (a[l] == 1) continue;
        ll prod = 1, total = 0;
        for (int r=l; r<n; r++) {
            prod *= a[r];
            total += a[r];
            if (prod - total > best) {
                best = prod - total;
                ansL = l + 1;
                ansR = r + 1;
            }
        }
    }
    printf("%d %d\n", ansL, ansR);
}

int main() {
    int tests = 1;
    scanf("%d", &tests);
    while (tests--) solve();
}
