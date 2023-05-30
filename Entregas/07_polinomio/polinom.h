/*
implementación de polinomios de coeficientes con operaciones de 
    suma
    resta
    multiplicación
    división
    evaluación
    búsqueda de raíces en un entorno por el método de bisección módulo un cierto error relativo y factorización usando división. 

La idea es implementar toda la clase
    constructores
    destructores
    asignación
    operadores
    input
    output
*/
# ifndef POLINOM_H
# define POLINOM_H

#include <iostream>
#include <cmath>
using namespace std;

class Polinom
{
private:
    int grade;
    float* coeficents; 
public:
    Polinom (); //POLINOMIO VACIO
    Polinom(const int g,const float *c); //CREACION DE UN POLINOMIO A PARTIR DE UN GRADO Y UNA LISTA DE FLOTANTES
    Polinom (const Polinom &p); //CONSTRUCTOR POR COPIA
    ~Polinom();
    Polinom operator+ (const Polinom &p);
    Polinom operator- (const Polinom &p);
    Polinom operator* (const Polinom &mult);
    Polinom operator/ (const Polinom &d);
    Polinom operator% (const Polinom &d);
    float operator() (float x);
    bool operator== (const Polinom &p);
    bool operator!= (const Polinom &p);
    bool operator!= (const float c);
    friend istream &operator>> (istream &data, Polinom &pol);
    friend ostream &operator<<  (std:: ostream& out, const Polinom &pol);


};

istream &operator>> (istream &data, Polinom &pol)
{
    data >> pol.grade;
    delete(pol.coeficents);
    pol.coeficents = new float[pol.grade+1];
    for (int i = 0; i <= pol.grade; i++)
        data >> pol.coeficents[i];
    return data;
}
ostream &operator<<  (std:: ostream& out, const Polinom &pol)
{
    for(int i=pol.grade; i>=0; i--)
    {
        out << pol.coeficents[i];
        out << "X^";
        out << i;
        out << " ";
    }
    out << "\n";
    return out;
}


Polinom:: Polinom (){
    grade = 0;
    coeficents = new float[0];
    coeficents[0] = 0;
}
Polinom::Polinom(const int g,const float *c) //contructor a partir de un grado y una lista de constantes
{
    grade = g;
    coeficents = new float[g+1];
    for (int i=0; i<=grade; i++)
    {
        coeficents[i] = c[i];
    }
}
Polinom::Polinom (const Polinom &p) //constructor por copia
{
    grade = p.grade;
    coeficents = new float[p.grade+1];
    for (int i=0; i<=p.grade; i++)
    {
        coeficents[i] = p.coeficents[i];
    }
}

Polinom Polinom:: operator+ (const Polinom &p)
{
    Polinom res;
    if(grade > p.grade) //determino cual polinomio posee un mayor grade 
    {
        res.grade = grade;
        for(int i= 0; i<=p.grade; i++) //sumo los coeficientes que poseen valores de ambos polinomios
        {
            res.coeficents[i] = coeficents[i] + p.coeficents[i];
        }
        for(int i = p.grade+1; i<=grade; i++) //agrego los coeficientes de mayor orden
        {
            res.coeficents[i] = coeficents[i];
        }
    }else if (p.grade > grade){
        res.grade = p.grade;
        for(int i= 0; i<=grade; i++) //sumo los coeficientes que poseen valores de ambos polinomios
        {
            res.coeficents[i] = coeficents[i] + p.coeficents[i];
        }
        for(int i = grade+1; i<=p.grade; i++) //agrego los coeficientes de mayor orden
        {
            res.coeficents[i] = p.coeficents[i];
        }
    }else{
        res.grade = p.grade;
        for(int i= 0; i<=grade; i++) //sumo los coeficientes que poseen valores de ambos polinomios
        {
            res.coeficents[i] = coeficents[i] + p.coeficents[i];
        }
    }
    return res;
}
Polinom Polinom::operator- (const Polinom &p)
{
    Polinom res;
    if(grade > p.grade) //determino cual polinomio posee un mayor grade 
    {
        res.grade = grade;
        for(int i= 0; i<=p.grade; i++) //sumo los coeficientes que poseen valores de ambos polinomios
        {
            res.coeficents[i] = coeficents[i] - p.coeficents[i];
        }
        for(int i = p.grade+1; i<=grade; i++) //agrego los coeficientes de mayor orden
        {
            res.coeficents[i] = coeficents[i];
        }
    }else if (p.grade > grade){
        res.grade = p.grade;
        for(int i= 0; i<=grade; i++) //sumo los coeficientes que poseen valores de ambos polinomios
        {
            res.coeficents[i] = coeficents[i] - p.coeficents[i];
        }
        for(int i = grade+1; i<=p.grade; i++) //agrego los coeficientes de mayor orden
        {
            res.coeficents[i] = -p.coeficents[i];
        }
    }else{
        res.grade = p.grade;
        for(int i= 0; i<=grade; i++) //sumo los coeficientes que poseen valores de ambos polinomios
        {
            res.coeficents[i] = coeficents[i] - p.coeficents[i];
        }
    }
    return res;
}  
float Polinom::operator() (float x)
{
    float res = 0;
    for(int i= 0; i<=grade; i++)
    {
        res += coeficents[i]*(pow(x,i));
    }
    return res;
}
bool Polinom:: operator== (const Polinom &p)
{
    bool flag = true;
    if(p.grade == grade)
    {
        for(int i = 0; i<=grade; i++)
        {
            if(coeficents[i] != p.coeficents[i])
            {
                flag = false;
            }
        }

    }else{
        flag = false;
    }
    return flag;
}
bool Polinom:: operator!= (const Polinom &p)
{
    bool flag = false;
    if(p.grade == grade)
    {
        for(int i = 0; i<=grade; i++)
        {
            if(coeficents[i] != p.coeficents[i])
            {
                flag = true;
            }
        }

    }else{
        flag = true;
    }
    return flag;
}
bool Polinom::operator!= (const float c)
{
    bool flag = false;
    for (int i =0; i<=grade; i++)
    {
        if( coeficents[i] != c)
        {
            flag = true;
            break;
        }
    }
    return flag;
}


