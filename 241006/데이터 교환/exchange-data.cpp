#include <iostream>
using namespace std;

int main() {
    int a = 5, b = 6, c = 7;
    int backb = b;
    int backc = c;
    b = a;
    c = backb;
    a = backc;

    cout << a << "\n";
    cout << b << "\n";
    cout << c << "\n";

    return 0;
}