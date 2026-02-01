#include <stdio.h>
#include <iostream>

using namespace std;

class Fecha
{
private:
    int dia;
    int mes;
    int anyo;

public:
    Fecha(int d, int m, int an)
    {
        setDia(d);
        setMes(m);
        setAnyo(an);
    };

    void setDia(int d)
    {
        dia = d;
        
    };

    void setMes(int m)
    {
        mes = m;
    };

    void setAnyo(int an)
    {
        anyo = an;
    };
};