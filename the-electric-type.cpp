#include <bits/stdc++.h>
using namespace std;

int arr[200005];
map<int, int> mp, first;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, i, t, unique, ans;
    unique = ans = 0;
    mp.clear();
    first.clear();
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (first.find(arr[i]) == first.end())
        {
            //cout << "hey didnt find end for " << arr[i] << endl;
            first[arr[i]] = i;
        }
    }

    for (i = n - 1; i >= 0; i--)
    {
        //cout << first[arr[i]] << endl;
        if (first[arr[i]] == i)
            ans = ans + unique;
        if (mp[arr[i]] == 0)
            unique++;
        mp[arr[i]]++;
    }
    cout << ans << endl;

    return 0;
}