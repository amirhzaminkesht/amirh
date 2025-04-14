#include <iostream>
using namespace std;

class Vector2D
{
    int x, y;
public:
    Vector2D(int a = 0, int b = 0): x(a), y(b) {}

    int getx() const {return x;}
    int gety() const {return y;}

    void setx(const int &value) {x = value;}
    void sety(const int &value) {y = value;}

    Vector2D operator++()
    {
        x++;
        y++;
        return *this;
    }

    Vector2D operator++(int)
    {
        Vector2D temp = *this;
        ++x;
        ++y;
        return temp;
    }

    friend ostream& operator<<(ostream& out, const Vector2D vec)
    {
        out << "(" << vec.x  << " , " << vec.y << ")";
        return out;
    }
};

int main()
{
    Vector2D vec1(5 , 5);
    vec1++;
    cout << vec1 << endl;
    return 0;
}
