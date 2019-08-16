#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}
int modulo(string s, int x)
{
    string temp;
    int numerator = 0, i;
    for (i = 0; i < temp.length(); i++)
    {
        if (numerator >= x)
            numerator = numerator / x;
        numerator = numerator * 10 + s[i] - '0';
    }
    return numerator % x;
}
int main()
{
  
    string s;
    int x, t;
    cin >> t;
    while (t--)
    {
        cin >> x >> s;
        if (x == 0)
            cout << s << endl;
        else if (s == "0")
            cout << endl;
        cout << gcd(x, modulo(s, x)) << endl;
    }
    return 0;
}