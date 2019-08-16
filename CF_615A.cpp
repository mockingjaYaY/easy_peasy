#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n, m, i, flag = 0, x, bulb[150], j, y;
	memset(bulb, 0, sizeof bulb);

	cin >> n >> m;
	for (i = 0; i < n; i++)
	{
		cin >> x;
		for (j = 0; j < x; j++)
		{
			cin >> y;
			bulb[y] = 1;
		}
	}

	for (i = 1; i <= m; i++)
	{
		if (bulb[i] == 0)
			flag = 1;
	}

	if (flag == 1)
		cout << "NO";
	else
		cout << "YES";
}