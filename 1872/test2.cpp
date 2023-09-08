#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        int* arr = new int[n];
        for (int i = 0; i < n; i++) cin >> arr[i];
        string str;
        cin >> str;
        int q;
        cin >> q;
        int x;
        int group_zero = 0, group_one = 0;
        for (int i = 0; i < str.length(); i++) {
            if (str[i] == '0')
                group_zero ^= arr[i];
            else
                group_one ^= arr[i];
        }
        while (q--) {
            cin >> x;
            if (x == 2) {
                char g;
                cin >> g;
                cout << (g == '0' ? group_zero : group_one) << " ";
            } else {
                int l, r;
                cin >> l >> r;
                for (int i = l - 1; i < r; i++) {
                    group_zero ^= arr[i];
                    group_one ^= arr[i];
                }
            }
        }
        cout << endl;
        delete[] arr;
    }
}
