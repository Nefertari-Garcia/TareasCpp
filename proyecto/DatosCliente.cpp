#include <string>
#include <string.h>
using std::string;

#include "DatosCliente.h"

// constructor predeterminado de DatosCliente
DatosCliente::DatosCliente( int valorNumeroCuenta,
string valorApellidoPaterno, string valorPrimerNombre, double valorSaldo )
 {
    establecerNumeroCuenta( valorNumeroCuenta );
    establecerApellidoPaterno( valorApellidoPaterno );
    establecerPrimerNombre( valorPrimerNombre );
    establecerSaldo( valorSaldo );
 } // fin del constructor de DatosCliente

 // obtiene el valor del número de cuenta
 int DatosCliente::obtenerNumeroCuenta() const
 {
 return numeroCuenta;
 } // fin de la función obtenerNumeroCuenta

 // establece el valor del número de cuenta
 void DatosCliente::establecerNumeroCuenta( int valorNumeroCuenta )
 {
 numeroCuenta = valorNumeroCuenta; // debe validar
 } // fin de la función establecerNumeroCuenta

// obtiene el valor del apellido paterno
string DatosCliente::obtenerApellidoPaterno() const
{
return apellidoPaterno;
} // fin de la función obtenerApellidoPaterno

// establece el valor del apellido paterno
void DatosCliente::establecerApellidoPaterno( string cadenaApellidoPaterno )
{
// copia a lo más 15 caracteres de la cadena a apellidoPaterno
const char *valorApellidoPaterno = cadenaApellidoPaterno.data();
int longitud = cadenaApellidoPaterno.size();
longitud = ( longitud < 15 ? longitud : 14 );
strncpy( apellidoPaterno, valorApellidoPaterno, longitud );
apellidoPaterno[ longitud ] = '\0'; // adjunta un carácter nulo a apellidoPaterno
} // fin de la función establecerApellidoPaterno

// obtiene el valor del primer nombre
string DatosCliente::obtenerPrimerNombre() const
{
return primerNombre;
} // fin de la función obtenerPrimerNombre

// establece el valor del primer nombre
void DatosCliente::establecerPrimerNombre( string cadenaPrimerNombre )
{
// copia a lo más 10 caracteres de la cadena a primerNombre
const char *valorPrimerNombre = cadenaPrimerNombre.data();
int longitud = cadenaPrimerNombre.size();
longitud = ( longitud < 10 ? longitud : 9 );
strncpy( primerNombre, valorPrimerNombre, longitud );
primerNombre[ longitud ] = '\0'; // adjunta un carácter nulo a primerNombre
} // fin de la función establecerPrimerNombre
