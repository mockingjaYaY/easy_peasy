#include <bits/stdc++.h>
using namespace std;

#define ll long long
ll arr[100005];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll n, k, i, l, r, mid, ans = 0, idx;

    cin >> n >> k;
    for (i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr + n);
    for (i = n - 1; i >= 0; i--)
    {
        l = 0;
        r = i;
        idx = -1;
        while (l < r)
        {
            mid = (l + r) / 2;

            if (arr[mid] + arr[i] >= k)
            {
                r = mid;
            }
            else
            {
                l = mid + 1;
                idx = max(idx, mid);
            }
        }
        if (idx != -1)
        {
            //cout << "for " << arr[i] << " adding freq " << idx << endl;
            ans += idx + 1;
        }
        
    }

    cout << ans;
    return 0;
}