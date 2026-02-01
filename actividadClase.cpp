// La tarea se encuentra en el libro ORIENTADA A OBJETOS de PDF 147
// Rocio Nefertari Garcia Luevano
// 28/01/2026
#include <iostream>
#include <stdio.h>
// #include "PlanArreglo.h"
using namespace std;
#define MAX 100

template <class T>
class Arreglo
{
private:
    T Datos[MAX];
    int Tam;

public:
    Arreglo();
    void Lectura();
    int InsertaDesordenado(T);
    int EliminaDesordenado(T);
    int BuscaDesordenado(T);
    void Escribe();
};

template <class T>
Arreglo<T>::Arreglo()
{
    Tam = 0;
}

template <class T>
void Arreglo<T>::Lectura()
{
    int Indice;
    do
    {
        cout << "\n\n Ingrese total de elementos:     ";
        cin >> Tam;
    } while (Tam < 1 || Tam > MAX);
    for (Indice = 0; Indice < Tam; Indice++)
    {
        cout << "\nIngrese el " << Indice + 1 << "dato: ";
        cin >> Datos[Indice];
    }
}

template <class T>
int Arreglo<T>::InsertaDesordenado(T Valor)
{
    int Posic, Resultado = 1;
    if (Tam < MAX)
    {
        Posic = BuscaDesordenado(Valor);
        if (Posic < 0)
        {
            Datos[Tam++] = Valor;
        }
        else
        {
            Resultado = -1;
        }
    }
    else
    {
        Resultado = 0;
    }
    return Resultado;
}

template <class T>
int Arreglo<T>::EliminaDesordenado(T Valor)
{
    int Indice, Posic, Resultado = 1;
    if (Tam > 0)
    {
        Posic = BuscaDesordenado(Valor);
        if (Posic < 0)
        {
            Resultado = -1;
        }
        else
        {
            Tam--;
            for (Indice = Posic; Indice < Tam; Indice++)
            {
                Datos[Indice] = Datos[Indice + 1];
            }
        }
    }
    else
    {
        Resultado = 0;
    }
    return Resultado;
}

template <class T>
int Arreglo<T>::BuscaDesordenado(T Valor)
{
    int Indice = 0, Resultado = -1;
    while ((Indice < Tam) && (Datos[Indice] != Valor))
    {
        Indice++;
    }
    if (Indice < Tam)
    {
        Resultado = Indice;
    }
    return Resultado;
}

template <class T>
void Arreglo<T>::Escribe()
{
    int Indice;
    if (Tam > 0)
    {
        cout << "\n\n";
        for (Indice = 0; Indice < Tam; Indice++)
        {
            cout << '\t' << Datos[Indice];
            cout << "\n\n";
        }
    }
    else
    {
        cout << "\n No hay elementos almacenados.";
    }
}

///----------------------------------------------------------------------------
///----------------------------------------------------------------------------
///----------------------------------------------------------------------------
///----------------------------------------------------------------------------
///----------------------------------------------------------------------------
///----------------------------------------------------------------------------
///----------------------------------------------------------------------------

char MenuOpciones()
{
    char Opcion;
    do
    {
        cout << "\n\n\nL: Leer la lista de claves: ";
        cout << "\nA: Dar de alta de nuevo alumno: ";
        cout << "\nB: Dar de baja a alumno: ";
        cout << "\nI: Imprimir la lista de claves: ";
        cout << "\nF: Finalixar el proceso.";
        cout << "\n\nIngrese opcion de trabajo: ";
        cin >> Opcion;
    } while (Opcion != 'A' && Opcion != 'B' && Opcion != 'L' && Opcion != 'I' && Opcion != 'F');
    return Opcion;
}

int main()
{
    Arreglo<int> ClavAlum;
    int Clave, Res;
    char Opc;
    do
    {
        Opc = MenuOpciones();
        switch (Opc)
        {
        case 'L':
        {
            ClavAlum.Lectura();
            break;
        }

        case 'I':
        {
            ClavAlum.Escribe();
            break;
        }
        case 'A':
        {
            cout << "\n\n Clave del nuevo alumno:  ";
            cin >> Clave;
            Res = ClavAlum.InsertaDesordenado(Clave);
            if (Res == 1)
            {
                cout << "\n\n Clave del nuevo alumno: ";
                cin >> Clave;
                Res = ClavAlum.InsertaDesordenado(Clave);
                if (Res == 1)
                {
                    cout << "\n\n El nuevo alumno ya fue dado de alta. ";
                }
                else if (Res == 0)
                {
                    cout << "\n\n No hay espacio para registrar el nuevo alumno. ";
                }
                else
                {
                    cout << "\n\n Esa clave ya fue registrada previamente. ";
                }
            }
            break;
        }
        case 'B':
        {
            cout << "\n\n Clave del alumno a dar de baja: ";
            cin >> Clave;
            Res = ClavAlum.EliminaDesordenado(Clave);
            if (Res == 1)
            {
                cout << "\n\n El alumno ya fue dado de baja. ";
            }
            else if (Res == 0)
            {
                cout << "\n\n No hay alumnos registrados.    ";
            }
            else
            {
                cout << "\n\n Esa clabe no esta registrada.   ";
            }
            break;
        }
        case 'F':
        {
            cout << "\n\n Terminar el proceso.\n\n";
            break;
        }
        }
    } while (Opc != 'F');
}