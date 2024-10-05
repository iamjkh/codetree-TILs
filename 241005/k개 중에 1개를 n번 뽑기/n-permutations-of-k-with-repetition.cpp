#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int n, k;

void permutation(vector<int>& v)
{
	if (v.size() == n)
	{
		for (auto& iv : v)
		{
			cout << iv << " ";
		}
		cout << "\n";
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
	cin >> k >> n;

	vector<int> v;

	permutation(v);

	return 0;
}