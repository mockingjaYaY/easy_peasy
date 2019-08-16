#include <bits/stdc++.h>
using namespace std;

int in[100005], out[100005];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t, n, m, i, a, b;
    cin >> t;
    while (t--)
    {
        memset(in, 0, sizeof in);
        memset(out, 0, sizeof out);
        cin >> n >> m;
        for (i = 0; i < m; i++)
        {
            cin >> a >> b;
            //cout << "marking " << a << " " << b << endl;
            out[a]++;
            in[b]++;
        }
        a = -1;
        for (i = 1; i <= n; i++)
        {
            //cout << in[i] << endl;
            if (out[i] == 0 && in[i] == n - 1)
            {
                a = i;
                break;
            }
        }
        if (a == -1)
            cout << "dead\n";
        else
            cout << "alive " << a << endl;
    }
    return 0;
}