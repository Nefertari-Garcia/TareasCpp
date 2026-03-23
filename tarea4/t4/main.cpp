#include "main.h"

#define MAX 100
template <class T>
class Arreglo
{
private:
T Datos[MAX];
int Tam;
public:
Arreglo();
int RegresaTam();
T RegresaValor(int);
void AsignaValor(int, T);
void Intercambia(int, int);
void IntercDirectoIzq();
void InsercionDirecta();
void SeleccionDirecta();
void QuickSort();
void Reduce(int, int);
void Lectura();
void Escribe();
};
/* Declaración del método constructor. Inicializa el número actual de
➥elementos en 0. */
template <class T>
Arreglo<T>::Arreglo()
{
Tam=0;
}
/* Método auxiliar que intercambia los contenidos de dos elementos del
➥arreglo. */
template <class T>
void Arreglo<T>::Intercambia(int Ind1, int Ind2)
{
T Auxiliar;
Auxiliar= Datos[Ind1];
Datos[Ind1]= Datos[Ind2];
Datos[Ind2]= Auxiliar;
}
/* Método que ordena los elementos del arreglo usando el algoritmo de
➥intercambio directo con desplazamiento del elemento más pequeño hacia
➥el extremo izquierdo. */
template <class T>
void Arreglo<T>::IntercDirectoIzq()
{
int Ind1, Ind2;
for (Ind1= 1; Ind1< Tam; Ind1++)
for (Ind2= Tam-1; Ind2 >= Ind1; Ind2––)
if (Datos[Ind2-1] > Datos[Ind2])
Intercambia(Ind2-1, Ind2);

}
/* Método que ordena los elementos del arreglo usando el algoritmo de
➥inserción directa. */
template <class T>
void Arreglo<T>::InsercionDirecta()
{
int Auxiliar, Indice, IndAux;
for (Indice= 1; Indice < Tam; Indice++)
{
Auxiliar= Datos[Indice];
IndAux= Indice - 1;
while ((IndAux >= 0) && (Auxiliar < Datos[IndAux]))
{
Datos[IndAux+1]= Datos[IndAux];
IndAux––;
}
Datos[IndAux+1]= Auxiliar;
}
}
/* Este método ordena los elementos del arreglo utilizando el algoritmo
➥de selección directa. */
template <class T>
void Arreglo<T>::SeleccionDirecta()
{
int Menor, Ind1, Ind2, Ind3;
for (Ind1= 0; Ind1 < Tam-1; Ind1++)
{
Menor= Datos[Ind1];
Ind2= Ind1;
for (Ind3= Ind1+1; Ind3 < Tam; Ind3++)
if (Datos[Ind3] < Menor)
{
Menor= Datos[Ind3];
Ind2= Ind3;
}
Datos[Ind2]= Datos[Ind1];
Datos[Ind1]= Menor;
}
}

template <class T>
void Arreglo<T>::QuickSort()
{
Reduce(0, Tam-1);
}
/* Método auxiliar del algoritmo QuickSort. Las parámetros Inicio y Fin
➥representan los extremos del intervalo en el cual se está ordenando. */
template <class T>
void Arreglo<T>::Reduce(int Inicio, int Fin)
{
if ( Tam > 0)
{
int Izq, Der, Posic, Bandera;
Izq= Inicio;
Der= Fin;
Posic= Inicio;
Bandera= 1;
while (Bandera)
{
Bandera= 0;
while ((Datos[Posic] <= Datos[Der]) && (Posic != Der))
Der––;
if (Posic != Der)
{
Intercambia(Posic, Der);
Posic= Der;
while ((Datos[Posic] >= Datos[Izq]) && (Posic != Izq))
Izq++;
if (Posic != Izq)
{
Bandera=1;
Intercambia(Posic, Izq);
Posic= Izq;
}
}
}
if ((Posic-1) > Inicio)
Reduce(Inicio, Posic-1);
if (Fin > (Posic+1))
Reduce(Posic+1, Fin);
}
}
