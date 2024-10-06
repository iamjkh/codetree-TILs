#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int n, m;
vector<vector<int>> g;
vector<vector<int>> v;

struct Point
{
	int y, x;
};

Point d[2] = { {0, 1}, {1, 0} };

bool isOK = false;

void dfs(Point& c)
{
	if (c.y == m - 1 && c.x == n-1)
	{
		isOK = true;
	}

	v[c.y][c.x] = true;
	Point next;
	for (int i = 0; i < 2; i++)
	{
		next.y = c.y + d[i].y;
		next.x = c.x + d[i].x;

		if (next.y < 0 || next.y >= m || next.x < 0 || next.x >= n)
			continue;

		if (v[next.y][next.x] == false && g[next.y][next.x] == 1)
		{
			dfs(next);
		}
	}
}

int main(void)
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	//freopen("input.txt", "r", stdin);

	cin >> m >> n;

	g = vector<vector<int>>(n, vector<int>(m, 0));
	v = vector<vector<int>>(n, vector<int>(m, 0));

	for (int j = 0; j < m; j++)
	{
		for (int i = 0; i < n; i++)
		{
			cin >> g[j][i];
		}
	}

	
	Point t;
	t.y = 0;
	t.x = 0;
	if(g[t.y][t.x])
		dfs(t);
	

	cout << isOK;


	return 0;
}