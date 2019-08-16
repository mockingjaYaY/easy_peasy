#include <bits/stdc++.h>
using namespace std;
string a, b;
int dp[2005][2005];
int solve(int i, int j)
{
    int ans = INT_MAX;
    if (i == a.size())
        return b.size() - j;
    if (j == b.size())
        return a.size() - i;

    if (dp[i][j] != -1)
        return dp[i][j];

    if (a[i] == b[j])
        ans = solve(i + 1, j + 1);
    else
        ans = min(ans, min(solve(i + 1, j + 1) + 1, min(solve(i + 1, j) + 1, solve(i, j + 1) + 1)));

    return dp[i][j] = ans;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;

    cin >> t;
    while (t--)
    {
        cin >> a >> b;
        memset(dp, -1, sizeof dp);
        cout << solve(0, 0) << endl;
    }

    return 0;
}