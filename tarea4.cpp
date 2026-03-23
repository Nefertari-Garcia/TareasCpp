#include <stdio.h>
#include <iostream>
#include <clocale>
// #include <windows.h>

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
    int RegresaTam();
    T RegresaValor(int);
    void AsignaValor(int, T);
    void Intercambia(int, int);
    void IntercDirectoIzq();
    void InsercionDirecta();
    void SeleccionDirecta();
    void QuickSort();
    void Demian_quickSort(int, int);
    void Nefertari_SeleccionDirecta();
    void Reduce(int, int);
    void Lectura();
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
        cout << "\n\n Ingrese total de elementos: " << endl;
        cin >> Tam;
    } while (Tam < 1 || Tam > MAX);
    for (Indice = 0; Indice < Tam; Indice++)
    {
        cout << "\nIngrese el " << Indice + 1 << " dato: ";
        cin >> Datos[Indice];
    }
}

template <class T>
void Arreglo<T>::Escribe()
{
    int Indice;
    if (Tam > 0)
    {
        cout << "\n\n";
        for (Indice = 0; Indice < Tam; Indice++)
            cout << '\t' << Datos[Indice];
        cout << "\n\n";
    }
    else
        cout << "\n No hay elementos almacenados.";
}

template <class T>
void Arreglo<T>::AsignaValor(int pos, T valor)
{
    if (pos < MAX)
    {
        if (pos >= Tam)
            Tam = pos + 1;
        Datos[pos] = valor;
    }
}

template <class T>
T Arreglo<T>::RegresaValor(int pos)
{
    if (pos < Tam)
        return Datos[pos];
    return 0;
}

template <class T>
int Arreglo<T>::RegresaTam()
{
    return Tam;
}

template <class T>
void Arreglo<T>::Intercambia(int Ind1, int Ind2)
{
    T Auxiliar;
    Auxiliar = Datos[Ind1];
    Datos[Ind1] = Datos[Ind2];
    Datos[Ind2] = Auxiliar;
}

template <class T>
void Arreglo<T>::IntercDirectoIzq()
{
    int Ind1, Ind2;
    for (Ind1 = 1; Ind1 < Tam; Ind1++)
    {
        for (Ind2 = Tam - 1; Ind2 >= Ind1; Ind2--)
        {

            if (Datos[Ind2 - 1] > Datos[Ind2])
                Intercambia(Ind2 - 1, Ind2);
        }
    }
}

template <class T>
void Arreglo<T>::InsercionDirecta()
{
    int Auxiliar, Indice, IndAux;
    for (Indice = 1; Indice < Tam; Indice++)
    {
        Auxiliar = Datos[Indice];
        IndAux = Indice - 1;
        while ((IndAux >= 0) && (Auxiliar < Datos[IndAux]))
        {
            Datos[IndAux + 1] = Datos[IndAux];
            IndAux--;
        }
        Datos[IndAux + 1] = Auxiliar;
    }
}
/* Este método ordena los elementos del arreglo utilizando el algoritmo
➥de selección directa. */
template <class T>
void Arreglo<T>::SeleccionDirecta()
{
    int Menor, Ind1, Ind2, Ind3;
    for (Ind1 = 0; Ind1 < Tam - 1; Ind1++)
    {
        Menor = Datos[Ind1];
        Ind2 = Ind1;
        for (Ind3 = Ind1 + 1; Ind3 < Tam; Ind3++)
            if (Datos[Ind3] < Menor)
            {
                Menor = Datos[Ind3];
                Ind2 = Ind3;
            }
        Datos[Ind2] = Datos[Ind1];
        Datos[Ind1] = Menor;
    }
}

template <class T>
void Arreglo<T>::QuickSort()
{
    Reduce(0, Tam - 1);
}
/* Método auxiliar del algoritmo QuickSort. Las parámetros Inicio y Fin
➥representan los extremos del intervalo en el cual se está ordenando. */
template <class T>
void Arreglo<T>::Reduce(int Inicio, int Fin)
{
    if (Tam > 0)
    {
        int Izq, Der, Posic, Bandera;
        Izq = Inicio;
        Der = Fin;
        Posic = Inicio;
        Bandera = 1;
        while (Bandera)
        {
            Bandera = 0;
            while ((Datos[Posic] <= Datos[Der]) && (Posic != Der))
                Der--;
            if (Posic != Der)
            {
                Intercambia(Posic, Der);
                Posic = Der;
                while ((Datos[Posic] >= Datos[Izq]) && (Posic != Izq))
                    Izq++;
                if (Posic != Izq)
                {
                    Bandera = 1;
                    Intercambia(Posic, Izq);
                    Posic = Izq;
                }
            }
        }
        if ((Posic - 1) > Inicio)
            Reduce(Inicio, Posic - 1);
        if (Fin > (Posic + 1))
            Reduce(Posic + 1, Fin);
    }
}

