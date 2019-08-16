#include <bits/stdc++.h>
using namespace std;

int a[100005], b[100005];
vector<pair<int, int>> d;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, x, y, i, ans = 0;
    cin >> n >> x >> y;
    for (i = 0; i < n; i++)
        cin >> a[i];
    for (i = 0; i < n; i++)
        cin >> b[i];
    for (i = 0; i < n; i++)
        d.push_back(make_pair(abs(a[i] - b[i]), i));
    sort(d.begin(), d.end(), greater<pair<int, int>>());

    for (i = 0; i < n; i++)
    {
        if (a[d[i].second] > b[d[i].second])
        {
            if (x)
            {
                ans += a[d[i].second];
                x--;
            }
            else
            {
                ans += b[d[i].second];
                y--;
            }
        }
        else
        {
            if (y)
            {
                ans += b[d[i].second];
                y--;
            }
            else
            {
                ans += a[d[i].second];
                x--;
            }
        }
    }

    cout << ans;
    return 0;
}