#include "splines.h"

Spline:: Spline(string formula, double xIni, double xEnd, int nPoints)
{
    //inicialization of the structure
    step = (xEnd-xIni)/(nPoints-1); //definition space betwin one x and the next
    this->formula = formula;

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
    double h00, h01, h10, h11;
    int i = floor((x0-x[0])/step);
    double t = (x0 - x[i])/(x[i+1]-x[i]);
    //return (2*p[i]+m[i]-2*p[i+1]+m[i+1])*std::pow(t,3) + (-3*p[i]+3*p[i+1]-2*m[i]-m[i+1])*std::pow(t,2)+m[i]*t+p[i];
    h00 = 2*std::pow(t,3)-3*std::pow(t,2)+1;
    h10 = std::pow(t,3)-2*std::pow(t,2)+t;
    h01 = -2*std::pow(t,3)+3*std::pow(t,2);
    h11 = std::pow(t,3)-std::pow(t,2);
    return h00*p[i]+h10*(x[i+1]-x[i])*m[i]+h01*p[i+1]+h11*(x[i+1]-x[i])*m[i+1];
}
ostream &operator<<  (std:: ostream& out, const Spline &s)
{
    out << s.formula <<endl;
    for(double element: s.x)
    {
        out << element << " ";
    }
    out << endl;
    for(double element: s.p)
    {
        out << element << " ";
    }
    out << endl;
    for(double element: s.m)
    {
        out << element << " ";
    }
    out << endl;
    return out;
}