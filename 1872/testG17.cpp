#include <iostream>
#include <vector>
using namespace std;
typedef int long lnog;
signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int l, r;
        l = 0, r = 0;
        int t = 0;

        vector<int> pre1(n);
        vector<int> pre2(n);
        vector<int> arr(n);
        vector<int> count;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            if (arr[i] > 1)
                count.push_back(i);

            if (i == 0)
            {
                pre1[i] = arr[i];
                pre2[i] = arr[i];
                continue;
            }
            pre1[i] = pre1[i - 1] + arr[i];
            pre2[i] = pre2[i - 1] * arr[i];
        }
        if (count.size() > 20 or count.size() == n)
            cout << count.front()+1 << " " << count.back()+1 << "\n";
        else
        {
            for(auto i : count)
                for(auto j : count)
                {
                    if(i >= j)
                        continue;
                    int sum = pre2[j] / pre2[i] * arr[i] - (pre1[j] - pre1[i] + arr[i]);
                    if(sum > t)
                    {
                        l = i;
                        r = j;
                        t = sum;
                    }
                }
            cout << l + 1<< " " << r+ 1 << "\n";
        }
    }
}
