#include <iostream>
using namespace std;

int main()
{
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for(int i = 1; i < 11; i++)
    {
        arr[i] = i +10;
        cout << "Element " << i << ": " << arr[i] << endl;
    }
    return 0;
}
