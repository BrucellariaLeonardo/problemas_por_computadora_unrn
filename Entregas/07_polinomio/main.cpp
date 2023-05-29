#include<iostream>
#include <fstream>
#include "polinom.h"
using namespace std;

int main()
{
    Polinom pol;
    ifstream F;
    F.open("pol.txt", ios::in);
    F >> pol;
    F.close();
    cout << pol;
    return 0;
}