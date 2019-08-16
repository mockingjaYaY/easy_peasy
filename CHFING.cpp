#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

int main()
{
    int t, n, k, l, r, mid, ans, tmp;
    ll N, K;
    cin >> t;
    
    while (t--)
    {
        ans = INT_MAX;
        cin >> K >> N;
        n = N % mod;
        k = K % mod;
        l = n;
        r = n + k;
        r = r - 1 + (r > 1 ? 0 : mod);

        tmp = min(l, r);
        r = max(l, r);
        l = tmp;
        while (l < r)
        {
            mid = (l + r) / 2;
            if (mid + n <= n + k - 1)
            {
                l = mid + 1;
            }
            else
            {
                ans = min(ans, mid + n);
                r = mid;
            }
        }

        //cout<<"cannot be formed "<<ans<<endl;
        if (ans == INT_MAX)
            ans = 0;
        else
        {
            r = n + k;
            r = (r - 1) % mod + (r > 1 ? 0 : mod);
            ans = (ans - r) % mod + (ans > r ? 0 : mod);
            ans = (ans - 1) % mod + (ans > 1 ? 0 : mod);
        }
        tmp = (n - 1) % mod + (n > 1 ? 0 : mod);
        cout << (tmp + ans) % mod << endl;
    }
    return 0;
}