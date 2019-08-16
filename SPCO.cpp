#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll prime[100], dp[65][65][2];

void seive()
{
    int x, i;
    prime[0] = prime[1] = 1;

    for (i = 2; i <= 10; i++)
    {
        if (prime[i] == 0)
        {
            x = i;
            while (x * i <= 100)
            {
                prime[i * x] = 1;
                x++;
            }
        }
    }
}
ll solve(unsigned ll a, unsigned ll b, unsigned ll num, ll ones, ll zeroes)
{
    //cout << num <<" "<<ones<<" "<<zeroes<<endl;

    if (ones + zeroes == 64 || num > b)
        return 0;
    if (num >= a && num <= b && prime[ones] == 0)
    {
        //cout << "returning one\n";
        return 1;
    }

    if (dp[ones][zeroes][num & 1] != -1)
    {
        //cout<<"returning dp\n";
        return dp[ones][zeroes][num & 1];
    }

    dp[ones][zeroes][num & 1] = solve(a, b, (num << 1), ones, zeroes + 1) + solve(a, b, (num << 1) + 1, ones + 1, zeroes);

    return dp[ones][zeroes][num & 1];
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll t;
    unsigned ll a, b;
    seive();
    cin >> t;
    while (t--)
    {
        cin >> a >> b;
        memset(dp, -1, sizeof dp);
        cout << solve(a, b, 1, 1, 0) << endl;
    }
    return 0;
}