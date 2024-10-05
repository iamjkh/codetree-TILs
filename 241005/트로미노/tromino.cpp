#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int n, m;

struct Point
{
	int y, x;
};

int main(void)
{
	//freopen("input.txt", "r", stdin);
	cin >> n >> m;
	
	vector<vector<Point>> b;
	b.push_back({ { 0, 0 }, {-1, 0}, {0, 1} });
	b.push_back({ { 0, 0 }, {-1, 0}, {0, -1} });
	b.push_back({ { 0, 0 }, {1, 0}, {0, -1} });
	b.push_back({ { 0, 0 }, {1, 0}, {0, 1} });
	b.push_back({ { 0, 0 }, {0, 1}, {0, 2} });
	b.push_back({ { 0, 0 }, {1, 0}, {2, 0} });


	vector<vector<int>> v(n, vector<int>(m, 0));

	for (int j = 0; j < n; j++)
	{
		for (int i = 0; i < m; i++)
		{
			cin >> v[j][i];
		}
	}


	int maxv = 0;
	for (int j = 0; j < n; j++)
	{
		for (int i = 0; i < m; i++)
		{
			for (auto& ib : b)
			{
				int s = 0;
				int x, y;
				for (auto& jb : ib)
				{
					x = i + jb.x;
					y = j + jb.y;
					if (x < 0 || x >= m || y < 0 || y >= n)
					{
						s = 0;
						break;
					}
					s += v[y][x];
				}
				maxv = max(maxv, s);
			}
		}
	}

	cout << maxv;

	return 0;
}