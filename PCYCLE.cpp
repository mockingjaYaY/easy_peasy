#include <bits/stdc++.h>
using namespace std;

int main()
{

#ifndef PRACTICE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n, i, arr[1005], pos[1005], x, ans_size = 0;
    vector<int> ans[1005];
    memset(pos, 0, sizeof pos);
    cin >> n;
    for (i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    for (i = 1; i <= n; i++)
    {
        if (pos[i] == 0)
        {
            pos[i] = 1;
            x = i;
            while (arr[x] != i)
            {
                ans[ans_size].push_back(x);
                x = arr[x];
                pos[x] = 1;
            }
            ans[ans_size].push_back(x);
            ans[ans_size].push_back(arr[x]);
            ans_size++;
        }
    }

    cout << ans_size << endl;
    for (i = 0; i < ans_size; i++)
    {
        for (x = 0; x < ans[i].size(); x++)
        {
            cout << ans[i][x] << " ";
        }
        cout << endl;
    }
    return 0;
}