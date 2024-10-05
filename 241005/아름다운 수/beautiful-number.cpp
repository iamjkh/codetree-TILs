#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int n, k;
int b = 0;

bool isBeautyful(vector<int>& v)
{
	int c = 0;
	int b = 0;
	for (int i = 0; i < v.size(); i++)
	{
		if (c == 0 && b == 0)
		{
			b = v[i];
			c = b;
		}
		c--;
		if (c == 0 && b == v[i])
		{
			b = 0;
		}
		else if (b != v[i])
			return false;
	}

	if (c != 0 || b != 0)
		return false;

	return true;
}

void permutation(vector<int>& v)
{
	if (v.size() == n)
	{
		if (isBeautyful(v))
			b++;
		return;
	}

	for (int i = 1; i <= k; i++)
	{
		v.push_back(i);
		permutation(v);
		v.pop_back();
	}
}


int main(void)
{
	//freopen("input.txt", "r", stdin);
	cin >> n;

	k = 4;

	vector<int> v;

	permutation(v);

	cout << b;

	return 0;
}