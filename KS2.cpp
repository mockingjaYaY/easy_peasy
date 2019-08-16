#include <bits/stdc++.h>
using namespace std;

long long total[10][25], dp[10][25][200];
long totalNum(long digits, long startingDigit, long sum)
{
    //cout << "for digit " << digits << " starting digit " << startingDigit << " with sum " << sum << endl;
    long x = 0, i;
    if (digits == 0)
    {
        return 1;
    }
    if (dp[startingDigit][digits][sum] != -1)
    {
        //cout<<"returning dp "<<digits<<":"<<sum<<"\n";
        return dp[startingDigit][digits][sum];
    }

    for (i = 0; i < 10; i++)
    {
        x += totalNum(digits - 1, startingDigit, sum + i);
    }
    return dp[startingDigit][digits][sum] = x;
}
int main()
{
#ifndef PRACTICE
    freopen("input.txt", "r", stdin);
    freopen("output1.txt", "w", stdout);
#endif
    memset(dp, -1, sizeof dp);
    long t, i, j;
    long long n;
    for (i = 1; i < 10; i++)
    {
        for (j = 1; j < 21; j++)
        {

            total[i][j] = totalNum(j - 1, i, i);
        }
    }
    
    for (i = 0; i < 10; i++)
    {
        for (j = 1; j < 10; j++)
            cout << total[i][j] << " ";
        cout << endl;
    }
}