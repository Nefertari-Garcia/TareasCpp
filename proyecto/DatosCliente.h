#ifndef DATOSCLIENTE_H
#define DATOSCLIENTE_H

#include <string>
using std::string;

class DatosCliente
    {
    public:
    // constructor predeterminado de DatosCliente
    DatosCliente( int = 0, string = "", string = "", double = 0.0 );

    // funciones de acceso para numeroCuenta
    void establecerNumeroCuenta( int );
    int obtenerNumeroCuenta() const;

    // funciones de acceso para apellidoPaterno
    void establecerApellidoPaterno( string );
    string obtenerApellidoPaterno() const;

    // funciones de acceso para primerNombre
    void establecerPrimerNombre( string );
    string obtenerPrimerNombre() const;

    // funciones de acceso para el saldo
    void establecerSaldo( double );
    double obtenerSaldo() const;

    private:
    int numeroCuenta;
    char apellidoPaterno[ 15 ];
    char primerNombre[ 10 ];
    double saldo;
}; // fin de la clase DatosCliente
#endif
