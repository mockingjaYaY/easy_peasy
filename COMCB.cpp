#include <bits/stdc++.h>
using namespace std;
int X, Y, vis[50][50];
string chess(int p, int q, string s, int cells)
{
    //cout << s << p<< q<< endl;
    int m, n, i, j;
    string max_s = "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";
    int x[8] = {2, -2, 2, -2, 1, -1, 1, -1};
    int y[8] = {-1, 1, 1, -1, -2, -2, 2, 2};

    if (cells == X * Y)
    {
        //cout<<"YES"<<endl;
        return s;
    }

    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 8; j++)
        {
            m = p + x[i];
            n = q + y[j];

            
            if (m >= 0 && m < X && n >= 0 && n < Y && vis[m][n] == 0)
            {
                cout<<"vis "<<vis[m][n]<<endl;
                vis[m][n] = 1;
                s.push_back('A' + n);
                s.push_back('0' + m + 1);

                cout << "hello " << i << j << s << endl;
                max_s = min(chess(m, n, s, cells + 1), max_s);
                s.pop_back();
                s.pop_back();
                vis[m][n] = 0;
            }
        }
    }

    return max_s;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t, i, j;

    cin >> t;
    while (t--)
    {
        string s = "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";
        cin >> X >> Y;
        for (i = 0; i < X; i++)
        {
            string str = "";

            for (j = 0; j < Y; j++)
            {
                memset(vis, 0, sizeof vis);
                str.push_back('A' + j);
                str.push_back(i + 1 + '0');

                vis[i][j] = 1;
                s = min(chess(i, j, str, 1), s);
                str.pop_back();
                str.pop_back();
                vis[i][j] = 0;
            }
        }

        cout << s << endl;
    }

    return 0;
}