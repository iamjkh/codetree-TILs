#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;

int n;

struct Op
{
    int c; //현재수
    int n; //연산횟수
};

int min_op = 1e9;

void bfs(int in)
{
    deque<Op> q;
    q.push_back({in, 0});


    while(!q.empty())
    {
        Op c = q.front(); q.pop_front();
        if(c.c == 1 && min_op > c.n)
        {
            min_op = c.n;
        }
        
        if(c.c > 1 && min_op > c.n +1)
        {
            q.push_back({c.c-1, c.n+1});
            q.push_back({c.c+1, c.n+1});
            if(c.c%2 == 0)
                q.push_back({c.c/2, c.n+1});
            if(c.c%3 == 0)
                q.push_back({c.c/3, c.n+1});
        }
    }
}

int main(void)
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);

    cin >> n;
    bfs(n);

    cout << min_op;

	return 0;
}