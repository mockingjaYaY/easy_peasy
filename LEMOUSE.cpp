#include <bits/stdc++.h>
using namespace std;
#define pp pair<int, pair<int, int>>
#define INTMAX 1000000007
int dist[105][105], mat[105][105], n, m;

int bfs()
{
    priority_queue<pp, vector<pp>, greater<pp>> pq;
    int x, y, ans = INTMAX;

    pq.push(make_pair(mat[0][0], make_pair(0, 0)));
    dist[0][0] = mat[0][0];

    while (!pq.empty())
    {
        pp p = pq.top();
        pq.pop();

        x = p.second.first;
        y = p.second.second;

        if (x + 1 < n && dist[x][y] + mat[x + 1][y] < dist[x + 1][y])
        {
            dist[x + 1][y] = dist[x][y] + mat[x + 1][y];
            pq.push(make_pair(dist[x + 1][y], make_pair(x + 1, y)));
        }
        if (y + 1 < m && dist[x][y] + mat[x][y + 1] < dist[x][y + 1])
        {
            dist[x][y + 1] = dist[x][y] + mat[x][y + 1];
            pq.push(make_pair(dist[x][y + 1], make_pair(x, y + 1)));
        }

        ans = min(ans, dist[n - 1][m - 1]);
    }

    return ans;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t, i, j;
    string s;

    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        memset(mat, 0, sizeof mat);
        for (i = 0; i < n; i++)
        {
            cin >> s;
            for (j = 0; j < m; j++)
            {
                if (s[j] == '1')
                {
                    if (i - 1 >= 0)
                    {
                        mat[i - 1][j] += 1;
                    }
                    if (i + 1 < n)
                    {
                        mat[i + 1][j] += 1;
                    }
                    if (j - 1 >= 0)
                    {
                        mat[i][j - 1] += 1;
                    }
                    if (j + 1 < m)
                    {

                        mat[i][j + 1] += 1;
                    }
                    mat[i][j] += 1;
                }

                dist[i][j] = INTMAX;
            }
        }
        bfs();
        cout << dist[n - 1][m - 1] << endl;
    }
    return 0;
}