#include <bits/stdc++.h>
using namespace std;
#define MAXINT 1000000007
#define ll long long
ll base_dist[16], jump[16], n;

void multiply(ll a[][16], ll b[][16])
{
    ll x[16][16], i, j, k;
    memset(x, 0, sizeof x);
    for (i = 1; i < 16; i++)
    {
        for (j = 1; j < 16; j++)
        {
            for (k = 1; k < 16; k++)
                x[i][j] = ((a[i][k] * b[k][j]) % MAXll + x[i][j]) % MAXll;
        }
    }

    for (i = 1; i < 16; i++)
    {
        for (j = 1; j < 16; j++)
            a[i][j] = x[i][j];
    }
}

ll exp(ll a[][16], ll n)
{
    ll base_matrix[16][16], i, j, ans = 0;
    for (i = 1; i < 16; i++)
    {
        for (j = i; j < 16; j++)
            base_matrix[i][j] = 1;
    }

    if (n == 1)
    {
        ans = 0;
        for (i = 1; i < 16; i++)
        {
            ans = ((a[1][i] * base_dist[i]) % MAINT + ans) % MAXINT;
        }
        return ans;
    }
    exp(a, n / 2);
    multiply(a, a);

    if (n % 2 == 1)
        multiply(a, base_matrix);

    ans = 0;
    for (i = 1; i < 16; i++)
    {
        ans = ((a[1][i] * base_dist[i]) % MAXll + ans) % MAXINT;
    }
    return ans;
}
int main()
{
    ll t, k, i, base_matrix[16][16], j;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        for (i = 0; i < k; i++)
        {
            cin >> jump[i];
        }
        memset(base_dist, 0, sizeof base_dist);
        memset(base_matrix, 0, sizeof base_matrix);
        base_dist[0] = 1;
        for (i = 1; i < 16; i++)
        {
            for (j = 0; j < k; j++)
            {
                if (jump[j] <= i)
                    base_dist[i] = (base_dist[i] + base_dist[i - jump[j]]) % MAXINT;
            }
        }

        //for(i=0;i<16;i++) cout<<base_dist[i]<<endl;
        for (i = 1; i < 16; i++)
        {
            for (j = i; j < 16; j++)
                base_matrix[i][j] = 1;
        }
        if (n < 16)
            cout << base_dist[n] << endl;
        else
            cout << exp(base_matrix, n - 15) << endl;
    }
    return 0;
}