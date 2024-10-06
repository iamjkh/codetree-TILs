#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int t = 0;
vector<vector<int>> g;
vector<bool> visited;
int n, m;

void dfs(int c)
{
	for (int i = 1; i < g[c].size(); i++)
	{
		int curr = g[c][i];
		if (!visited[curr])
		{
			visited[curr] = true;
			t++;
			dfs(curr);
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

	g = vector<vector<int>>(n+1);
	visited.resize(n + 1);


	int a, b;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;

		g[a].push_back(b);
		g[b].push_back(a);
	}

	visited[1] = true;
	dfs(1);
	
	cout << t;

	return 0;
}