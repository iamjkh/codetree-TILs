#include <iostream>
using namespace std;

int main() {
    int a, n;

    cin >> a >> n;

    for(int i=1; i<=n; i++)
    {
        cout << a + (n*i) << "\n";
    }

    return 0;
}