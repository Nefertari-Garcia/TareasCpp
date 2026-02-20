// Rocio Nefertari Garcia Luevano
// 28/01/2026

#include <iostream>
#include <iomanip>

using namespace std;
#define MAX 80

template <class T>
class Calificaciones
{
private:
    T Datos[MAX];
    int Tam;

public:
    Calificaciones();
    void IngresarCalificaciones();
    void ImprimirCalificaciones();
    T ObtenerCalificacionMasAlta();
    T ObtenerCalificacionMasBaja();
    int ContarMenoresA6();
    int ContarMayoresA8_5();
    T ObtenerPromedio();
};


template <class T>
Calificaciones<T>::Calificaciones()
{
    Tam = 0;
}


template <class T>
void Calificaciones<T>::IngresarCalificaciones()
{
    do
    {
        cout << "\n Ingrese total de calificaciones (1-" << MAX << "): ";
        cin >> Tam;
    } while (Tam < 1 || Tam > MAX);

    cout << "\n Ingrese las calificaciones (0.0 - 10.0):\n";
    for (int i = 0; i < Tam; i++)
    {
        do
        {
            cout << " Calificacion " << (i + 1) << ": ";
            cin >> Datos[i];
        } while (Datos[i] < 0.0 || Datos[i] > 10.0);
    }
    cout << "\n Calificaciones ingresadas exitosamente!\n";
}


template <class T>
void Calificaciones<T>::ImprimirCalificaciones()
{
    if (Tam == 0)
    {
        cout << "\n No hay calificaciones para mostrar.\n";
        return;
    }

    cout << "\n CALIFICACIONES REGISTRADAS:\n";
    for (int i = 0; i < Tam; i++)
    {
        cout << " [" << setw(2) << (i + 1) << "] " << fixed << setprecision(1) << Datos[i] << endl;
    }
}


template <class T>
T Calificaciones<T>::ObtenerCalificacionMasAlta()
{
    if (Tam == 0)
        return 0;

    T maxima = Datos[0];
    for (int i = 1; i < Tam; i++)
    {
        if (Datos[i] > maxima)
            maxima = Datos[i];
    }
    return maxima;
}


template <class T>
T Calificaciones<T>::ObtenerCalificacionMasBaja()
{
    if (Tam == 0)
        return 0;

    T minima = Datos[0];
    for (int i = 1; i < Tam; i++)
    {
        if (Datos[i] < minima)
            minima = Datos[i];
    }
    return minima;
}


template <class T>
int Calificaciones<T>::ContarMenoresA6()
{
    int contador = 0;
    for (int i = 0; i < Tam; i++)
    {
        if (Datos[i] < 6.0)
            contador++;
    }
    return contador;
}


template <class T>
int Calificaciones<T>::ContarMayoresA8_5()
{
    int contador = 0;
    for (int i = 0; i < Tam; i++)
    {
        if (Datos[i] > 8.5)
            contador++;
    }
    return contador;
}


template <class T>
T Calificaciones<T>::ObtenerPromedio()
{
    if (Tam == 0)
        return 0;

    T suma = 0;
    for (int i = 0; i < Tam; i++)
    {
        suma += Datos[i];
    }
    return suma / Tam;
}

char MenuOpciones()
{
    char Opcion;
    cout << "\n";
    cout << " ========================================\n";
    cout << "    MENU - SISTEMA DE CALIFICACIONES\n";
    cout << " ========================================\n";
    cout << " 1. Ingresar las calificaciones\n";
    cout << " 2. Imprimir las calificaciones\n";
    cout << " 3. Mostrar calificacion mas alta\n";
    cout << " 4. Mostrar calificacion mas baja\n";
    cout << " 5. Imprimir total de calificaciones menores a 6\n";
    cout << " 6. Imprimir total de calificaciones mayores a 8.5\n";
    cout << " 7. Salir\n";
    cout << " ========================================\n";
    cout << " ELIGE TU OPCION: ";
    cin >> Opcion;
    return Opcion;
}

int main()
{
    Calificaciones<float> miGrupo;
    char opcion;
    bool continuar = true;

    cout << "\n BIENVENIDO AL SISTEMA DE CALIFICACIONES\n";

    while (continuar)
    {
        opcion = MenuOpciones();

        switch (opcion)
        {
        case '1':
            miGrupo.IngresarCalificaciones();
            break;

        case '2':
            miGrupo.ImprimirCalificaciones();
            break;

        case '3':
        {
            float maxima = miGrupo.ObtenerCalificacionMasAlta();
            cout << "\n La calificacion mas alta es: " << fixed << setprecision(1) << maxima << endl;
            break;
        }

        case '4':
        {
            float minima = miGrupo.ObtenerCalificacionMasBaja();
            cout << "\n La calificacion mas baja es: " << fixed << setprecision(1) << minima << endl;
            break;
        }

        case '5':
        {
            int total = miGrupo.ContarMenoresA6();
            cout << "\n Total de calificaciones menores a 6: " << total << endl;
            break;
        }

        case '6':
        {
            int total = miGrupo.ContarMayoresA8_5();
            cout << "\n Total de calificaciones mayores a 8.5: " << total << endl;
            break;
        }

        case '7':
        {
            float promedio = miGrupo.ObtenerPromedio();
            cout << "\n ====================================\n";
            cout << " RESUMEN FINAL:\n";
            cout << " ====================================\n";
            cout << " Calificacion mas alta: " << fixed << setprecision(1) << miGrupo.ObtenerCalificacionMasAlta() << endl;
            cout << " Calificacion mas baja: " << miGrupo.ObtenerCalificacionMasBaja() << endl;
            cout << " Promedio: " << setprecision(2) << promedio << endl;
            cout << " ====================================\n";
            cout << "\n Gracias por usar el sistema. Adios!\n";
            continuar = false;
            break;
        }

        default:
            cout << "\n Opcion invalida. Por favor, elige una opcion del 1 al 7.\n";
            break;
        }
    }

    return 0;
}