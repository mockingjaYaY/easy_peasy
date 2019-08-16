#include <bits/stdc++.h>
using namespace std;

int arr[70000];
int main()
{
    int n, i, mid, l, r, temp, ans = 0, k;
    cin >> n >> k;
    for (i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);

    for (i = 0; i < n; i++)
    {
        l = i + 1;
        r = n - 1;
        temp = n + 1;
        while (l < r)
        {
            mid = (l + r) / 2;
            if (arr[mid] - arr[i] < k)
            {
                l = mid + 1;
            }
            else
            {
                r = mid;
                temp = min(temp, mid);
            }
        }
        if (temp != n + 1)
        {
            ans += (n - temp);
        }
    }
    cout << ans;
}