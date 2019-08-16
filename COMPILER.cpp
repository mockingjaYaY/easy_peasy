#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, i, ans, x, prev;
    string s;
    cin >> t;
    while (t--)
    {
        cin >> s;
        ans = 0;
        x = 0;
        prev = 1000000007;
        for (i = 0; i < s.size(); i++)
        {
            if (s[i] == '<')
            {
                x++;
                prev = min(prev, i);
            }
            else
            {
                if (x <= 0)
                    {
                        x = 0;
                        prev = 1000000007;
                    }
                else
                    x--;
            }
            if (x == 0)
            {
                ans = max(ans, i - prev + 1);
                prev = 1000000007;
            }
        }

        cout << ans << endl;
    }
    return 0;
}