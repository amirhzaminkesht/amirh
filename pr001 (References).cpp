#include <iostream>
using namespace std;

int main()
{
    int num = 50;
    int &refNum = num;
    refNum = 75;
    cout << num << "\t" << refNum;
    //Refrence Questions//
    return 0;
}

