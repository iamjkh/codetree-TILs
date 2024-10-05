#include <iostream>
#include <vector>
using namespace std;

int n;

int main(void)
{
	//freopen("input.txt", "r", stdin);
	cin >> n;

	vector<vector<int>> v(n, vector<int>(n, 0));

	for (int j = 0; j < n; j++)
	{
		for (int i = 0; i < n; i++)
		{
			cin >> v[j][i];
		}
	}
	
	int maxn = 0;
	for (int j = 1; j < n - 1; j++)
	{
		for (int i = 1; i < n - 1; i++)
		{
			int a = v[j - 1][i - 1] + v[j - 1][i] + v[j - 1][i + 1] + v[j][i - 1] + v[j][i] + v[j][i + 1] + v[j + 1][i - 1] + v[j + 1][i] + v[j + 1][i + 1];
			maxn = max(maxn, a);
		}
	}

	cout << maxn;

	return 0;
}