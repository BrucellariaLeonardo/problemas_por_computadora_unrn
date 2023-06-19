#include <iostream>
#include <ginac/ginac.h>
#include "splines.h"
using namespace std;
using namespace GiNaC;
int main(int argc, char** argv)
//este programa recibe por terminal la expresio a evaluar y luego recibe el valor en el que debe ser evaluada
{
    Spline s(argv[1],0,3,30);
    float x;
    x = stof(argv[2]);
    cout << s(x) <<endl;
    return 0;
}
// CODIGO DE EJEMPLO DE USO DE GINAC
/*    symbol x("x");
    symtab table;
    table["x"] = x;
    parser reader(table);
    // Función
    ex f = reader("sqrt(4*x^5 - 6*x^4 + 2*x^3) * cosh (x)");
    cout << "Funcion: " << f << endl;
    numeric f_ev = ex_to<numeric>(f.subs(x==5).evalf());
    double f_d = f_ev.to_double();
    cout << "Evaluación en 5: " << f_d << endl;
    // Derivada 1
    ex f_diff_1 = diff(f, x);
    cout << "Derivada primera: " << f_diff_1 << endl;
    numeric f_diff_1_ev = ex_to<numeric>(f_diff_1.subs(x==5).evalf());
    double f_diff_1_d = f_diff_1_ev.to_double();
    cout << "Evaluación en 5: " << f_diff_1_d << endl;
    // Derivada 2
    ex f_diff_2 = diff(f_diff_1, x);
    cout << "Derivada segunda: " << f_diff_2 << endl;
    numeric f_diff_2_ev = ex_to<numeric>(f_diff_2.subs(x==5).evalf());
    double f_diff_2_d = f_diff_2_ev.to_double();
    cout << "Evaluación en 5: " << f_diff_2_d << endl;
*/
//c++ hello.cc -o hello -lginac -lcln