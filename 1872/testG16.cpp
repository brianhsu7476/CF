#include <bits/stdc++.h>
using namespace std;

#define MAXN 200005

long long a[MAXN];
long long pre[MAXN];

inline void solve(int T) {
    
    int N; cin >> N;
    vector<int > pos;
    for (int i=1;i<=N;++i) {
        cin >> a[i];
        if (a[i] > 1) pos.emplace_back(i);
        pre[i] = pre[i-1] + a[i];
    }

    long long maxx = pre[N];
    int ansl = 1, ansr = 1;

    auto check = [&]() {
        long long mul = 1;
        for (int i=1;i<=N;++i) {
            mul *= a[i];
            if (mul > 1e10) return true;
        }
        return false;
    };

    if (check()) {
        cout << (*pos.begin()) << " " << (*pos.rbegin()) << "\n";
        return;
    }

    for (int i=0;i<pos.size();++i) {
        long long mul = 1; int k = pos[i]-1;
        for (int j=i;j<pos.size();++j) {
            while (k < pos[j]) mul *= a[++k];
            
            // cout << pos[i] << " " << pos[j] << " "<< mul << "\n";
            // cout << maxx << "\n";

            if (pre[pos[i]-1]+pre[N]-pre[pos[j]]+mul > maxx) {
                maxx = pre[pos[i]-1]+pre[N]-pre[pos[j]]+mul;
                ansl = pos[i]; ansr = pos[j];

            }
        }
    }

    // cout << maxx << '\n';
    cout << ansl << " " << ansr << "\n";
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int T = 0; cin >> T;
    for (int i=1;i<=T;++i) solve(i);

    return 0;
}
