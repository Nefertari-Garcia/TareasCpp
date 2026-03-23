#include <iostream>
 using std::cerr;
 using std::cin;
 using std::cout;
 using std::endl;
 using std::ios;

#include <fstream> // flujo de archivo
using std::ofstream; // flujo de archivo de salida

#include <cstdlib>
using std::exit; // prototipo de la función exit

int main()
{
// el constructor de ofstream abre el archivo
ofstream archivoClientesSalida( "clientes.dat", ios::out );

// sale del programa si no puede crear el archivo
if ( !archivoClientesSalida ) // operador ! sobrecargado
{
cerr << "No se pudo abrir el archivo" << endl;
 exit( 1 );
 } // fin de if

 cout << "Escriba la cuenta, nombre y saldo." << endl
 << "Escriba fin de archivo para terminar la entrada.\n? ";

 int cuenta;
 char nombre[ 30 ];
 double saldo;

 // lee la cuenta, nombre y saldo de cin, y después los coloca en el archivo
 while ( cin >> cuenta >> nombre >> saldo )
 {
 archivoClientesSalida << cuenta << ' ' << nombre << ' ' << saldo << endl;
 cout << "? ";
 } // fin de while

 return 0; // el destructor de ofstream cierra el archivo
 } // fin de main
