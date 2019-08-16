#include <bits/stdc++.h>
using namespace std;

vector<int> primes;
bool prime[1000005];

void markPrimes()
{
    memset(prime, 0, sizeof prime);
    prime[0] = prime[1] = 1;
    int i, x;
    for (i = 2; i < 1005; i++)
    {
        if (prime[i] == 0)
        {
            x = i;
            while (x * i < 1000005)
            {
                prime[x * i] = 1;
                x++;
            }
        }
    }

    for (i = 0; i < 1000005; i++)
    {
        if (prime[i] == 0)
            primes.push_back(i);
    }
}
int main()
{
    int t, n, i, turn = 0;
    markPrimes();

    cin >> t;
    while (t--)
    {
        cin >> n;
        for (i = 0; primes[i] <= sqrt(n); i++)
        {
            if (n % primes[i] == 0)
            {
                n = n - (n / primes[i]);
                i = -1;
                turn++;
            }
        }

        if (turn % 2 == 0)
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }

    return 0;
}