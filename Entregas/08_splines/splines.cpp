#include "splines.h"

Spline:: Spline(string formula, double xIni, double xEnd, int nPoints)
{
    //inicialization of the structure
    step = (xEnd-xIni)/(nPoints-1); //definition space betwin one x and the next
    formula = formula;

    //lectura de la expresion
    symbol s("x");
    symtab table;
    table["x"] = s;
    parser reader(table);
    ex f = reader(formula); //obtencion exprecion
    ex fd = diff(f,s);

    //variables auxiliares
    numeric evAux;
    for (int i=0; i<nPoints; i++)
    {
        //valores de los puntos de control
        x.push_back(xIni+step*i);
        //valores de la funcion en los puntos de control
        evAux = ex_to<numeric>(f.subs(s==x[i]).evalf());
        p.push_back( evAux.to_double());
        //valores de la derivada en los puntos de control
        evAux = ex_to<numeric>(fd.subs(s==x[i]).evalf());
        m.push_back( evAux.to_double());
    }
}
double Spline:: operator() (double x0)
{
    int i = floor((x0-x[0])/step);
    double t = (x0 - x[i])/(x[i+1]-x[i]);
    return (2*p[i]+m[i]-2*p[i+1]+m[i+1])*std::pow(t,3) + (-3*p[i]+3*p[i+1]-2*m[i]-m[i+1])*std::pow(t,2)+m[i]*t+p[i];
}