#include <iostream>
using namespace std;

void subtractByValue(int x)
{
    x = x - 5;
}

void subtractByReference(int &x)
{
    x = x - 5;
}

int main()
{
    int a = 20;
    subtractByValue(a);
    cout << "Subtraction By Value: "<< a << endl;

    subtractByReference(a);
    cout << "Subtraction By Reference: "<< a << endl;

    return 0;
}
