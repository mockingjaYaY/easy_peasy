#include <bits/stdc++.h>
using namespace std;
int m, n, mat[205][205], dp[205][205][2];

// 0 : left, 1 : right
// 0 : empty, 1 : tree, 2 : blocked cell

int solve(int i, int j, int dir)
{
    int ans = -1;
    if (i == m || j == n || i < 0 || j < 0)
        return 0;

    if (mat[i][j] == 2)
        return 0;

    if (dp[i][j][dir] != -1)
        return dp[i][j][dir];

    if (dir == 0)
    {
        ans = max(ans, solve(i, j - 1, 0) + mat[i][j]);
        ans = max(ans, solve(i + 1, j, 1) + mat[i][j]);
    }
    else
    {
        ans = max(ans, solve(i, j + 1, 1) + mat[i][j]);
        ans = max(ans, solve(i + 1, j, 0) + mat[i][j]);
    }

    return dp[i][j][dir] = ans;
}
int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t, i, j, ans;
    string s;
    cin >> t;
    while (t--)
    {
        cin >> m >> n;
        for (i = 0; i < m; i++)
        {
            cin >> s;
            for (j = 0; j < n; j++)
            {
                if (s[j] == '0')
                    mat[i][j] = 0;
                if (s[j] == 'T')
                    mat[i][j] = 1;
                if (s[j] == '#')
                    mat[i][j] = 2;
            }
        }

        memset(dp, -1, sizeof dp);
        ans = solve(0, 0, 1);
        //cout << "dp over\n";
        cout << ans << endl;
    }
}
