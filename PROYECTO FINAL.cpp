#include <iostream>
#include <string>
#include <vector>
#include <limits>
using namespace std;

// ==================== CLASE TIENDA ====================
class Tienda
{
private:
    string tiendaID;
    string tiendaDireccion;

public:
    Tienda(string id, string direccion) : tiendaID(id), tiendaDireccion(direccion) {}

    string getTiendaID() const { return tiendaID; }
    string getTiendaDireccion() const { return tiendaDireccion; }

    void mostrarInfoTienda()
    {
        cout << "\n╔════════════════════════════════════╗\n";
        cout << "║     INFORMACION DE LA TIENDA       ║\n";
        cout << "╚════════════════════════════════════╝\n";
        cout << "ID: " << tiendaID << endl;
        cout << "Direccion: " << tiendaDireccion << endl;
    }
};

// ==================== CLASE TRABAJADOR ====================
class Trabajador
{
private:
    int ID;
    string nombreEmp;
    string contrasena;

public:
    Trabajador(int id, string nombre, string pass)
        : ID(id), nombreEmp(nombre), contrasena(pass) {}

    bool iniciarSesion(string pass)
    {
        return contrasena == pass;
    }

    string getNombre() const { return nombreEmp; }
    int getID() const { return ID; }
};

// ==================== CLASE VEHICULO (ABSTRACTA) ====================
class Vehiculo
{
protected:
    // Atributos comunes a todos los vehículos
    string modelo;
    string marca;
    int asientos;
    int IDarticulo;
    float precio;
    string color;
    string anio;
    string placas;

    static int contadorID; // Para generar IDs únicos

public:
    // Constructor
    Vehiculo(string m, string mar, int asien, float prec, string col, string a, string plac)
        : modelo(m), marca(mar), asientos(asien), precio(prec),
          color(col), anio(a), placas(plac)
    {
        IDarticulo = ++contadorID;
    }

    // Destructor virtual (importante para polimorfismo)
    virtual ~Vehiculo() {}

    // Getters
    int getID() const { return IDarticulo; }
    string getMarca() const { return marca; }
    string getModelo() const { return modelo; }
    float getPrecio() const { return precio; }

    // Setters para edición
    void setPrecio(float p) { precio = p; }
    void setColor(string c) { color = c; }
    void setAnio(string a) { anio = a; }

    // Método virtual para mostrar información base
    virtual void mostrarInfo()
    {
        cout << "\n┌─────────────────────────────────────┐\n";
        cout << "  ID: " << IDarticulo << endl;
        cout << "  Marca: " << marca << endl;
        cout << "  Modelo: " << modelo << endl;
        cout << "  Año: " << anio << endl;
        cout << "  Color: " << color << endl;
        cout << "  Precio: $" << precio << endl;
        cout << "  Placas: " << placas << endl;
        cout << "  Asientos: " << asientos << endl;
    }

    // Método virtual puro (abstracto) - Cada clase DEBE implementarlo
    virtual void probar() = 0;

    // Método para obtener el tipo de vehículo
    virtual string getTipo() const = 0;
};

// Inicializar contador estático
int Vehiculo::contadorID = 0;

// ==================== CLASE CARRO ====================
class Carro : public Vehiculo
{
private:
    int numPuertas;
    string tipoDeCarro; // "Sedan", "SUV", "Deportivo", etc.
    bool cajuela;

public:
    Carro(string m, string mar, int asien, float prec, string col, string a, string plac,
          int puertas, string tipo, bool tieneCajuela)
        : Vehiculo(m, mar, asien, prec, col, a, plac),
          numPuertas(puertas), tipoDeCarro(tipo), cajuela(tieneCajuela) {}

    void mostrarInfo() override
    {
        Vehiculo::mostrarInfo(); // Llama al método de la clase base
        cout << "  Tipo de Carro: " << tipoDeCarro << endl;
        cout << "  Numero de Puertas: " << numPuertas << endl;
        cout << "  Cajuela: " << (cajuela ? "Si" : "No") << endl;
        cout << "└─────────────────────────────────────┘\n";
    }

    void probar() override
    {
        cout << "\n🚗 Probando Carro " << marca << " " << modelo << "...\n";
        cout << "✓ Arrancando motor...\n";
        cout << "✓ Probando frenos...\n";
        cout << "✓ Revisando " << numPuertas << " puertas...\n";
        cout << "✓ Verificando cajuela...\n";
        cout << "✓ Carro en perfecto estado!\n";
    }

