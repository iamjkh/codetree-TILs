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

bool isOK = false;

int dfs(Point& c, int k)
{
	v[c.y][c.x] = true;
	if(g[c.y][c.x])
		k++;

	Point next;
	for (int i = 0; i < 4; i++)
	{
		next.y = c.y + d[i].y;
		next.x = c.x + d[i].x;

		if (next.y < 0 || next.y >= n || next.x < 0 || next.x >= n)
			continue;

		if (v[next.y][next.x] == false && g[next.y][next.x] == 1)
		{
			k = dfs(next, k);
		}
	}

	return k;
}

int main(void)
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	//freopen("input.txt", "r", stdin);

	cin >> n;

	g = vector<vector<int>>(n, vector<int>(n, 0));
	v = vector<vector<int>>(n, vector<int>(n, 0));

	for (int j = 0; j < n; j++)
	{
		for (int i = 0; i < n; i++)
		{
			cin >> g[j][i];
		}
	}

	

	for (int j = 0; j < n; j++)
	{
		for (int i = 0; i < n; i++)
		{
			if (v[j][i] == 0 && g[j][i] == 1)
			{
				Point t;
				t.y = j;
				t.x = i;
				p.push_back(dfs(t, 0));
			}
		}
	}
	
	cout << p.size() <<"\n";
	sort(p.begin(), p.end());

	for (auto& pp : p)
		cout << pp << "\n";


	return 0;
}