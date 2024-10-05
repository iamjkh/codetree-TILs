#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int n, m;

int main(void)
{
	//freopen("input.txt", "r", stdin);
	cin >> n >> m;

	vector<vector<int>> v(n, vector<int>(n, 0));

	for (int j = 0; j < n; j++)
	{
		for (int i = 0; i < n; i++)
		{
			cin >> v[j][i];
		}
	}
	
	int maxn = 0;

	unordered_map<int, unordered_map<int, int>> a;
	a.reserve(6);

	for (int j = 0; j < n; j++)
	{
		for (int i = 0; i < n; i++)
		{
			int b = v[j][i];
			a[j][b]++;
			a[i+n][b]++;
		}
	}

	int nhappy = 0;
	for (int i = 0; i < n*2; i++)
	{
		for (auto& k : a[i])
		{
			if (k.second == m)
			{
				nhappy++;
				break;
			}
		}
	}

	cout << nhappy;

	return 0;
}