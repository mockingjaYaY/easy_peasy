#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int X, in[100005], out[100005], vis[100005];
vector<int> g[100005];
void dfs(int x, int p)
{
    int i;
    X++;
    in[x] = X;
    vis[x] = 1;
    //cout << x << p << endl;

    for (i = 0; i < g[x].size(); i++)
    {
        //cout << "child" << g[x][i] << endl;
        if (vis[g[x][i]] == 0)
        {
            dfs(g[x][i], x);
        }
    }

    X++;
    out[x] = X;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n, q, adm, i, a, b;
    X = 0;
    cin >> n >> q;
    cin >> adm;

    for (i = 0; i < n - 1; i++)
    {
        cin >> a >> b;
        g[a].push_back(b);
    }

    dfs(adm, adm);

    while (q--)
    {
        cin >> a >> b;
        if (in[a] >= in[b] && out[a] <= out[b])
            cout << 1 << "\n";
        else if (in[b] >= in[a] && out[b] <= out[a])
            cout << -1 << "\n";
        else
            cout << 0 << "\n";
    }
    return 0;
}