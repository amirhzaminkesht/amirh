#include <iostream>
using namespace std;

class Complex
{
    double r, i;
public:
    Complex();
    Complex(double, double);
    void input();
    double getRel() const;
    double getIm() const;
    void setRel(double);
    void setIm(double);
    void display() const;
    Complex operator +(const Complex&);
    friend ostream& operator <<(ostream& , const Complex&);
};

int main()
{
    Complex obj1;
    obj1.input();
    Complex obj2;
    obj2.input();
    Complex obj3 = obj1 + obj2;
//    obj3.display();
    cout << "Your Number is " << obj3;
    return 0;
}

Complex:: Complex()
    {
        double& x = r;
        double& y = i;
        x = 0;
        y = 0;
    }
Complex:: Complex(double x, double y): r(x), i(y) {}

void Complex:: input()
{
    cout << "Real part: ";
    cin >> r;
    cout << endl;

    cout << "Imaginary part: ";
    cin >> i;
    cout << endl;
}

double Complex:: getRel() const
{
    return r;
}
double Complex:: getIm() const
{
    return i;
}

void Complex:: setRel(double newRel)
{
    r = newRel;
}
void Complex:: setIm(double newIm)
{
    i = newIm;
}

void Complex:: display() const
{
    cout << "\nYour number is " << *this;
}

Complex Complex:: operator +(const Complex& other)
{
    double R = r + other.r;
    double I = i + other.i;
    return Complex(R, I);
}

ostream& operator <<(ostream& out, const Complex& obj)
{
    out << "(" << obj.r << " , " << obj.i << ")";
    return out;
}
