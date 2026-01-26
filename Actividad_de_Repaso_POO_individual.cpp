#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

class Cuenta_Bancaria
{
private:
    string num_cuenta;
    string propetario;
    double saldo;

public:
    Cuenta_Bancaria(string nc, string p, double s)
    {
        asignarNumCuenta(nc);
        asignarPropetario(p);
        asignarSaldo(s);
    };

    void asignarPropetario(string p)
    {
        propetario = p;
    };

    void asignarNumCuenta(string nc)
    {
        num_cuenta = nc;
    };

    void asignarSaldo(double s)
    {
        saldo = s;
    };

    double obteneSaldo()
    {
        return saldo;
    };

    void deposito(double s)
    {
        saldo += s;
    };

    void retirar(double r)
    {
        if (r <= saldo)
        {
            saldo -= r;
        }
        else
        {
            cout << "No es posible hacer el retiro de la cantidad solicitado" << std::endl;
        }
    };

    string obtenerNumCuenta()
    {
        return num_cuenta;
    }
    // int getsaldo()
};

int main()
{
    vector<Cuenta_Bancaria> cuentas_B =
        {
            Cuenta_Bancaria("12345", "Claudia Arroyo", 10650.85),
            Cuenta_Bancaria("54321", "Miguel Lomeli", 7800.99)};

    int opcion;

    do
    {
        cout << "\n\n------------- CUENTA DE BANCO -------------\n"
             << endl;
        cout << "Que desea realizar hoy:\n"
             << endl;
        cout << "1) Deposito\n"
             << endl;
        cout << "2) Retirar\n"
             << endl;
        cout << "3) Saldo actual\n"
             << endl;
        cout << "4) Salir\n"
             << endl;
        cin >> opcion;
        string ing_numC;
        double ingreso;
        bool encontrado;
        switch (opcion)
        {
        case 1:
        {
            cout << "\n\n------------- DEPOSITO -------------\n"
                 << endl;
            cout << "Ingrese su numero de cuenta:\n"
                 << endl;
            cin >> ing_numC;
            encontrado = false;
            for (auto &cuenta : cuentas_B)
            {
                if (ing_numC == cuenta.obtenerNumCuenta())
                {
                    cout << "Cuanto vas a ingresar: ";
                    cin >> ingreso;
                    cuenta.deposito(ingreso);
                    cout << "Tu nuevo saldo es: $" << cuenta.obteneSaldo() << endl;
                    encontrado = true;
                    break;
                }
            }
            if (!encontrado)
            {
                cout << "No se encontro tu cuenta" << endl;
            }
            break;
        }

        case 2:
        {
            cout << "\n\n------------- RETIRAR -------------\n"
                 << endl;
            cout << "Ingrese su numero de cuenta:\n"
                 << endl;
            cin >> ing_numC;
            encontrado = false;
            for (auto &cuenta : cuentas_B)
            {
                if (ing_numC == cuenta.obtenerNumCuenta())
                {
                    cout << "Cuanto vas a retirar: ";
                    cin >> ingreso;
                    cuenta.retirar(ingreso);
                    cout << "Tu nuevo saldo es: $" << cuenta.obteneSaldo() << endl;
                    encontrado = true;
                    break;
                }
            }
            if (!encontrado)
            {
                cout << "No se encontro tu cuenta" << endl;
            }
            break;
        }
        case 3:
        {
            cout << "\n\n------------- SALDO ACTUAL -------------\n"
                 << endl;
            cout << "Ingrese su numero de cuenta:\n"
                 << endl;
            cin >> ing_numC;
            encontrado = false;
            for (auto &cuenta : cuentas_B)
            {
                if (ing_numC == cuenta.obtenerNumCuenta())
                {
                    cout << "Tu saldo es: $" << cuenta.obteneSaldo() << endl;
                    encontrado = true;
                    break;
                }
            }
            if (!encontrado)
            {
                cout << "No se encontro tu cuenta" << endl;
            }
            break;
        }

        case 4:
        {

            cout << "Hasta luego" << endl;
            break;
        }

        default:
            cout << "Opcion incorrecta, vuelve a ingresar una opcion" << endl;
            break;
        }
    } while (opcion != 4);
    return 0;
}