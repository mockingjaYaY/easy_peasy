#include <bits/stdc++.h>
using namespace std;

long arr[100];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    long test_cases, pratas, cooks, x, i, l, r, mid, temp_pratas, ans = 0;
    cin >> test_cases;
    while (test_cases--)
    {
        cin >> pratas >> cooks;
        for (i = 0; i < cooks; i++)
            cin >> arr[i];

        l = 1;
        r = 10000007;
        ans = INT_MAX;
        while (l < r)
        {
            mid = (l + r) / 2;
            temp_pratas = 0;
            for (i = 0; i < cooks; i++)
            {
                //cout << "paratas made " << (sqrt((1 + (8 * mid) / arr[i]) - 1) / 2) << endl;
                temp_pratas += (sqrt(1 + (8 * mid) / arr[i]) - 1) / 2;
            }
            //cout << "temp_pratas " << temp_pratas << endl;

            if (temp_pratas >= pratas)
            {
                ans = min(ans, mid);
                r = mid;
            }
            else
            {
                l = mid + 1;
            }
        }

        cout << ans << endl;
    }
    return 0;
}