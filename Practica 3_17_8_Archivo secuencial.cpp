#include <iostream>
using std ::cerr;
using std ::cin;
using std ::cout;
using std ::endl;
using std ::fixed;
using std ::ios;
using std ::left;
using std ::right;
using std ::showpoint;

#include <fstream>
using std::ifstream;

#include <iomanip>
using std ::setprecision;
using std ::setw;

#include <string>
using std ::string;

#include <cstdlib>
using std ::exit;

enum TipoSolicitud
{
    SALDO_CERO = 1,
    SALDO_CREDITO,
    SALDO_DEBITO,
    TERMINAR
};
int obtenerSolicitud();
bool debeMostrar(int, double);
void imprimirLinea(int, const string, double);
void imprimirLinea(int, const string, double);

int main()
{
    ifstream archivoClientesEntrada("clientes.dat", ios::in);

    if (!archivoClientesEntrada)
    {
        cerr << "No se pudo abrir el archivo" << endl;
        exit(1);
    }

    int cuenta;
    char nombre[30];
    double saldo;

    cout << left << setw(10) << "Cuenta" << setw(13) << "Nombre" << "Saldo" << endl
         << fixed << showpoint;

    while (archivoClientesEntrada >> cuenta >> nombre >> saldo)
    {
        imprimirLinea(cuenta, nombre, saldo);
    }
    return 0;
}

void imprimirLinea(int cuenta, const string nombre, double saldo)
{
    cout << left << setw(10) << cuenta << setw(13) << nombre << setw(7) << setprecision(2) << right << saldo << endl;
}
