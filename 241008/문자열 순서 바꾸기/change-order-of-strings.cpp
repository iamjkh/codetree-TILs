#include <iostream>
#include <string>
using namespace std;

int main() {
    string a, b;

    cin >> a >> b;

    string c = a;
    a = b;
    b = c;

    cout << a  << "\n" << b;

    return 0;
}