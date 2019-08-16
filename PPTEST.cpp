#include <bits/stdc++.h>
using namespace std;
int c[105], p[105], t[105], n, dp[105][105];

int solve(int i, int cost)
{
    if (i == n)
        return 0;

    if (dp[i][cost] != -1)
        return dp[i][cost];

//cout<<"i "<<i<<" time left "<<cost<<endl;
    if (cost >= t[i])
        return dp[i][cost] = max(solve(i + 1, cost - t[i]) + (p[i] * c[i]), solve(i + 1, cost));
    else
        return dp[i][cost] = solve(i + 1, cost);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int tests, w, i;
    cin >> tests;
    while (tests--)
    {
        cin >> n >> w;
        for (i = 0; i < n; i++)
            cin >> c[i] >> p[i] >> t[i];
        memset(dp, -1, sizeof dp);
        cout << solve(0, w) << endl;
    }
    return 0;
}