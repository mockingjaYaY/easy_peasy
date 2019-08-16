#include <bits/stdc++.h>
using namespace std;

long long int arr[10005], cost[10005];
int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long int t, n, i, l, r, mid, ans, temp, n_sum, p_sum;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (i = 0; i < n; i++)
            cin >> arr[i];
        for (i = 0; i < n; i++)
            cin >> cost[i];

        ans = LLONG_MAX;

        l = 0;
        r = LLONG_MAX;
        while (l < r)
        {
            mid = (l + r) / 2;
            temp = n_sum = p_sum = 0;
            for (i = 0; i < n; i++)
            {
                temp += abs(cost[i] * (arr[i] - mid));
                if (arr[i] > mid)
                    n_sum += abs(cost[i] * (arr[i] - mid));
                else
                    p_sum += abs(cost[i] * (arr[i] - mid));
            }
            ans = min(ans, temp);
            if (n_sum > p_sum)
            {
                l = mid + 1;
            }
            else
            {
                r = mid;
            }
        }
        cout << ans << endl;
    }
    return 0;
}