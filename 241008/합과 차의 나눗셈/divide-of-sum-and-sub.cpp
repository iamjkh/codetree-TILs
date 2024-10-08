#include <iostream>
using namespace std;

int main() {
    float a, b;

    cin >> a >> b;

    float c = ((a+b) / (a-b));

    printf("%.2f", c);

    return 0;
}