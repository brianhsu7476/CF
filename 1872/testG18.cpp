#include <bits/stdc++.h>

using namespace std;
using LL = long long;

template<typename T>
ostream &operator<<(ostream &os, const vector<T> &vec) {
    for (auto &&x: vec) {
        os << x << " ";
    }
    return os;
}

template<typename T>
istream &operator>>(istream &is, vector<T> &vec) {
    for (auto &&x: vec) {
        is >> x;
    }
    return is;
}

template<typename T>
void print(const T &t) {
    cout << t;
}

template<typename T, typename... Args>
void print(const T &t, const Args &... args) {
    cout << t;
    print(args...);
}

constexpr int N = 200'010;
constexpr LL M = (LL) N * (1e9);

int n, f[N];
LL a[N], s[N];

void solve() {
    cin >> n;
    LL p = 1;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (p < M) {
            if (p > M / a[i]) {
                p = M;
            } else {
                p *= a[i];
            }
        }
    }
    f[n + 1] = n + 1;
    for (int i = n; i; i--) {
        if (a[i] != 1) {
            f[i] = i;
        } else {
            f[i] = f[i + 1];
        }
    }
    if (p >= M) {
        int l = 1, r = n;
        while (a[l] == 1) {
            l++;
        }
        while (a[r] == 1) {
            r--;
        }
        assert(l <= r);
        cout << l << ' ' << r << '\n';
        return;
    }
    for (int i = 1; i <= n; i++) {
        s[i] = s[i - 1] + a[i];
    }
    LL ans = 0;
    int L = 1, R = 1;
    for (int i = 1; i <= n; i++) {
        if (a[i] != 1) {
            int j = i;
            p = 1;
            while (j <= n) {
                p *= a[j];
                LL t = s[i - 1] + s[n] - s[j] + p;
                if (t > ans) {
                    ans = t;
                    L = i;
                    R = j;
                }
                j = f[j + 1];
            }
        }
    }
    cout << L << ' ' << R << '\n';
}

int main() {
//    freopen("in", "r", stdin);
//    freopen("out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _;
    cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}

