#include <iostream>
using namespace std;


class student{
string name;
float n;

public:
void input(){
cout<<"enter a name:";
cin>>name;
cout<<"enter a number:";
cin>>n;



};

friend void print(student obj) ;






};

void print(student obj) {

cout<<"name of student: " <<obj.name<<endl;

cout<<"scor of student: " <<obj.n<<endl;





}


int main()
{
    student c;

    c.input();
    print(c);

    return 0;
}