    string getTipo() const override { return "Carro"; }
};

// ==================== CLASE MOTO ====================
class Moto : public Vehiculo
{
private:
    string tipoDeMoto; // "Deportiva", "Cruiser", "Scooter", etc.
    bool incluyeCasco;

public:
    Moto(string m, string mar, int asien, float prec, string col, string a, string plac,
         string tipo, bool casco)
        : Vehiculo(m, mar, asien, prec, col, a, plac),
          tipoDeMoto(tipo), incluyeCasco(casco) {}

    void mostrarInfo() override
    {
        Vehiculo::mostrarInfo();
        cout << "  Tipo de Moto: " << tipoDeMoto << endl;
        cout << "  Incluye Casco: " << (incluyeCasco ? "Si" : "No") << endl;
        cout << "└─────────────────────────────────────┘\n";
    }

    void probar() override
    {
        cout << "\n🏍️  Probando Moto " << marca << " " << modelo << "...\n";
        cout << "✓ Arrancando motor...\n";
        cout << "✓ Probando aceleración...\n";
        cout << "✓ Verificando equilibrio...\n";
        cout << "✓ Revisando frenos...\n";
        cout << "✓ Moto lista para rodar!\n";
    }

    string getTipo() const override { return "Moto"; }
};

// ==================== CLASE CAMION ====================
class Camion : public Vehiculo
{
private:
    int pesoLimite; // En kilogramos
    string tamaño;  // "Pequeño", "Mediano", "Grande"

public:
    Camion(string m, string mar, int asien, float prec, string col, string a, string plac,
           int peso, string tam)
        : Vehiculo(m, mar, asien, prec, col, a, plac),
          pesoLimite(peso), tamaño(tam) {}

    void mostrarInfo() override
    {
        Vehiculo::mostrarInfo();
        cout << "  Peso Limite: " << pesoLimite << " kg\n";
        cout << "  Tamaño: " << tamaño << endl;
        cout << "└─────────────────────────────────────┘\n";
    }

    void probar() override
    {
        cout << "\n🚚 Probando Camion " << marca << " " << modelo << "...\n";
        cout << "✓ Verificando capacidad de carga (" << pesoLimite << " kg)...\n";
        cout << "✓ Probando sistema de frenos de aire...\n";
        cout << "✓ Revisando suspension...\n";
        cout << "✓ Comprobando direccion...\n";
        cout << "✓ Camion listo para transportar!\n";
    }

    string getTipo() const override { return "Camion"; }
};

// ==================== CLASE GESTOR DE VEHICULOS ====================
class GestorVehiculos
{
private:
    vector<Vehiculo *> vehiculos; // Polimorfismo: almacena punteros a cualquier tipo de vehículo

public:
    ~GestorVehiculos()
    {
        // Liberar memoria
        for (auto v : vehiculos)
        {
            delete v;
        }
    }

