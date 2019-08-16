#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll> x, y;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll t, n, a, b, i;
    cin >> t;
    while (t--)
    {
        cin >> n;
        x.clear();
        y.clear();
        for (i = 0; i < n; i++)
        {
            cin >> a >> b;
            x.push_back(a);
            y.push_back(b);
        }
        sort(x.begin(), x.end());
        sort(y.begin(), y.end());

        a = x[n / 2] - x[(n - 1) / 2] + 1;
        b = y[n / 2] - y[(n - 1) / 2] + 1;
        cout << a * b << endl;
    }
    return 0;
}