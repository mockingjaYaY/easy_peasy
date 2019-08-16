#include <bits/stdc++.h>
using namespace std;

int row_cnt[1005], col_cnt[1005];
vector<int> row[1005], col[1005];
priority_queue<pair<int, pair<int, int>>> pq;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t, n, x, y, i, j, ans;
    cin >> t;
    while (t--)
    {
        while (!pq.empty())
            pq.pop();
        memset(row_cnt, 0, sizeof row_cnt);
        memset(col_cnt, 0, sizeof col_cnt);
        for (i = 0; i < 1005; i++)
        {
            row[i].clear();
            col[i].clear();
        }
        ans = 0;
        cin >> n;
        for (i = 0; i < n; i++)
        {
            cin >> x >> y;
            row[x].push_back(y);
            col[y].push_back(x);
            row_cnt[a]++;
            col_cnt[b]++;
        }
        for (i = 0; i < 1005; i++)
        {
            if (row_cnt[i])
                pq.push(make_pair(row_cnt[i], make_pair(i, 0)));
            if (col_cnt[i])
                pq.push(make_pair(col_cnt[i], make_pair(i, 1)));
        }
        while (!pq.empty() && n)
        {
            x = pq.top().first;
            y = pq.top().second.first;
            i = pq.top().second.second;

            if (i == 0 && row_cnt[y] >= x)
            {
                row_cnt[y] -= x;
                n -= x;
                pq.push(make_pair(row_cnt[y], make_pair(y, 0)));
                ans++;
                for (j = 0; j < row[y].size(); j++)
                {
                    if (col_cnt[row[y][j]])
                        col_cnt[row[y][j]]--;
                }
            }
            else if (i == 1 && col_cnt[y] >= x)
            {
                col_cnt[y] -= x;
                n -= x;
                pq.push(make_pair(col_cnt[y], make_pair(y, 1)));
                ans++;
                for (j = 0; j < col[y].size(); j++)
                {
                    if (row_cnt[col[y][j]])
                        row_cnt[col[y][j]]--;
                }
            }
            else if (n == 0)
                break;
            pq.pop();
        }
        cout << ans << endl;
    }
    return 0;
}