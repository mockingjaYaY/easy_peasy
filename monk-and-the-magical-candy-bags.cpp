#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, n, k, i, x, ans;
    priority_queue<int> pq;
    cin >> t;
    while (t--)
    {
        while (!pq.empty())
            pq.pop();
        ans = 0;
        cin >> n >> k;
        for (i = 0; i < n; i++)
        {
            cin >> x;
            pq.push(x);
        }
        while (k--)
        {
            x = pq.top();
            ans += x;
            pq.push(x / 2);
        }
        cout << ans << endl;
    }
    return 0;
}