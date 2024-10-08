#include <iostream>
using namespace std;

void compare(int&a, int&b)
{
    if(a > b)
        cout << 1 << "\n";
    else
        cout << 0 << "\n";
}

int main() {
    int a, b, c, d, e;

    cin >> a >> b >> c >> d >> e;

    compare(a, b);
    compare(a, c);
    compare(a, d);
    compare(a, e);

    return 0;
}