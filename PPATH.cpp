#include <bits/stdc++.h>
using namespace std;

int prime[10005], dist[10005];
vector<int> v, graph[10005];

int digi_diff(int a, int b)
{
    int d = 0;
    while (a)
    {
        if (a % 10 != b % 10)
            d++;
        a = a / 10;
        b = b / 10;
    }
    return d;
}
void bfs(int a)
{
    int i, j;
    queue<int> q;
    while (!q.empty())
        q.pop();
    for (i = 0; i < 10005; i++)
    {
        dist[i] = INT_MAX;
    }
    dist[a] = 0;
    q.push(a);
    while (!q.empty())
    {
        j = q.front();
        q.pop();
        for (i = 0; i < graph[j].size(); i++)
        {
            if (dist[j] + 1 < dist[graph[j][i]])
            {
                dist[graph[j][i]] = dist[j] + 1;
                q.push(graph[j][i]);
            }
        }
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int i, j, n;
    prime[0] = prime[1] = 1;
    for (i = 1; i < 1000; i++)
    {
        if (prime[i] == 0)
        {
            prime[i] = 1;
            j = i;
            while (i * j < 10005)
            {
                prime[i * j] = 1;
                j++;
            }
        }
    }
    j = 0;
    for (i = 1000; i < 10000; i++)
    {
        if (prime[i] == 0)
        {
            v.push_back(i);
        }
    }
    //cout << v.size();

    for (i = 0; i < v.size(); i++)
    {
        for (j = i + 1; j < v.size(); j++)
        {
            if (digi_diff(v[i], v[j]) == 1)
            {
                graph[v[i]].push_back(v[j]);
                graph[v[j]].push_back(v[i]);
            }
        }
    }
    cin >> n;
    while (n--)
    {
        cin >> i >> j;
        bfs(i);
        if (dist[j] != INT_MAX)
            cout << dist[j] << "\n";
        else
            cout << "Impossible\n";
    }

    return 0;
}