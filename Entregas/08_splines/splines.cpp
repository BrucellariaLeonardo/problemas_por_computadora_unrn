#include "splines.h"

Spline:: Spline(string formula, float xIni, float xEnd, int nDivisions)
{
    //inicialization of the structure
    n = nDivisions;
    step = (xEnd-xIni)/(nDivisions-1); //definition space betwin one x and the next
    x = new float[nDivisions];
    p = new float[nDivisions];
    m = new float[nDivisions];
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
    for (int i=0; i<nDivisions; i++)
    {
        //valores de los puntos de control
        x[i] = xIni + step * i; 
        //valores de la funcion en los puntos de control
        evAux = ex_to<numeric>(f.subs(s==x[i]).evalf());
        p[i] = evAux.to_double();
        //valores de la derivada en los puntos de control
        evAux = ex_to<numeric>(fd.subs(s==5).evalf());
        m[i] = evAux.to_double();
    }
}