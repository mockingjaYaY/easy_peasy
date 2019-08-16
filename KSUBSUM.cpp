#include <bits/stdc++.h>
using namespace std;
int n, k1, k2, k3, arr[10005], dp[10005][10005];
priority_queue<int, vector<int>, greater<int>> pq;
int solve(int i, int max_k, int sum, int freq)
{
    //cout << i << " " << max_k << " " << sum << " " << freq << endl;
    if (pq.size() == max_k && pq.top() < sum && freq > 0)
    {
        //cout << "popping " << pq.top() << endl;
        pq.pop();
        pq.push(sum);
    }
    else if (pq.size() < max_k && freq > 0)
    {
        pq.push(sum);
        //cout << "pushing " << sum << endl;
    }
    if (i == n)
        return sum;

    if (dp[i][freq] != -1)
        return dp[i][freq];

    return dp[i][freq] = max(solve(i + 1, max_k, 0, 0), solve(i + 1, max_k, sum + arr[i], freq + 1));
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t, i, max_k;
    cin >> t;
    while (t--)
    {
        memset(dp, -1, sizeof dp);

        cin >> n >> k1 >> k2 >> k3;
        max_k = max(k1, max(k2, k3));

        for (i = 0; i < n; i++)
            cin >> arr[i];

        solve(0, max_k, 0, 0);

        //cout << "dp over\n";
        while (!pq.empty())
        {
            if (max_k == k3)
                k3 = pq.top();
            if (max_k == k2)
                k2 = pq.top();
            if (max_k == k1)
                k1 = pq.top();

            max_k--;
            //cout << pq.top() << endl;
            pq.pop();
        }
        cout << k1 << " " << k2 << " " << k3 << endl;
    }
    return 0;
}