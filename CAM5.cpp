#include <bits/stdc++.h>
using namespace std;
int parent[100005], syz[100005];
int get_parent(int a)
{
    int p = a;
    while (parent[p] != p)
    {
        p = parent[parent[p]];
    }
    return p;
}

void join(int a, int b)
{
    int pa = get_parent(a);
    int pb = get_parent(b);
    if (syz[pa] > syz[pb])
    {
        parent[pb] = pa;
        syz[pa] += syz[pb];
    }
    else
    {
        parent[pa] = pb;
        syz[pb] += syz[pa];
    }
}

void init()
{
    int i;
    for (i = 0; i < 100005; i++)
    {
        parent[i] = i;
        syz[i] = 1;
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t, n, e, a, b, ans, i;
    cin >> t;
    while (t--)
    {
        ans = 0;
        init();
        cin >> n;
        cin >> e;
        for (i = 0; i < e; i++)
        {
            cin >> a >> b;

            if (get_parent(a) != get_parent(b))
            {
                join(a, b);
            }
        }

        for (i = 0; i < n; i++)
        {
            if (parent[i] == i)
                ans++;
        }
        cout << ans << endl;
    }
    return 0;
}