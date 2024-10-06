#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;

int n, m;
vector<vector<int>> g;
vector<vector<bool>> v;

struct Point
{
	int y, x;
};

Point d[4] = { {0, 1}, {1, 0}, {-1, 0}, {0, -1} };

void bfs(Point c, bool& alive)
{
	deque<Point> q;

	q.push_back(c);

	while (!q.empty())
	{
		Point current = q.front(); q.pop_front();
		int x = current.x;
		int y = current.y;

		v[y][x] = true;

		if (y == n - 1 && x == m - 1)
		{
			alive = true;
			return;
		}

		for (int i = 0; i < 4; i++)
		{
			int ny = d[i].y + y;
			int nx = d[i].x + x;

			if (ny < 0 || ny >= n || nx < 0 || nx >= m)
				continue;

			if (g[ny][nx] == 1 && v[ny][nx] == false)
				bfs({ ny, nx }, alive);
		}
	}
}

int main(void)
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	//freopen("input.txt", "r", stdin);

	cin >> n >> m;

	g = vector<vector<int>>(n, vector<int>(m, 0));
	v = vector<vector<bool>>(n, vector<bool>(m, 0));

	for (int j = 0; j < n; j++)
	{
		for (int i = 0; i < m; i++)
		{
			cin >> g[j][i];
		}
	}

	bool alive = false;
	bfs({ 0, 0 }, alive);

	cout << alive;

	return 0;
}