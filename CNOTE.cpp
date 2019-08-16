#include <bits/stdc++.h>
using namespace std;

int main()
{

    int x, y, k, n, p, c, t, flag;
    cin >> t;
    while (t--)
    {
        flag = 0;
        cin >> x >> y >> k >> n;
        y = x - y;
        while (n--)
        {
            cin >> p >> c;
            if (c <= k && p >= y)
                flag++;
        }

        if (flag)
            cout << "LuckyChef\n";
        else
            cout << "UnluckyChef\n";
    }
    return 0;
}