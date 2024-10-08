#include <iostream>
using namespace std;

int main() {
    int a;

    cin >> a;

    for(int i=0; i<2; i++)
    {
        if (a % 3 == 0 || a%5 == 0)
            cout << "YES" << "\n";
        else
            cout << "NO" << "\n";
    }
    return 0;
}