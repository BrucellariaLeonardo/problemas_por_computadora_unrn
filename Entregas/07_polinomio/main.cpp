#include<iostream>
#include <fstream>
#include "polinom.h"
using namespace std;

int main()
{
    Polinom pol1, pol2, pol3;
    ifstream F;
    F.open("pol.txt", ios::in);
    F >> pol1;
    F >> pol2;
    F >> pol3;
    F.close();
    cout << pol1;
    //cout << pol2;
    //cout << pol3;
    cout << (pol1/ pol3);
    cout << (pol1% pol1);
    cout << pol1;
    cout << "\n";
    return 0;
}