// Garcia Luevano Rocio Nefertari
// Ragknos Demian Fernandez Agraz Rodriguez
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <sstream>
using namespace std;
// Esta seria la parte 1: Crear el archivo deportistas.txt
void crearArchivo()
{
    ofstream archivoSalida("deportistas.txt");
    if (!archivoSalida)
    {
        cerr << "No se pudo abrir el archivo para escritura." << endl;
        return;
    }
    string datos[][3] = {
        {"Dana", "7", "Taekwondo"},
        {"Luis", "46", "Futbol"},
        {"Laura", "36", "Basquetbol"},
        {"Jose", "39", "Futbol"},
        {"Luz", "37", "Volibol"},
        {"Francisco", "42", "Futbol"},
        {"Katia", "42", "Tenis"},
        {"Felipe", "6", "Natacion"},
        {"Goretti", "10", "Volibol"},
        {"Arturo", "67", "Futbol"}};
    for (int i = 0; i < 10; i++)
    {
        archivoSalida << datos[i][0] << " "
                      << datos[i][1] << " "
                      << datos[i][2] << "\n";
    }
    archivoSalida.close();
    cout << "\nArchivo 'deportistas.txt' creado\n";
}
// PARTE 2: Mostrar deportistas filtrados por edad
void mostrarEncabezado(const string &titulo)
{
    cout << "\n---------------------------------------------\n";
    cout << "  " << titulo << "\n";
    cout << "---------------------------------------------\n";
    cout << left
         << setw(15) << "NOMBRE"
         << setw(8) << "EDAD"
         << setw(15) << "DEPORTE" << "\n";
}
void mostrarPorRango(int edadMin, int edadMax, const string &titulo)
{
    ifstream archivoEntrada("deportistas.txt");
    if (!archivoEntrada)
    {
        cerr << "No se pudo abrir el archivo 'deportistas.txt'." << endl;
        return;
    }
    mostrarEncabezado(titulo);
    string nombre, deporte;
    int edad;
    bool encontrado = false;
    while (archivoEntrada >> nombre >> edad >> deporte)
    {
        if (edad >= edadMin && edad <= edadMax)
        {
            cout << left
                 << setw(15) << nombre
                 << setw(8) << edad
                 << setw(15) << deporte << "\n";
            encontrado = true;
        }
    }
    if (!encontrado)
    {
        cout << "  (No se encontraron deportistas en este rango)\n";
    }
    cout << "---------------------------------------------\n";
    archivoEntrada.close();
}
void mostrarMenu()
{
    cout << "\n=============================================\n";
    cout << "       Deportistas Jaliscienses\n";
    cout << "=============================================\n";
    cout << "  1.- Mostrar deportistas menores de edad (5-17)\n";
    cout << "  2.- Mostrar deportistas mayores de edad (18-59)\n";
    cout << "  3.- Mostrar deportistas adultos mayores (60-85)\n";
    cout << "  4.- Salir\n";
    cout << "=============================================\n";
    cout << "Elige tu opcion: ";
}
int main()
{
    crearArchivo();
    int opcion;
    do
    {
        mostrarMenu();
        cin >> opcion;
        switch (opcion)
        {
        case 1:
            mostrarPorRango(5, 17, "DEPORTISTAS MENORES DE EDAD");
            break;
        case 2:
            mostrarPorRango(18, 59, "DEPORTISTAS MAYORES DE EDAD");
            break;
        case 3:
            mostrarPorRango(60, 85, "DEPORTISTAS ADULTOS MAYORES");
            break;
        case 4:
            cout << "\nSaliendo del programa.\n\n";
            break;
        default:
            cout << "\nOpcion invalida.\n";
            break;
        }
    } while (opcion != 4);
    return 0;
}