    void crearNuevoVehiculo()
    {
        int tipo;
        cout << "\n╔════════════════════════════════════╗\n";
        cout << "║      CREAR NUEVO VEHICULO          ║\n";
        cout << "╚════════════════════════════════════╝\n";
        cout << "1. Carro\n";
        cout << "2. Moto\n";
        cout << "3. Camion\n";
        cout << "Seleccione tipo: ";
        cin >> tipo;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        // Datos comunes
        string marca, modelo, color, anio, placas;
        int asientos;
        float precio;

        cout << "\n--- DATOS GENERALES ---\n";
        cout << "Marca: ";
        getline(cin, marca);
        cout << "Modelo: ";
        getline(cin, modelo);
        cout << "Año: ";
        getline(cin, anio);
        cout << "Color: ";
        getline(cin, color);
        cout << "Placas: ";
        getline(cin, placas);
        cout << "Numero de asientos: ";
        cin >> asientos;
        cout << "Precio: $";
        cin >> precio;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        Vehiculo *nuevoVehiculo = nullptr;

        if (tipo == 1)
        {
            // TODO: Completa la creación del Carro
            // Pide: numPuertas, tipoDeCarro, cajuela
            int puertas;
            string tipoCarro;
            char tieneCajuela;

            cout << "\n--- DATOS DEL CARRO ---\n";
            cout << "Numero de puertas: ";
            cin >> puertas;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Tipo (Sedan/SUV/Deportivo/Pickup): ";
            getline(cin, tipoCarro);
            cout << "Tiene cajuela? (S/N): ";
            cin >> tieneCajuela;

            nuevoVehiculo = new Carro(modelo, marca, asientos, precio, color, anio, placas,
                                      puertas, tipoCarro, (tieneCajuela == 'S' || tieneCajuela == 's'));
        }
        else if (tipo == 2)
        {
            // TODO: Completa la creación de la Moto
            // Pide: tipoDeMoto, incluyeCasco
            string tipoMoto;
            char casco;

            cout << "\n--- DATOS DE LA MOTO ---\n";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Tipo (Deportiva/Cruiser/Scooter/Touring): ";
            getline(cin, tipoMoto);
            cout << "Incluye casco? (S/N): ";
            cin >> casco;

            nuevoVehiculo = new Moto(modelo, marca, asientos, precio, color, anio, placas,
                                     tipoMoto, (casco == 'S' || casco == 's'));
        }
        else if (tipo == 3)
        {
            // TODO: Completa la creación del Camión
            // Pide: pesoLimite, tamaño
            int peso;
            string tam;

            cout << "\n--- DATOS DEL CAMION ---\n";
            cout << "Peso limite (kg): ";
            cin >> peso;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Tamaño (Pequeño/Mediano/Grande): ";
            getline(cin, tam);

            nuevoVehiculo = new Camion(modelo, marca, asientos, precio, color, anio, placas,
                                       peso, tam);
        }

        if (nuevoVehiculo != nullptr)
        {
            vehiculos.push_back(nuevoVehiculo);
            cout << "\n✓ Vehiculo creado exitosamente! ID: " << nuevoVehiculo->getID() << "\n";
        }
    }

    void eliminar()
    {
        if (vehiculos.empty())
        {
            cout << "\n⚠ No hay vehiculos registrados.\n";
            return;
        }

        mostrarTodos();

        int id;
        cout << "\nIngrese ID del vehiculo a eliminar: ";
        cin >> id;

        // TODO: Implementa la lógica para buscar y eliminar el vehículo por ID
        // Pista: usa un iterador y el método erase() del vector
        for (auto it = vehiculos.begin(); it != vehiculos.end(); ++it)
        {
            if ((*it)->getID() == id)
            {
                cout << "\n¿Confirma eliminar " << (*it)->getMarca() << " "
                     << (*it)->getModelo() << "? (S/N): ";
                char conf;
                cin >> conf;
                if (conf == 'S' || conf == 's')
                {
                    delete *it; // Liberar memoria
                    vehiculos.erase(it);
                    cout << "✓ Vehiculo eliminado exitosamente.\n";
                }
                return;
            }
        }
        cout << "⚠ Vehiculo no encontrado.\n";
    }

    void editar()
    {
        if (vehiculos.empty())
        {
            cout << "\n⚠ No hay vehiculos registrados.\n";
            return;
        }

        mostrarTodos();

        int id;
        cout << "\nIngrese ID del vehiculo a editar: ";
        cin >> id;

        // TODO: Implementa la lógica para buscar el vehículo y permitir editar
        // Pista: Busca por ID, muestra opciones (precio, color, año) y actualiza
        for (auto v : vehiculos)
        {
            if (v->getID() == id)
            {
                cout << "\n--- EDITANDO VEHICULO ---\n";
                cout << "1. Cambiar precio\n";
                cout << "2. Cambiar color\n";
                cout << "3. Cambiar año\n";
                cout << "Opcion: ";
                int op;
                cin >> op;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                if (op == 1)
                {
                    float nuevoPrecio;
                    cout << "Nuevo precio: $";
                    cin >> nuevoPrecio;
                    v->setPrecio(nuevoPrecio);
                    cout << "✓ Precio actualizado.\n";
                }
                else if (op == 2)
                {
                    string nuevoColor;
                    cout << "Nuevo color: ";
                    getline(cin, nuevoColor);
                    v->setColor(nuevoColor);
                    cout << "✓ Color actualizado.\n";
                }
                else if (op == 3)
                {
                    string nuevoAnio;
                    cout << "Nuevo año: ";
                    getline(cin, nuevoAnio);
                    v->setAnio(nuevoAnio);
                    cout << "✓ Año actualizado.\n";
                }
                return;
            }
        }
        cout << "⚠ Vehiculo no encontrado.\n";
    }

