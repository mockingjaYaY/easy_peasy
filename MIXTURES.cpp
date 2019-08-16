#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXINT 1000000000
ll arr[105], sum[105];
ll dp[105][105];
ll get_sum(ll l, ll r)
{
    return (sum[r + 1] - sum[l] + 100) % 100;
}
ll solve(ll l, ll r)
{
    ll ans = MAXINT;

    if (dp[l][r] != -1)
        return dp[l][r];

    if (l == r)
        return 0;
    if (l + 1 == r)
        return arr[l] * arr[r];

    for (int i = l + 1; i < r; i++)
    {
        ans = min(ans, solve(l, i) + solve(i + 1, r) + get_sum(l, i) * get_sum(i + 1, r));
    }

    return dp[l][r] = ans;
}
int main()
{
    ll n, i;
    while (!cin.eof())
    {
        cin >> n;
        for (i = 0; i < n; i++)
        {
            cin >> arr[i];
            sum[i + 1] = (sum[i] + arr[i]) % 100;
        }
        memset(dp, -1, sizeof dp);
        cout << solve(0, n - 1) << endl;
    }
}