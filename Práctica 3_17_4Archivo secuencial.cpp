#include <iostream>
using std::cerr;
using std ::cin;
using std ::cout;
using std ::endl;
using std ::ios;

#include <fstream>
using std ::ofstream;

#include <cstdlib>
using std ::exit;

int main()
{
    ofstream archivoClientesSalida("clientes.dat", ios::out);

    if (!archivoClientesSalida)
    {
        cerr << "No se pudo abrir el archivo" << endl;
        exit(1);
    }

    cout << "Escriba la cuenta, nombre y saldo." << endl
         << "Escriba fin de archivo para terminar la entrada. \n";
    int cuenta;
    char nombre[30];
    double saldo;

    while (cin >> cuenta >> nombre >> saldo)
    {
        archivoClientesSalida << cuenta << ' ' << nombre << ' ' << saldo << endl;
        cout << "? ";
    }
}