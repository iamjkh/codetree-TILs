#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;

int n, m;
vector<vector<int>> g;
vector<vector<bool>> v;
vector<vector<int>> s;

struct Point
{
    int y, x;
};

Point d[4] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

int bfs(const Point& c)
{
    deque<Point> q;
    q.push_back(c);

    while(!q.empty())
    {
        int x = q.front().x;
        int y = q.front().y;
        q.pop_front();

        if(x < 0 || x >= m || y < 0 || y >= n)
            continue;
        if(v[y][x] == true)
            continue;
        
        
        if(g[y][x] == 1)
        {
            for(int i =0; i<4; i++)
            {
                int nx = x + d[i].x;
                int ny = y + d[i].y;

                if(nx < 0 || nx >= m || ny < 0 || ny >= n)
                    continue;

                if(v[ny][nx])
                    continue;

                if(g[ny][nx] == 0)
                    continue;
                
                q.push_back({ny, nx});

                v[y][x] = true;
                s[ny][nx] = s[y][x]+1;
            }
        }
    }

    return s[n-1][m-1];
}


int main(void)
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);

    int k;

    cin >> n >> m;

    g = vector<vector<int>>(n, vector<int>(m, 0));

    for(int j=0; j<n; j++)
    {
        for(int i=0; i<m; i++)
        {
            cin >> g[j][i];
        }
    }
    v = vector<vector<bool>>(n, vector<bool>(m, false));
    s = vector<vector<int>>(n, vector<int>(m, 0));
    s[n-1][m-1] = -1;

    Point start = {0, 0};

    cout << bfs(start);

	return 0;
}