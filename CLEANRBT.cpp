#include <bits/stdc++.h>
using namespace std;

int w, h, r, dp[25][25][1050], dirty[25][25];
char tiles[25][25];

int solve(int i, int j, int rbt)
{
    int ans = 1000000007;
    if (i >= h || j >= w)
        return 1000000007;
    if (rbt == ((1 << r) - 1))
        return 0;
    if (dp[i][j][rbt] != -1)
        return dp[i][j][rbt];

    if (i + 1 < h && tiles[i + 1][j] != 'x')
    {
        if(tiles[i+1][j] == '*')
        ans = min(ans, solve(i+1, j, rbt))
    }
}