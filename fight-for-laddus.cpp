#include <bits/stdc++.h>
using namespace std;
int arr[100005], ans[100005];
stack<pair<int, int>> st;
map<int, int> mp;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n, i;
    cin >> t;
    while (t--)
    {
        while (!st.empty())
            st.pop();
        mp.clear();
        cin >> n;
        for (i = 0; i < n; i++)
        {
            cin >> arr[i];
            mp[arr[i]]++;
        }
        for (i = 0; i < n; i++)
        {

            while (!st.empty() && mp[arr[i]] > mp[st.top().first])
            {
                ans[st.top().second] = arr[i];
                st.pop();
            }

            st.push(make_pair(arr[i], i));
        }
        while (!st.empty())
        {
            ans[st.top().second] = -1;
            st.pop();
        }
        for (i = 0; i < n; i++)
            cout << ans[i] << " ";
        cout << endl;
    }
    return 0;
}