#include<bits/stdc++.h>
using namespace std;

int main()
{
    map<int, int> duplicate;
    int unique, n, i, j, sum=0, ans = INT_MIN;
    cin>>n;
    for(i=0;i<n;i++) cin>>arr[i];
    i = j = 0;
    duplicate[arr[0]] = 1;
    unique = 1;
    sum = arr[0];
    ans = sum;
    j = 1;
    while(j<n)
    {
        if(duplicate.find(arr[j]) != duplicate.end())
        {
            while(i<j && arr[i]!=arr[j]) 
            {
                sum = sum - arr[i];
                i++;
            }
        }
    }
}