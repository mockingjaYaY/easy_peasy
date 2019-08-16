#include <bits/stdc++.h>
using namespace std;

#define MAXINT 1000000007
int arr[1000005];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, k, i, ans = 1, x;
    stack<int> st;
    cin >> n >> k;
    for (i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (i = 0; i < n; i++)
    {
        while (!st.empty() && arr[st.top()] > arr[i])
        {
            ans = (ans * (i - st.top() + 1)) % MAXINT;
            st.pop();
        }
        st.push(i);
    }

    cout << ans;
    return 0;
}