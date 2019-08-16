#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> v[100005];
map<int, int> norm_k;
int arr[100005];

int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t, n, k, i, j, start_t, end_t, pref_k, K, ans, last_max_time;
    cin >> t;
    while (t--)
    {
        norm_k.clear();
        for (i = 0; i < 100005; i++)
            v[i].clear();
        memset(arr, 0, sizeof arr);
        K = 0;
        cin >> n >> k;
        for (i = 0; i < n; i++)
        {
            cin >> start_t >> end_t >> pref_k;
            if (norm_k.find(pref_k) == norm_k.end())
            {
                K++;
                norm_k[pref_k] = K;
            }

            v[norm_k[pref_k]].push_back(make_pair(end_t, start_t));
        }

        ans = 0;
        for (i = 1; i <= K; i++)
        {
            sort(v[i].begin(), v[i].end());
            last_max_time = 0;

            for (j = 0; j < v[i].size(); j++)
            {
                if (v[i][j].second >= last_max_time)
                {
                    ans++;
                    last_max_time = v[i][j].first;
                    //cout << last_max_time << endl;
                }
            }
        }

        cout << ans << "\n";
    }
    return 0;
}