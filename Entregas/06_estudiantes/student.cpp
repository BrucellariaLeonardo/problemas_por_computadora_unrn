#include "student.h"

Student:: Student(string name, string lName, int d, int m, int y)
{
 this->name = name;
 this->lastName = lName;
 this->birth.setD(d,m,y);
}

void Student::addCarrer(string newCarrer)
{
    this->carrer = newCarrer;
    return;
}
string Student::getDate()
{
    return this->birth.getD();
}
void Student::addSubject(string newSub)
{
    this->subjectsA.push_back(newSub);
}
