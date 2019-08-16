#include <bits/stdc++.h>
using namespace std;
#define max_num 100005
#define ll long long 
ll arr[max_num], n;
ll max_left_soft[max_num];
ll max_left_hard[max_num];
ll min_left_soft[max_num];
ll min_left_hard[max_num];
ll max_right_hard[max_num];
ll min_right_hard[max_num];

void calculateSums()
{
    ll i;
    max_left_soft[0] = max_left_hard[0] = min_left_soft[0] = min_left_hard[0] = arr[0];
    for (i = 1; i < n; i++)
    {
        max_left_hard[i] = max(max_left_hard[i - 1] + arr[i], arr[i]);
        max_left_soft[i] = max(max_left_soft[i - 1], max_left_hard[i]);

        min_left_hard[i] = min(min_left_hard[i - 1] + arr[i], arr[i]);
        min_left_soft[i] = min(min_left_soft[i - 1], min_left_hard[i]);
    }

    max_right_hard[n - 1] = min_right_hard[n - 1] = arr[n - 1];
    for (i = n - 2; i >= 0; i--)
    {
        max_right_hard[i] = max(max_right_hard[i + 1] + arr[i], arr[i]);
        min_right_hard[i] = min(min_right_hard[i + 1] + arr[i], arr[i]);
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll t, i, ans;
    cin >> t;
    while (t--)
    {
        ans = 0;
        cin >> n;
        for (i = 0; i < n; i++)
            cin >> arr[i];

        calculateSums();

        for (i = n - 1; i > 0; i--)
        {
            ans = max(ans, abs(max_right_hard[i] - min_left_soft[i - 1]));
            ans = max(ans, abs(min_right_hard[i] - max_left_soft[i - 1]));
        }

        cout << ans << endl;
    }
    return 0;
}