    void mostrarTodos()
    {
        if (vehiculos.empty())
        {
            cout << "\n⚠ No hay vehiculos registrados.\n";
            return;
        }

        cout << "\n╔════════════════════════════════════╗\n";
        cout << "║    VEHICULOS EN EXHIBICION         ║\n";
        cout << "╚════════════════════════════════════╝\n";

        for (auto v : vehiculos)
        {
            v->mostrarInfo(); // Polimorfismo: llama a la versión correcta
        }
    }

    void probarVehiculo()
    {
        if (vehiculos.empty())
        {
            cout << "\n⚠ No hay vehiculos registrados.\n";
            return;
        }

        mostrarTodos();

        int id;
        cout << "\nIngrese ID del vehiculo a probar: ";
        cin >> id;

        for (auto v : vehiculos)
        {
            if (v->getID() == id)
            {
                v->probar(); // Polimorfismo: cada tipo se prueba diferente
                return;
            }
        }
        cout << "⚠ Vehiculo no encontrado.\n";
    }
};

// ==================== CLASE MENU ====================
class Menu
{
public:
    void volverPagInicial()
    {
        cout << "\nPresione Enter para volver al menu principal...";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();
    }

    void mostrarMenuPrincipal()
    {
        cout << "\n╔════════════════════════════════════╗\n";
        cout << "║    SISTEMA DE GESTION VEHICULAR    ║\n";
        cout << "╚════════════════════════════════════╝\n";
        cout << "1. Crear nuevo vehiculo\n";
        cout << "2. Mostrar todos los vehiculos\n";
        cout << "3. Editar vehiculo\n";
        cout << "4. Eliminar vehiculo\n";
        cout << "5. Probar vehiculo\n";
        cout << "0. Salir\n";
        cout << "\nSeleccione una opcion: ";
    }
};

// ==================== MAIN ====================
int main()
{
    // Crear tienda
    Tienda miTienda("TEND001", "Av. Principal #123");

    // Crear trabajador
    Trabajador trabajador(1, "Juan Perez", "admin123");

    // Autenticación
    cout << "╔════════════════════════════════════╗\n";
    cout << "║         INICIO DE SESION           ║\n";
    cout << "╚════════════════════════════════════╝\n";
    string password;
    cout << "Usuario: " << trabajador.getNombre() << endl;
    cout << "Contraseña: ";
    cin >> password;

    if (!trabajador.iniciarSesion(password))
    {
        cout << "\n⚠ Contraseña incorrecta. Acceso denegado.\n";
        return 1;
    }

    cout << "\n✓ Bienvenido, " << trabajador.getNombre() << "!\n";
    miTienda.mostrarInfoTienda();

    // Sistema principal
    GestorVehiculos gestor;
    Menu menu;
    int opcion;

    do
    {
        menu.mostrarMenuPrincipal();
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            gestor.crearNuevoVehiculo();
            menu.volverPagInicial();
            break;
        case 2:
            gestor.mostrarTodos();
            menu.volverPagInicial();
            break;
        case 3:
            gestor.editar();
            menu.volverPagInicial();
            break;
        case 4:
            gestor.eliminar();
            menu.volverPagInicial();
            break;
        case 5:
            gestor.probarVehiculo();
            menu.volverPagInicial();
            break;
        case 0:
            cout << "\n¡Hasta luego!\n";
            break;
        default:
            cout << "\n⚠ Opcion invalida.\n";
        }

    } while (opcion != 0);

    return 0;
}

/*
╔════════════════════════════════════════════════════════════════════╗
║                    REFLEXIONES FINALES                             ║
╠════════════════════════════════════════════════════════════════════╣
║ 1. ¿Cómo funciona el polimorfismo en este sistema?                ║
║    - El vector almacena Vehiculo* (punteros a la clase base)      ║
║    - Cada elemento puede ser Carro, Moto o Camion                 ║
║    - Cuando llamas v->probar(), se ejecuta la versión correcta    ║
║                                                                    ║
║ 2. ¿Por qué los métodos son virtuales?                            ║
║    - Permite que cada clase derivada tenga su propia versión      ║
║    - El compilador decide en tiempo de ejecución cuál llamar      ║
║                                                                    ║
║ 3. ¿Qué aprendiste sobre herencia?                                ║
║    - Reutilización de código (atributos comunes en la base)       ║
║    - Especialización (atributos únicos en derivadas)              ║
║    - Relación "ES-UN" (Carro ES-UN Vehiculo)                      ║
╚════════════════════════════════════════════════════════════════════╝
*/
