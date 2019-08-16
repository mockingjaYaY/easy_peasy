#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n, birds[150], m, x, y, i;
	memset(birds, 0, sizeof birds);
	cin >> n;
	for (i = 1; i <= n; i++)
	{
		cin >> birds[i];
	}

	cin >> m;
	for (i = 0; i < m; i++)
	{
		cin >> x >> y;
		if (x - 1 > 0) birds[x - 1] += y - 1;
		if (x + 1 <= n) birds[x + 1] = b+irds[x] - y;

		birds[x] = 0;
	}

	for (i = 1; i <= n; i++)
		cout << birds[i] << endl;

	return 0;

}