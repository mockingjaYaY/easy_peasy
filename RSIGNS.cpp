#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define ll long long

ll power(ll n, ll k)
{
    ll ans = 1;
    while (k)
    {
        if (k % 2 == 1)
            ans = (ans * n) % mod;
        k = k / 2;
        n = (n * n) % mod;
    }
    return ans;
}
int main()
{
    ll t, k, temp, p;
    cin >> t;
    while (t--)
    {
        cin >> k;
        p = power(2, k);
        //cout<<"p "<<(p-1)%mod;
        temp = (p - 1) % mod + (p >= 1 ? 0 : mod);
        cout << (10 * temp) % mod << endl;
    }
    return 0;
}