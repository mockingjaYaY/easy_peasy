#include <bits/stdc++.h>
using namespace std;
vector<int> g[10005];
pair<int, int> dfs(int node, int parent)
{
    int M1, M2, SUB = 0, depth = 0, sub = 0;
    M1 = M2 = -100000000;
    pair<int, int> p;

    if (g[node].size() == 1 && g[node][0] == parent)
        return make_pair(0, 0);

    for (int i = 0; i < g[node].size(); i++)
    {
        if (g[node][i] != parent)
        {
            p = dfs(g[node][i], node);

            depth = p.first;
            sub = p.second;
            //cout << "dfs " << g[node][i] <<" "<<parent<< " " << depth << " " << sub << endl;
            if (depth >= M1)
            {
                M2 = M1;
                M1 = depth;
            }
            else if (depth > M2)
                M2 = depth;
            if (sub > SUB)
                SUB = sub;
        }
    }

    return make_pair(M1 + 1, max(SUB, M1 + M2 + 2));
}
int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, p, q, i;
    pair<int, int> res;
    cin >> n;
    n--;
    while (n--)
    {
        cin >> p >> q;
        g[p].push_back(q);
        g[q].push_back(p);
    }

    res = dfs(1, 1);
    cout << max(res.first, res.second);
    return 0;
}