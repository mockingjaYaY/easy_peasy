#include <bits/stdc++.h>
using namespace std;
int n, dp[5005][5005];
string a, b;

int solve(int i, int j)
{
    if (i == n || j == n)
        return abs(i - j);
    if (dp[i][j] != -1)
        return dp[i][j];

    if (a[i] == b[j])
        dp[i][j] = solve(i + 1, j + 1);
    else
        dp[i][j] = min(solve(i + 1, j), solve(i, j + 1)) + 1;

    return dp[i][j];
}

int bottom_up()
{
    int i, j;

    for(i=0;i<=n;i++)
    {
        dp[i][0] = i;
        dp[0][i] = i;
    }

    for(i=1 ;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(a[i-1]==b[j-1]) dp[i][j]=dp[i-1][j-1];
            else dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + 1;
        }
    }
    return dp[n][n];
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    cin >> a;
    b = a;
    reverse(b.begin(), b.end());
    memset(dp, -1, sizeof dp);
    cout << bottom_up()/2;
    return 0;
}