#include <bits/stdc++.h>
using namespace std;

int percentage(int n, int p)
{
    return (p * 100) / n;
}

int main()
{

#ifndef PRACTICE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t, n, i, p, x, prev;
    string s;
    cin >> t;
    while (t--)
    {
        p = 0;
        x = 0;
        cin >> n;
        cin >> s;
        for (i = 0; i < n; i++)
        {
            if (s[i] == 'P')
                p++;
        }
        prev = p;

        if (percentage(n, p) >= 75)
        {
            cout << 0 << endl;
        }
        else
        {
            for (i = 0; i < n; i++)
            {
                if (i - 2 >= 0 && i - 1 >= 0 && i + 1 < n && i + 2 < n && s[i] == 'A')
                {
                    if ((s[i - 1] == 'P' || s[i - 2] == 'P') && (s[i + 1] == 'P' || s[i + 2] == 'P'))
                    {
                        p++;
                        if (percentage(n, p) >= 75)
                            break;
                    }
                }
            }

            if (percentage(n, p) >= 75)
                cout << p - prev << endl;
            else
                cout << -1 << endl;
        }
    }
    return 0;
}