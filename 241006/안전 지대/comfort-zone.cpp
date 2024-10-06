#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<vector<int>> g;
vector<vector<int>> v;
vector<int> p;

struct Point
{
	int y, x;
};

Point d[4] = { {0, 1}, {1, 0}, {-1, 0}, {0, -1} };

void dfs(Point& c, int k, int kk, int id)
{
	v[c.y][c.x] = true;

	if (g[c.y][c.x] <= kk)
		return;

	Point next;
	for (int i = 0; i < 4; i++)
	{
		next.y = c.y + d[i].y;
		next.x = c.x + d[i].x;

		if (next.y < 0 || next.y >= n || next.x < 0 || next.x >= m)
			continue;

		if (v[next.y][next.x] == false && g[next.y][next.x] > kk)
		{
			dfs(next, k+1, kk, id);
		}
	}

	if (p[kk] == 0)
		p[kk] = id;
}

int main(void)
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	//freopen("input.txt", "r", stdin);

	cin >> n >> m;

	g = vector<vector<int>>(n, vector<int>(m, 0));

	int maxk = 0;
	for (int j = 0; j < n; j++)
	{
		for (int i = 0; i < m; i++)
		{
			cin >> g[j][i];
			maxk = max(g[j][i], maxk);
		}
	}

	p.resize(maxk);
	for (int k = 1; k < maxk; k++)
	{
		v = vector<vector<int>>(n, vector<int>(m, 0));
		for (int j = 0; j < n; j++)
		{
			for (int i = 0; i < m; i++)
			{
				Point c = { j, i };
				if(v[j][i] == false && g[j][i] > k)
					dfs(c, 0, k, p[k]++);
			}
		}
	}

	int maxa = 0;
	int maxi = 0;
	for (int k = maxk - 1; k >= 1; k--)
	{
		if (maxa < p[k])
		{
			maxa = p[k];
			maxi = k;
		}
	}

	cout << maxi << " " << maxa;

	return 0;
}