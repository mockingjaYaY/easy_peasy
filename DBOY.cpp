#include <bits/stdc++.h>
using namespace std;
#define MAXINT 1000000007

int n, h[505], k[505], dp[505][1010];

int solve(int i, int sum, int maxS)
{
    if (sum > maxS)
        return MAXINT;
    if (i == n)
    {
        return 0;
    }
    if (dp[i][sum] != -1)
        return dp[i][sum];

    return dp[i][sum] = min(solve(i, sum + k[i], maxS) + 1, min(solve(i + 1, sum + k[i], maxS) + 1, solve(i + 1, sum, maxS)));
}
int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t, i, j, maxS, ans;

    cin >> t;
    while (t--)
    {
        ans = maxS = 0;
        cin >> n;
        for (i = 0; i < n; i++)
        {
            cin >> h[i];
            maxS = max(maxS, j);
        }
        for (i = 0; i < n; i++)
            cin >> k[i];

        memset(dp, -1, sizeof dp);
        solve(0, 0, maxS * 2);

        for (i = 0; i < n; i++)
        {
            for (j = 0; j < 2 * maxS; j++)
                cout << dp[i][j] << " ";
            cout << endl;
        }
        for (i = 0; i < n; i++)
        {
            ans += dp[n - 1][h[i] * 2];
        }
        cout << ans << endl;
    }
}