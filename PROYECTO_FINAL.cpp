#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Vehiculo
{
protected:
    string color;
    string marca;
    string modelo;
    int anio;
    int ruedas;
    float precio;

public:
    Vehiculo()
    {
        color = "Gris";
        ruedas = 2;
    }

    virtual void mostrarInfo()
    {
        cout << "\n=== INFORMACION DEL VEHICULO ===\n";
        cout << "Marca: " << marca << endl;
        cout << "Modelo: " << modelo << endl;
        cout << "Año: " << anio << endl;
        cout << "Color: " << color << endl;
        cout << "Precio: $" << precio << endl;
    }

    virtual void probar() = 0;

    void setPrecio(float descuento, float p)
    {
        precio = p - (p * descuento / 100);
    }

    void setPrecio(string moneda, float p)
    {
        if (moneda == "USD")
        {
            precio = p * 17.5;
        }
        else
        {
            precio = p;
        }
    }
};

class Automovil : public Vehiculo
{
private:
    int numPuertas;

public:
    virtual void mostrarInfo()
    {
        Vehiculo::mostrarInfo();
        cout << "Numero de puertas: " << numPuertas << endl;
        cout << "\n=== INFORMACION DEL VEHICULO ===\n";
        cout << "Marca: " << marca << endl;
        cout << "Modelo: " << modelo << endl;
        cout << "Año: " << anio << endl;
        cout << "Color: " << color << endl;
        cout << "Precio: $" << precio << endl;
    }

    void probar() override
    {
        cout << "Probando Moto...\n";
        cout << "Arrancando motor...\n";
        cout << "APROBADO...";
    }

    void establecerPuertas(int p)
    {
        numPuertas = p;
        cout << "Puertas:  " << p << endl;
    }

    void establecerPuertas(int p, bool validar)
    {
        if (validar && (p < 2 || p > 5))
        {
            numPuertas = 4;
            cout << "ERROR ERROR ERROR " << endl;
        }
        else
        {
            numPuertas = p;
        }
    }

    void establecerPuertas(string tipo)
    {
        if (tipo == "Deportivo")
        {
            numPuertas = 2;
        }
        else if (tipo == "Sedan")
        {
            numPuertas = 4;
        }
        else if (tipo == "SUV")
        {
            numPuertas = 5;
        }
    }
};

class Moto : public Vehiculo
{
private:
    string tipoDeMoto;
    bool incluyeCasco;

public:
    Moto()
    {
        marca = "Italika";
        modelo = "WS 150 Sport";
        precio = 30000.0;
        color = "Amarilla";
        anio = 2022;
        tipoDeMoto = "Para ciudad";
        incluyeCasco = true;
    }

    void probar() override
    {
        cout << "Probando Moto...\n";
        cout << "Arrancando motor...\n";
        cout << "APROBADO...";
    }

    void mostrarInfo() override
    {
        cout << "\n=== INFORMACION DE LA MOTO ===\n";
        cout << "Marca: " << marca << endl;
        cout << "Modelo: " << modelo << endl;
        cout << "Año: " << anio << endl;
        cout << "Color: " << color << endl;
        cout << "Precio: $" << precio << endl;
        cout << "Tipo de Moto: " << tipoDeMoto << endl;
        cout << "Incluye Casco: " << (incluyeCasco ? "Si" : "No") << endl;
    }
};

class Camion : public Vehiculo
{
private:
    string tipoDeCamion;
    int pesoLimite;
    string tamanio;

public:
    Camion()
    {
        marca = "TVolvo Trucks";
        modelo = "camion rígido";
        precio = 33350000.0;
        color = "Verde";
        anio = 2025;
        pesoLimite = 50;
        tamanio = "Grande";
    }
    void probar() override
    {
        cout << "Probando Camion...\n";
        cout << "Arrancando motor...\n";
        cout << "APROBADO...";
    }

    void mostrarInfo() override
    {
        cout << "\n=== INFORMACION DEL CAMION ===\n";
        cout << "Marca: " << marca << endl;
        cout << "Modelo: " << modelo << endl;
        cout << "Año: " << anio << endl;
        cout << "Color: " << color << endl;
        cout << "Precio: $" << precio << endl;
        cout << "Peso Limite: " << pesoLimite << endl;
        cout << "Tamaño: " << tamanio << endl;
    }
};

class Carro : public Vehiculo
{
private:
    int numPuertas;
    string tipoDeCarro;
    bool cajuela;

public:
    Carro()
    {
        marca = "Toyota";
        modelo = "Corolla";
        precio = 350000.0;
        numPuertas = 4;
        color = "Rojo";
        anio = 2024;
        tipoDeCarro = "Deportivo";
        cajuela = true;
    }

    void establecerPuertas(int p)
    {
        numPuertas = p;
        cout << "Puertas:  " << p << endl;
    }

    void establecerPuertas(int p, bool validar)
    {
        if (validar && (p < 2 || p > 5))
        {
            numPuertas = 4;
            cout << "ERROR ERROR ERROR " << endl;
        }
        else
        {
            numPuertas = p;
        }
    }

    void probar() override
    {
        cout << "Probando carro...\n";
        cout << "Arrancando motor...\n";
        cout << "Revisando" << numPuertas << " puertas...\n";
        cout << "Probando las palancas .... \n";
    }

    void mostrarInfo() override
    {
        cout << "\n=== INFORMACION DEL CARRO ===\n";
        cout << "Marca: " << marca << endl;
        cout << "Modelo: " << modelo << endl;
        cout << "Año: " << anio << endl;
        cout << "Color: " << color << endl;
        cout << "Precio: $" << precio << endl;
        cout << "Tipo de Carro: " << tipoDeCarro << endl;
        cout << "Tiene cajuela: " << (cajuela ? "Si" : "No") << endl;
    }
};

int main()
{
    int opcionPrincipal;
    int subOpcion;

    do
    {
        cout << "=== TIENDA DE VEHICULOS ===" << endl;
        cout << "1. Carro\n2. Camion\n3. Moto \n0. Salir\n";
        cin >> opcionPrincipal;

        switch (opcionPrincipal)
        {
        case 1:
        {

            Carro carro1;
            int subOpcion;
            do
            {
                cout << "\n--- MENU CARRO ---\n";
                cout << "1. Probar\n2. Info\n3. Volver\n";
                cin >> subOpcion;

                switch (subOpcion)
                {
                case 1:
                {
                    carro1.probar();
                    break;
                }
                case 2:
                {
                    carro1.mostrarInfo();
                    break;
                }
                }
            } while (subOpcion != 3);
            break;
        }
        case 2:
        {
            Camion camion1;
            int subOpcion;
            do
            {
                cout << "\n--- MENU CAMION ---\n";
                cout << "1. Probar\n2. Info\n3. Volver\n";
                cin >> subOpcion;

                switch (subOpcion)
                {
                case 1:
                {
                    camion1.probar();
                    break;
                }
                case 2:
                {
                    camion1.mostrarInfo();
                    break;
                }
                }
            } while (subOpcion != 3);
            break;
        }
        case 3:
        {
            Moto moto1;
            int subOpcion;
            do
            {
                cout << "\n--- MENU MOTO ---\n";
                cout << "1. Probar\n2. Info\n3. Volver\n";
                cin >> subOpcion;

                switch (subOpcion)
                {
                case 1:
                {
                    moto1.probar();
                    break;
                }
                case 2:
                {
                    moto1.mostrarInfo();
                    break;
                }
                }
            } while (subOpcion != 3);
            break;
        }
        }

    } while (opcionPrincipal != 0);

    return 0;
}
