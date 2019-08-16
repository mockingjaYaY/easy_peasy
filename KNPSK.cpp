#include <bits/stdc++.h>
using namespace std;

#define NEG_MAX -10000007
vector<int> p1, p2;

int dp[200005];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, i, w, c, total = 0, a, b;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> w >> c;
        if (w == 1)
            p1.push(c);
        else
            p2.push(c);

        total += w;
    }

    sort(p1.begin(), p1.end());
    reverse(p1.begin(), p1.end());

    sort(p2.begin(), p2.end());
    reverse(p2.begin(), p2.end());

    p1.push_back(NEG_MAX);
    p2.push_back(NEG_MAX);

    a = b = 0;
    for (i = 1; i <= total; i++)
    {
        if(i-2>=0)
        {
            if(dp[i]+p1[i] > )
        }
    }

    return 0;
}