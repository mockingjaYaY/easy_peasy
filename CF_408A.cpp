#include<bits/stdc++.h>
using namespace std;

int main()
{
	long n, k[110], i, x, answer = LONG_MAX, temp, j;
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> k[i];
	}
	
	for (i = 0; i < n; i++)
	{
		temp = 0;
		for (j = 0; j < k[i]; j++)
		{
			cin >> x;
			temp += x * 5 + 15;
		}
		answer = min(answer, temp);
	}

	cout << answer;
	return 0;
}