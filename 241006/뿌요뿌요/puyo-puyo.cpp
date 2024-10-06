#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<vector<int>> g;
vector<vector<int>> v;
vector<int> p;

struct Point
{
	int y, x;
};

Point d[4] = { {0, 1}, {1, 0}, {-1, 0}, {0, -1} };

void dfs(Point& c, int kk, int& k)
{
	v[c.y][c.x] = true;

	if (g[c.y][c.x] != kk)
		return;

	k++;

	Point next;
	for (int i = 0; i < 4; i++)
	{
		next.y = c.y + d[i].y;
		next.x = c.x + d[i].x;

		if (next.y < 0 || next.y >= n || next.x < 0 || next.x >= n)
			continue;

		if (v[next.y][next.x] == false && g[next.y][next.x] == kk)
		{
			dfs(next, kk, k);
		}
	}
}

int main(void)
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	//freopen("input.txt", "r", stdin);

	cin >> n;

	g = vector<vector<int>>(n, vector<int>(n, 0));

	int maxk = 0;
	for (int j = 0; j < n; j++)
	{
		for (int i = 0; i < n; i++)
		{
			cin >> g[j][i];
			maxk = max(g[j][i], maxk);
		}
	}

	p.resize(maxk+1);
	v = vector<vector<int>>(n, vector<int>(n, false));
	for (int kk = 1; kk <= maxk; kk++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int i = 0; i < n; i++)
			{
				Point c = { j, i };
				int k = 0;
				if (v[j][i] == false && g[j][i] == kk)
					dfs(c, kk, k);

				p[kk] = max(p[kk], k);
			}
		}
	}

	int maxa = 0;
	int explosion = 0;
	for (int k = maxk - 1; k >= 1; k--)
	{
		maxa = max(maxa, p[k]);
		if (p[k] >= 4)
			explosion++;
	}

	cout << explosion << " " << maxa;

	return 0;
}