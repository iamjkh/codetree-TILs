#include <iostream>
using namespace std;

int main() {
    
    int a, b;

    cin >> b >> a;
    while(true)
    {
        if(b%2==0)
            cout << b << " ";
        if(b == a)
            break;
        b--;
    }


    return 0;
}