// Rocio Nefertari Garcia Luevano
// 28/01/2026

#include <iostream>
#include <stdio.h>

using namespace std;
#define MAX 80
#define N 20

char MenuOpciones()
{
    char Opcion;
    do
    {
        cout << "\n\n 1. Ingresar las calificaciones: ";
        cout << "\n\n 2. Imprimir las calificaciones: ";
        cout << "\n\n 3. Mostrar las calificacion mas alta: ";
        cout << "\n\n 4. Mostrar las calificacion mas baja: ";
        cout << "\n\n 5. Imprimir total de calificaciones menores a 6: ";
        cout << "\n\n 6. Imprimir total de calificaciones mayores a 8.5: ";
        cout << "\n\n 7. Salir: ";
        cout << "\n\n ELIGE TU OPCION: ";
    } while (Opcion != 1 && Opcion != 2 && Opcion != 3 && Opcion != 4 && Opcion != 5 && Opcion != 6 && Opcion != 7);
}