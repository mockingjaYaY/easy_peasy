#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n, x;
    cin>>n;
    while(n--)
    {
        cin>>x;
        if(x%2==0) cout<<"BOB\n";
        else cout<<"ALICE\n";
    }
    return 0;
}