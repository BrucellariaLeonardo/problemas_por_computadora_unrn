#ifndef DATE_H
#define DATE_H
#include <string>
#include <iostream>
using namespace std;


class Date{
    int day;
    int month;
    int year;
public:
    Date();
    Date (int y, int m, int d);
    void setD (int d, int m, int y);
    string getD ();
    //~date(); //DUDAS
    friend ostream& operator << (ostream & o,const Date & p);
    //ostream & operator<<(ostream & os,  Date & dt)
    //friend ostream operator << (ostream & out, date & d);
    //sobrecargas

};

#endif