template <class T>
void Arreglo<T>::Demian_quickSort(int izq, int der)
{
    if (izq >= der)
    {
        return;
    }

    int i = izq, j = der;
    int pivote = Datos[(izq + der) / 2];
    int temp;

    while (i <= j)
    {
        while (Datos[i] < pivote)
            i++;
        while (Datos[j] > pivote)
            j--;
        if (i <= j)
        {
            temp = Datos[i];
            Datos[i] = Datos[j];
            Datos[j] = temp;
            i++;
            j--;
        }
    }
    if (izq < j)
        Demian_quickSort(izq, j);
    if (i < der)
        Demian_quickSort(i, der);
}

template <class T>
void Arreglo<T>::Nefertari_SeleccionDirecta()
{
    int Mayor, Ind1, Ind2, Ind3;
    for (Ind1 = 0; Ind1 < Tam - 1; Ind1++)
    {
        Mayor = Datos[Ind1];
        Ind2 = Ind1;
        for (Ind3 = Ind1 + 1; Ind3 < Tam; Ind3++)
            if (Datos[Ind3] > Mayor)
            {
                Mayor = Datos[Ind3];
                Ind2 = Ind3;
            }
        Datos[Ind2] = Datos[Ind1];
        Datos[Ind1] = Mayor;
    }
}

int main()
{
    setlocale(LC_CTYPE, "Spanish");

    Arreglo<int> arr;
    int opcion;
    int llenarAr[10];
    cout << "MENÚ - MÉTODOS DE ORDENAMIENTO" << endl;
    cout << "- 1. Llenar el arreglo (10 números enteros)\n- 2. Mostrar el arreglo\n- 3. Metodo Intercambio directo por la izquierda\n- 4. Método Inserción directa\n- 5. Método Selección directa\n- 6. Método QuickSort\n- 7. Método elegido NEFERTARI.\n- 8. Método elegido DEMIAN.\n- 0. Salir\n " << endl;
    cout << "Elije una opcion \n"
         << endl;
    cin >> opcion;

    do
    {
        switch (opcion)
        {
        case 1:
            for (int i = 0; i < 10; i++)
            {
                cout << "Ingrese número " << i + 1 << ": ";
                cin >> llenarAr[i];
                arr.AsignaValor(i, llenarAr[i]);
            }
            break;
        case 2:
            cout << "Números ingresados: \n";
            arr.Escribe();
            break;
        case 3:
            arr.IntercDirectoIzq();
            arr.Escribe();
            cout << "Ordenado con Intercambio directo\n"
                 << endl;
            break;
        case 4:
            arr.InsercionDirecta();
            arr.Escribe();
            cout << "Ordenado con Inserción directa\n"
                 << endl;
            break;
        case 5:
            arr.SeleccionDirecta();
            arr.Escribe();
            cout << "Ordenado con Selección directa\n"
                 << endl;
            break;
        case 6:
            arr.QuickSort();
            arr.Escribe();
            cout << "Ordenado con QuickSort\n"
                 << endl;
            break;
        case 7:
            arr.Nefertari_SeleccionDirecta();
            arr.Escribe();
            cout << "Ordenado con Nefertari\n"
                 << endl;
            break;
        case 8:
            arr.Demian_quickSort(0, 4);
            arr.Escribe();
            cout << "Ordenado con Demian QuickSort\n"
                 << endl;
            break;
        default:
            cout << "Opción no válida\n"
                 << endl;
            break;
        }
        cout << "MENÚ - MÉTODOS DE ORDENAMIENTO" << endl;
        cout << "- 1. Llenar el arreglo (10 números enteros)\n- 2. Mostrar el arreglo\n- 3. Metodo Intercambio directo por la izquierda\n- 4. Método Inserción directa\n- 5. Método Selección directa\n- 6. Método QuickSort\n- 7. Método elegido NEFERTARI.\n- 8. Método elegido DEMIAN.\n- 0. Salir\n " << endl;
        cout << "Elije una opcion \n"
             << endl;
        cin >> opcion;
    } while (opcion != 0);

    cout << "¡Hasta luego!" << endl;
    return 0;
}
