#include <iostream>
using namespace std;

struct Student
{
    string name;
    float score;
};

int main()
{
//    Student A = {"Sahar", 19.50};
    Student A;
    A.name = "Sahar";
    A.score = 19.50;
    cout << "The student " << A.name << " had a score of " << A.score << " overall." << endl;
    return 0;
}
