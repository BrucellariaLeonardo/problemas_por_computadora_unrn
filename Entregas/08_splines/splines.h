/*
Se divide a la curva que se quiere representar en N puntos de control (xi, yi), obtenionedo un polinomio de grado 3 por cada par

se decide utilizar splines hermiticas por lo que seran necesarios los puntos f(xi) y f'(xi) 
este tipo de spline posee derivada primera continua y suave, pero la derivada segunda no

*/

#ifndef SPLINES_H
#define SPLINES_H
#include <iostream>
#include <ginac/ginac.h>
#include <vector>
#include <cmath>


using namespace std;
using namespace GiNaC;

class Spline
{
    private:
    vector<double> x, p,m; //punteros para almacenar los puntos de control y su evaluacion en la funcion y la derivada
    double step; //tamaño de paso
    string formula; //expresion cerrada que se representa
    public:
    Spline(string formula, double xIni, double xEnd, int nDivisions);
    double operator() (double x0);
    friend ostream &operator<<  (std:: ostream& out, const Spline &s);
};
#endif