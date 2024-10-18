#include <iostream>
using namespace std;

int main() {
    int x1, x2, x3, x4;

    cin >> x1 >> x2 >> x3 >> x4;

    if(x3 >= x1 && x2 >=x3 && x4 > x3)
        cout << "intersecting";
    else
        cout << "nonintersecting";

    return 0;
}