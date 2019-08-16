#include <bits/stdc++.h>
using namespace std;

int arr[10005];
vector<pair<int, int>> xor_grp;
int main()
{
#ifndef PRACTICE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t, n, k, x, i, sum;
    cin >> t;
    while (t--)
    {
        xor_grp.clear();
        sum = 0;
        cin >> n;
        for (i = 0; i < n; i++)
        {
            cout << "taking another set of " << n << endl;
            cin >> arr[i];
        }
        cin >> k >> x;
        for (i = 0; i < n; i++)
        {
                xor_grp.push_back(make_pair(arr[i] ^ x, i));
        }

        if (xor_grp.size() / k > 0)
        {
            cout << "reached xor grp\n";
            sort(xor_grp.begin(), xor_grp.end());
            reverse(xor_grp.begin(), xor_grp.end());
            for (i = 0; i < (xor_grp.size() / k) * k; i++)
            {
                cout << "adding " << xor_grp[i].first << endl;
                sum += xor_grp[i].first;
                arr[xor_grp[i].second] = 0;
            }
            for(i=(xor_grp.size() / k) * k; i<xor_grp.size();i++)
            {
                
            }
        }
        for (i = 0; i < n; i++)
        {
            sum += arr[i];
        }
        cout << sum << endl;
    }
    return 0;
}