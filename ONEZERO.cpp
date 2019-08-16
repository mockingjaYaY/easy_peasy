#include <bits/stdc++.h>
using namespace std;

int find_remainder(string s, int n)
{
    int quotient = 0, i;
    for (i = 0; i < s.length(); i++)
    {
        quotient = quotient * 10 + s[i] - '0';

        quotient = quotient % n;
    }
    return quotient;
}
string find_num(int n)
{
    queue<string> q;
    string x;
    q.push("1");
    while (!q.empty())
    {
        x = q.front();
        q.pop();
        if (find_remainder(x, n) == 0)
            return x;
        x.push_back('0');
        q.push(x);
        x.pop_back();
        x.push_back('1');
        q.push(x);
    }
    return x;
}
int main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output1.txt", "w", stdout);
    // #endif
    int t, n;
    cin >> t;
    while (t--)
    {
        //memset(dp, -1, sizeof dp);
        cin >> n;
        cout << find_num(n) << endl;
    }
    return 0;
}