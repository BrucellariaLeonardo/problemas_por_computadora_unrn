#ifndef STUDENT_H
#define STUDENT_H
using namespace std;

#include <string>
#include <vector>
#include "date.h"

class Student{
    string name;
    string lastName;
    Date birth;
    string carrer;
    vector <string> subjectsA;
public:
    Student(string name, string lName,int d, int m, int y);
    void addCarrer(string newCarrer);
    void addSubject(string newSub);
    string getDate();
    //string getSubject(string sub);
};

#endif