Polinom Polinom::operator* (const Polinom &mult) //TO DO
{
    //creacion de un polinomio res lleno de ceros
    Polinom res;
    res.grade = grade+mult.grade;
    delete(res.coeficents);
    res.coeficents = new float[res.grade];
    for (int i = 0; i<res.grade; i++) res.coeficents[i] = 0;
    //se calcula cada termino de la multiplicacion uno a uno y se los suma a su grado correspondiente
    for (int i = 0; i<=mult.grade; i++)
    {
        for (int j = 0; j<=grade; j++)
        {
            res.coeficents[i+j] += mult.coeficents[i]*coeficents[j];
        }

    }
    return res;
}

Polinom Polinom:: operator/ (const Polinom &d) //&d = divisor
{
    Polinom r(*this); //dividendo
    Polinom res;
    if((d.coeficents != NULL and (d.grade != 0 or d.coeficents[0] != 0))) //compruevo que mi divisor no sea el polinomio nulo
    {
        if(grade >= d.grade)
        {
            res.grade = grade-d.grade;
            delete(res.coeficents);
            res.coeficents = new float[res.grade];
        }
        int i = 0; //pivote para la division
        while ( (r != 0) and ((r.grade-i) >= d.grade)) // condiciones para finalizar la division (resto 0 o dividendo de menor orden que el divisor)
        {
            res.coeficents[res.grade - i] = r.coeficents[grade-i]/d.coeficents[d.grade]; // calculo un nuevo termino del polinomio resultado
            for(int j = 0; j<= d.grade; j++) //divisor - dividendo * (termino nuevo del resultado)  //se itera sobre cada termino del divisor
            {
                r.coeficents[grade-i-j] -= (d.coeficents[d.grade-j]*res.coeficents[res.grade-i]);
            }
        i++; //actualizacion del pibote
        };
    }
    return res;
}

Polinom Polinom:: operator% (const Polinom &d) //&d = divisor
{
    Polinom r(*this); //dividendo
    Polinom res;
    if((d.coeficents != NULL and (d.grade != 0 or d.coeficents[0] != 0))) //compruevo que mi divisor no sea el polinomio nulo
    {
        if(grade >= d.grade)
        {
            res.grade = grade-d.grade;
            delete(res.coeficents);
            res.coeficents = new float[res.grade];
        }
        int i = 0; //pivote para la division
        while ( (r != 0) and ((r.grade-i) >= d.grade)) // condiciones para finalizar la division (resto 0 o dividendo de menor orden que el divisor)
        {
            res.coeficents[res.grade - i] = r.coeficents[grade-i]/d.coeficents[d.grade]; // calculo un nuevo termino del polinomio resultado
            for(int j = 0; j<= d.grade; j++) //divisor - dividendo * (termino nuevo del resultado)  //se itera sobre cada termino del divisor
            {
                r.coeficents[grade-i-j] -= (d.coeficents[d.grade-j]*res.coeficents[res.grade-i]);
            }
        i++; //actualizacion del pibote
        };

        for(int j= r.grade; j>=0; j--) //limpieza de ceros y actualizacion del grade de r
        {
            if(r.coeficents[j] != 0)
            {
                float* aux = new float[j];
                r.grade = j;
                for(int k=0; k<=j; k++) 
                {
                    aux[k] = r.coeficents[k];
                }
                delete(r.coeficents);
                r.coeficents = new float[r.grade];
                for(int k = 0; k<= r.grade; k++)
                {
                    r.coeficents[k] = aux[k];
                }
                delete(aux);
                break;
            }else if(j == 0)
            {
                r.grade = 0;
                delete(r.coeficents);
                r.coeficents = new float[0];
                r.coeficents[0] = 0;
            }
        }
    }
    return r;
}
Polinom::~Polinom()
{
    delete(coeficents);
}


#endif