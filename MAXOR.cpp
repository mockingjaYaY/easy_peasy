#include <bits/stdc++.h>
using namespace std;

#define allOne (1 << 20) - 1
int arr[1000005], bitree[1000005];

void update(int idx, int val)
{
    for (int i = idx; i < 1000005; i += (i & -i))
    {
        bitree[i] += val;
    }
}

int query(int idx)
{
    int ans = 0;
    for (int i = idx; i > 0; i -= (i & -i))
    {
        ans += bitree[i];
    }
    return ans;
}
int main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    int t, n, i, ans;
    cin >> t;
    while (t--)
    {
        memset(bitree, 0, sizeof bitree);
        ans = 0;
        cin >> n;
        for (i = 0; i < n; i++)
        {
            cin >> arr[i];
            update(arr[i] + 1, 1);
        }
        for (i = 0; i < n; i++)
        {

            cout << (0 ^ arr[i]) << endl;
            if ((arr[i] & (arr[i] + 1)) == 0)
            {
                cout << "running for " << arr[i] << endl;
                ans += query(arr[i]);
                cout << "now ans " << ans << endl;
            }
        }
        for(i=0;i<1000005;i++)
        {
            if((i&(i+1)) == 0)
            {
                int temp =  query(i+1)-query(i);
                ans += (temp*(temp+1))/2;
            }
        }
        cout << ans << endl;
    }
    return 0;
}