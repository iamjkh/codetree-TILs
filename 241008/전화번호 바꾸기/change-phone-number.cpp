#include <iostream>
#include <string>
using namespace std;

int main() {
    string p;

    cin >> p;

    string m, l;
    string f = p.substr(0, 3);
    m = p.substr(4, 4);
    l = p.substr(9, 4);

    cout << f << "-" << l << "-" << m;

    return 0;
}