#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;

int n;
vector<vector<int>> g;
vector<vector<bool>> v;

struct Point
{
	int y, x;
};

Point d[4] = { {0, 1}, {1, 0}, {-1, 0}, {0, -1} };

void bfs(Point c, int& blob)
{
	deque<Point> q;

	q.push_back(c);

	while (!q.empty())
	{
		Point current = q.front(); q.pop_front();
		int x = current.x;
		int y = current.y;

		v[y][x] = true;

		if (g[y][x] == 0)
			blob++;

		for (int i = 0; i < 4; i++)
		{
			int ny = d[i].y + y;
			int nx = d[i].x + x;

			if (ny < 0 || ny >= n || nx < 0 || nx >= n)
				continue;

			if (g[ny][nx] == 0 && v[ny][nx] == false)
				bfs({ ny, nx }, blob);
		}
	}
}

int main(void)
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	//freopen("input.txt", "r", stdin);

	int k;
	cin >> n >> k;

	g = vector<vector<int>>(n, vector<int>(n, 0));
	v = vector<vector<bool>>(n, vector<bool>(n, 0));

	for (int j = 0; j < n; j++)
	{
		for (int i = 0; i < n; i++)
		{
			cin >> g[j][i];
		}
	}

	int blob = 0;
	for (int i = 0; i < k; i++)
	{
		int x, y;
		cin >> x >> y;
		if(v[y-1][x-1] == false)
			bfs({ y-1, x-1 }, blob);
	}

	cout << blob;

	return 0;
}