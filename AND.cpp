#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll bits[35], arr[100005];
int main()
{
    ll n, i, x, j, carry, ans;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
        x = arr[i];
        j = 0;
        while(x)
        {
            if(x%2 == 1)
                bits[j]++;
            j++;
            x=x/2;
        }
    }
    x = j = carry = ans = 0;
    for(i=0;i<35;i++)
    {
        j = ((bits[i]-1)*bits[i])/2;
        
        if((carry + j) %2 == 1)
            {
                ans += (1<<i);
                x = max(x, i);
            }
        carry = (carry+j)/2;
    }
    i = x+1;
    while(carry)
    {
        if(carry%2 == 1)
        {
            ans += (1<<i);
        }
        i++;
        carry = carry/2;
    }
    cout<<ans;
    return 0;

}