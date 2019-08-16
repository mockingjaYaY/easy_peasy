#include<bits/stdc++.h>
using namespace std;


int main()
{
	double total_time = 0;
	int x[110], y[110], n, k, i;
	cin >> n >> k;
	for (i = 0; i < n; i++)
	{
		cin >> x[i] >> y[i];
		if (i > 0)
		{
			total_time += sqrt((x[i] - x[i - 1]) * (x[i] - x[i - 1]) + (y[i] - y[i - 1]) * (y[i] - y[i - 1]));
		}
	}

	cout << fixed << setprecision(9) << total_time * k / 50.0;
	return 0;
}