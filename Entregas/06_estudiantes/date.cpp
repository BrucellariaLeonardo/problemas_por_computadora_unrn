#include "date.h"
Date::Date()
{
    day = -1;
    month = -1;
    year = -1;
}
Date::Date(int y, int m, int d)
{
    day = d;
    year = y;
    month = m;
}


string Date::getD(){
    return to_string(day)+"/"+to_string(month)+"/"+to_string(year);
}

void Date::setD(int d, int m, int y)
{
    day = d;
    year = y;
    month = m;
    return;
}

ostream& operator <<(ostream & o,const Date & p)
{
o << to_string(p.day)+"/"+to_string(p.month)+"/"+to_string(p.year);
return o;
}