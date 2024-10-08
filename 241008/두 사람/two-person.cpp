#include <iostream>
using namespace std;

struct person
{
    int age;
    string sex;
};

int is_adult(person& p)
{
    if(p.age >= 19 && p.sex=="M")
        return 1;
    else
        return 0;
}

int main() {
    person a, b;

    cin >> a.age >> a.sex;
    cin >> b.age >> b.sex;

    int ar = is_adult(a);
    int br = is_adult(b);

    if(ar || br)
        cout << 1 << "\n";
    else
        cout << 0 << "\n";

    return 0;
}