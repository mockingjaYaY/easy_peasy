#include <bits/stdc++.h>
using namespace std;
int in[30], out[30], p[30];
vector<string> v;

int get_parent(int i)
{
    while (p[i] != i)
    {
        i = p[p[i]];
    }
    return i;
}

void join(int i, int j)
{
    int pi = get_parent(i);
    int pj = get_parent(j);

    p[pj] = pi;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t, n, i, extra, unique_p;
    string s;
    cin >> t;
    while (t--)
    {
        memset(in, 0, sizeof in);
        memset(out, 0, sizeof out);
        v.clear();

        extra = unique_p = 0;
        cin >> n;
        for (i = 0; i < n; i++)
        {
            cin >> s;
            v.push_back(s);
            in[s[0] - 'a']++;
            out[s[s.size() - 1] - 'a']++;
        }
        for (i = 0; i < 30; i++)
        {
            if (in[i] != out[i])
                extra++;
        }
        for (i = 0; i < 30; i++)
        {
            p[i] = i;
        }
        for (i = 0; i < n; i++)
        {
            s = v[i];
            if (get_parent(s[0] - 'a') != get_parent(s[s.size() - 1] - 'a'))
                join(s[0] - 'a', s[s.size() - 1] - 'a');
        }
        for (i = 0; i < 30; i++)
        {
            //cout << p[i] << " ";
            if (p[i] == i && (in[i] > 0 || out[i] > 0))
                unique_p++;
        }
        //cout << "reached " << extra << " " << unique_p << "\n";
        if ((extra == 0 || (extra == 2 && n > 2)) && unique_p == 1)
            cout << "Ordering is possible.\n";
        else
            cout << "The door cannot be opened.\n";
    }
    return 0;
}