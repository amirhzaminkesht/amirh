#include <iostream>
using namespace std;

class Person
{
    string name;
    int age;
public:
    Person(string n, int a): name(n), age(a)
    {
        cout << n << endl << a << endl;
    }
    ~Person()
    {
        cout << "The Object Is Being Destroyed." << endl;
    }
};

int main()
{
    Person obj("Ali", 18);
    return 0;
}
