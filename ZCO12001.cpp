#include <bits/stdc++.h>
using namespace std;
int arr[100005];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int B, n, i, p, q, x, y, X, Y;
    B = 0;
    x = 0;
    X = 0;
    p = 0;
    cin >> n;
    for (i = 0; i < n; i++)
        cin >> arr[i];

    for (i = 0; i < n; i++)
    {
        if (arr[i] == 1)
        {
            B++;
            //cout<<B<<" "<<p<<endl;
            if (B > p)
            {
                p = B;
                q = i + 1;
            }
            x += 2;
        }
        else
        {
            B--;
            if (B == 0)
            {
                if (x > X)
                {
                    X = x;
                    Y = i - X + 2;
                }
                x = 0;
                //cout << "x zero at " << i + 1 << endl;
            }
        }
    }

    cout << p << " " << q << " " << X << " " << Y;
    return 0;
}