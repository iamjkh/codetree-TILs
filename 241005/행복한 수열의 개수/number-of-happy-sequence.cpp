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

	unordered_map<int, vector<int>> a;
	a.reserve(6);

	for (int j = 0; j < n; j++)
	{
		for (int i = 0; i < n; i++)
		{
			int b = v[j][i];
			a[j].push_back(b);
			a[i+n].push_back(b);
		}
	}

	int ihappy = 0;
	for (int i = 0; i < 2 * n; i++)
	{
		int nhappy = 0;
		for (int j = 0; j < a[i].size(); j++)
		{
			if (m == 1)
			{
				nhappy = 1;
				break;
			}
			else
			{
				if (j == 0)
					continue;
				
				if (a[i][j - 1] - a[i][j] == 0)
					nhappy++;
				else
					nhappy = 0;
				
				if (nhappy >= m)
					break;
			}
		}
		if (nhappy > 0)
			ihappy++;
	}

	cout << ihappy;

	return 0;
}