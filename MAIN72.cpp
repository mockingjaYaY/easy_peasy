#include <bits/stdc++.h>
using namespace std;
int n, dp[105][100005], arr[105];
map<int, bool> mp;
bool solve(int i, int sum)
{
    if (i == n)
    {
        mp[sum] = true;
        return true;
    }
    if (dp[i][sum] != -1)
        return dp[i][sum];

    return dp[i][sum] = solve(i + 1, sum + arr[i]) | solve(i + 1, sum);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t, sum, i, ans;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (i = 0; i < n; i++)
            cin >> arr[i];
        memset(dp, -1, sizeof dp);
        mp.clear();
        ans = 0;
        solve(0, 0);
        for (auto itr = mp.begin(); itr != mp.end(); itr++)
        {
            ans += itr->first;
        }
        cout << ans << endl;
    }

    return 0;
}
