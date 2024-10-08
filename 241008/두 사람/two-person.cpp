#include <iostream>
using namespace std;

struct person
{
    int age;
    string sex;
}

void is_adult(person& p)
{
    if(p.age >= 19 && p.sex=="M")
        cout << 1;
    else
        cout << 0;
}

int main() {
    person a, b;

    cin >> a.age >> a.sex;
    cin >> b.age >> b.sex;

    is_adult(a);
    is_adult(b);

    return 0;
}