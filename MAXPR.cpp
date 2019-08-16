#include <bits/stdc++.h>
using namespace std;

#define INTMAX 10000007

int arr[200005], n;
int dp[200005][105];

int power(int a, int b)
{
    int ans = 1;
    while (b)
    {
        if (b % 2 == 1)
        {
            ans = (ans * a) % INTMAX;
        }
        a = (a * a) % INTMAX;
        b = b / 2;
    }
    return ans;
}
int find_ap(int i, int diff, int prev, int len)
{
    if (i == n)
    {
       return 1;
    }
    if (dp[i][prev] != -1)
        return dp[i][prev];

    if (arr[i] - arr[prev] == diff)
        return dp[i][prev] = (find_ap(i + 1, diff, i, len + 1) + find_ap(i + 1, diff, prev, len)) % INTMAX;
    else
        return dp[i][prev] = find_ap(i + 1, diff, prev, len);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t, i, ans, temp, j;
    cin >> t;
    while (t--)
    {
        ans = 0;
        cin >> n;
        for (i = 0; i < n; i++)
            cin >> arr[i];

        for (i = -100; i <= 100; i++)
        {
            memset(dp, -1, sizeof dp);
            for (j = 0; j < n; j++)
            {
                temp = find_ap(j + 1, i, j, 1);
                // if (temp > 0)
                //     cout << "APs with diff " << i << " are " << temp << endl;
                ans = (ans + temp) % INTMAX;
            }
        }

        temp = power(2, n);
        cout << "no of aps " << ans << endl;
        temp = (temp - 1) % INTMAX + (temp >= 1 ? 0 : INTMAX);

        ans = (temp - ans) % INTMAX + (temp >= ans ? 0 : INTMAX);

        cout << ans << endl;
    }
    return 0;
}