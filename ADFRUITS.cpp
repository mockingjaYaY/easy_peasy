#include <bits/stdc++.h>
using namespace std;

string a, b, MAX_S;
string dp[105][105];

string solve(int i, int j, string s)
{
    if (i == -1 || j == -1)
    {
        while (j >-1)
            s = b[j--] + s;

        while (i >-1)
            s = a[i--] + s;

        return s;
    }

    if (dp[i][j] != MAX_S)
        return dp[i][j];

    string sa, sb;
    sa = a[i] + s;
    sb = b[j] + s;

    if (a[i] == b[j])
        dp[i][j] = solve(i - 1, j - 1, sa);
    else
        dp[i][j] = min(solve(i - 1, j, sa), solve(i, j - 1, sb));
    return dp[i][j];
}
int main()
{
    for (int i = 0; i < 300; i++)
        MAX_S.push_back('z');

    while (!cin.eof())
    {
        cin >> a >> b;
        for (int i = 0; i < 105; i++)
        {
            for (int j = 0; j < 105; j++)
                dp[i][j] = MAX_S;
        }
        cout << solve(a.size()-1, b.size()-1, "") << "\n";
    }
    return 0;
}