#include <bits/stdc++.h>
using namespace std;
int tree[100005];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t, i, d, ans, x;
    string s;
    stack<int> st;
    cin >> t;
    while (t--)
    {
        while (!st.empty())
            st.pop();
        cin >> s;
        d = 0;
        ans = 0;
        st.push(1);
        for (i = 0; i < s.length(); i++)
        {

            x = st.top();
            st.pop();
            if (s[i] == 'n')
            {
                d++;
                ans = max(ans, d);
                st.push(x * -1);
                st.push(x * 2 + 1);
                st.push(x * 2);
            }
            else
            {
                while (!st.empty() && st.top() < 0)
                {
                    st.pop();
                    d--;
                }
            }
        }
        cout << ans << endl;
    }
}