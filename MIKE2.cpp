#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll arr[100005];
int main()
{
    ll n, x, i, unp = 0, sup = 0;
    cin >> n >> x;
    for (i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    for (i = 0; i < n; i++)
    {
        if (x >= ceil((double)arr[i] / 2.0))
        {-gyp
            x -= ceil((double)arr[i] / 2.0);
        }
        else
        {
            unp = n - i;
            break;
        }
    }
    for (i = 0; i < n; i++)
    {
        if (x >= arr[i] / 2)
        {
            sup++;
            x -= arr[i] / 2;
        }
    }
    cout << unp << " " << sup << endl;
    return 0;
}