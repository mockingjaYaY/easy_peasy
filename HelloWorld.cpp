#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the maxXor function below.
struct bit
{
	int cnt;
	bit *next[2], *parent;
	bit()
	{
		next[0] = NULL;
		next[1] = NULL;
		parent = NULL;
		cnt = 0;
	}
}*head;

void create(int n, int len)
{
	bit *ptr = head;

	while (len--)
	{
		int last_bit = n % 2;
		n = n / 2;
		if (ptr->next[last_bit] == NULL)
		{
			ptr->next[last_bit] = new bit();
			ptr->cnt += 1;
			ptr->next[last_bit]->parent = ptr;

		}
		ptr = ptr->next[last_bit];
	}
}

int findMax(int q, int len)
{
	bit *ptr = head;
	long long ans = 0, i = 0 ;

	while (len--)
	{
		int last_bit = q % 2;
		q = q / 2;

		if (last_bit == 0)
		{
			if (ptr->next[1] != NULL)
			{
				ans = ans + (1LL << i);
				ptr = ptr->next[1];
			}
			else
			{
				ptr = ptr->next[0];
			}
		}
		else if (last_bit == 1)
		{
			if (ptr->next[0] != NULL)
			{
				ptr = ptr->next[0];
				ans = ans + (1LL << i);
			}
			else
			{
				ptr = ptr->next[1];
			}
		}


		i++;
	}

	free(ptr);
	return ans;
}


vector<int> maxXor(vector<int> arr, vector<int> queries) {
	head = new bit();
	int i;
	vector<int> ans;
	for (i = 0; i < arr.size(); i++)
	{
		create(arr[i], 32);
	}

	for (i = 0; i < queries.size(); i++)
	{
		ans.push_back(findMax(queries[i], 32));
	}
	free(head);
	return ans;

}
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	cin >> n;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	string arr_temp_temp;
	getline(cin, arr_temp_temp);

	vector<string> arr_temp = split_string(arr_temp_temp);

	vector<int> arr(n);

	for (int i = 0; i < n; i++) {
		int arr_item = stoi(arr_temp[i]);

		arr[i] = arr_item;
	}

	int m;
	cin >> m;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	vector<int> queries(m);

	for (int i = 0; i < m; i++) {
		int queries_item;
		cin >> queries_item;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		queries[i] = queries_item;
	}

	vector<int> result = maxXor(arr, queries);

	for (int i = 0; i < result.size(); i++) {
		cout << result[i];

		if (i != result.size() - 1) {
			cout << "\n";
		}
	}

	cout << "\n";



	return 0;
}

vector<string> split_string(string input_string) {
	string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
		return x == y and x == ' ';
	});

	input_string.erase(new_end, input_string.end());

	while (input_string[input_string.length() - 1] == ' ') {
		input_string.pop_back();
	}

	vector<string> splits;
	char delimiter = ' ';

	size_t i = 0;
	size_t pos = input_string.find(delimiter);

	while (pos != string::npos) {
		splits.push_back(input_string.substr(i, pos - i));

		i = pos + 1;
		pos = input_string.find(delimiter, i);
	}

	splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

	return splits;
}
