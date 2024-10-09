#include <iostream>
#include <string>
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

Point d[4] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

Point bfs(const Point& c)
{
    deque<Point> q;
    q.push_back(c);

    int c_val = g[c.y][c.x];
    Point min_point = c;
    int max_val = 0;
    while (!q.empty())
    {
        Point current = q.front(); q.pop_front();
        int y = current.y;
        int x = current.x;
    
        if(x < 0 || x >= n || y < 0 || y >= n)
            continue;

        if(g[y][x] < c_val)
        {
            if(max_val < g[y][x])
            {
                min_point.y = y;
                min_point.x = x;
                max_val = max(max_val, g[min_point.y][min_point.x]);
            }
            if(min_point.y > y && max_val == g[y][x])
            {
                min_point.y = y;
                min_point.x = x;
                max_val = max(max_val, g[min_point.y][min_point.x]);
            }
            if(min_point.y == y && min_point.x > x && max_val == g[y][x])
            {
                min_point.x = x;
                max_val = max(max_val, g[min_point.y][min_point.x]);
            }
        }
        
        for(int i=0; i<4; i++)
        {
            Point next;
            next.y = current.y + d[i].y;
            next.x = current.x + d[i].x;

            if(next.x < 0 || next.x >= n || next.y < 0 || next.y >= n)
                continue;
            if(v[next.y][next.x] == true)
                continue;
            if(g[next.y][next.x] >= c_val)
            {
                v[next.y][next.x] = true;
                continue;
            }
            q.push_back(next);
            v[next.y][next.x] = true;
        }
    }
    
    return min_point;
}


int main(void)
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);

    int k;

    cin >> n >> k;

    g = vector<vector<int>>(n, vector<int>(n, 0));

    for(int j=0; j<n; j++)
    {
        for(int i=0; i<n; i++)
        {
            cin >> g[j][i];
        }
    }

    Point start;

    cin >> start.y >> start.x;
    start.y--;
    start.x--;

    Point current = start;
    for(int i=0; i<k; i++)
    {
        v = vector<vector<bool>>(n, vector<bool>(n, false));
        current = bfs(current);
    }
    
    cout << ++current.y << " " << ++current.x;

	return 0;
}