#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    long long int t, n, x, i, ans;
    vector<long long int> v;
    string s;

    cin >> t;
    while (t--)
    {
        ans = 0;
        cin >> n;
        while (!v.empty())
            v.pop_back();
        for (i = 0; i < n; i++)
        {
            cin >> s >> x;
            v.push_back(x);
        }
        sort(v.begin(), v.end());
        for (i = 0; i < n; i++)
        {
            ans += abs(v[i] - i - 1);
        }

        cout << ans << endl;
    }
    return 0;
}