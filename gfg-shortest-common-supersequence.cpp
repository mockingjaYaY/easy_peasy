#include <bits/stdc++.h>

using namespace std;

int dp[102][102];

int getLongestCommonSubSequence(string s1, string s2, int i, int j, int x)
{
    if (i >= s1.length() or j >= s2.length())
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    if (s1[i] == s2[j])
        return dp[i][j] = getLongestCommonSubSequence(s1, s2, i + 1, j + 1, x) + 1;
    else
        return dp[i][j] = max(getLongestCommonSubSequence(s1, s2, i + 1, j, x),
                              getLongestCommonSubSequence(s1, s2, i, j + 1, x));
}
int main()
{
    string s1, s2;
    int t;

    cin >> t;
    while (t--)
    {
        memset(dp, -1, sizeof dp);
        cin >> s1 >> s2;
        int x = getLongestCommonSubSequence(s1, s2, 0, 0, 0);
        int ans = s1.length() + s2.length() - x;
        cout << ans << endl;
    }
    return 0;
}