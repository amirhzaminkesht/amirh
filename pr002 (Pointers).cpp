#include <iostream>
using namespace std;

int main()
{
    int *ptr = new int;
    *ptr = 100;
    cout << "Number: " << *ptr << endl;
    delete ptr;
    *ptr != 100? cout << "Dead!": cout << "Alive!";
    return 0;
}
