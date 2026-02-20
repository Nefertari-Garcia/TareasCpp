#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

#define MAX 100

template <class T>
class Pila
{
private:
    T EspacioPila[MAX];
    int Tope;

public:
    Pila();
    void operator+(T Dato);
    void operator-(T *Dato);
    int PilaLlena();
    int PilaVacia();
};

template <class T>
Pila<T>::Pila()
{
    Tope = -1;
}

template <class T>
void Pila<T>::operator+(T Dato)
{
    if (!PilaLlena())
    {
        EspacioPila[++Tope] = Dato;
    }
}

template <class T>
void Pila<T>::operator-(T *Dato)
{
    if (!PilaVacia())
    {
        *Dato = EspacioPila[Tope--];
    }
}

template <class T>
int Pila<T>::PilaLlena()
{
    return (Tope == MAX - 1) ? 1 : 0;
}

template <class T>
int Pila<T>::PilaVacia()
{
    return (Tope == -1) ? 1 : 0;
}

class Cheque
{
protected:
    int Numero;
    int CuentaADepositar;
    char Banco[50];
    double Monto;

public:
    Cheque();
    Cheque(int, char *, int, double);
    virtual ~Cheque() {}
    virtual void ImprimeDatos();
};

Cheque::Cheque() : Numero(0), CuentaADepositar(0), Monto(0.0)
{
    Banco[0] = '\0';
}

Cheque::Cheque(int NumCta, char *NomBco, int Cta, double Mon)
{
    Numero = NumCta;
    CuentaADepositar = Cta;
    Monto = Mon;
    strncpy(Banco, NomBco, 49);
    Banco[49] = '\0';
}

void Cheque::ImprimeDatos()
{
    cout << "\nNúmero de cheque: " << Numero;
    cout << "\nDel banco: " << Banco;
    cout << "\nDepositado en la cuenta: " << CuentaADepositar;
    cout << "\nMonto: " << Monto << endl;
}

class ChequeRechazado : public Cheque
{
private:
    double Cargo;

public:
    ChequeRechazado();
    ChequeRechazado(int, char *, int, double);
    ~ChequeRechazado() {}
    void ImprimeDatos();
};

ChequeRechazado::ChequeRechazado() : Cheque(), Cargo(0.0) {}

ChequeRechazado::ChequeRechazado(int NumCta, char *NomBco, int Cta, double Mon)
    : Cheque(NumCta, NomBco, Cta, Mon)
{
    Cargo = Mon * 0.1;
}

void ChequeRechazado::ImprimeDatos()
{
    Cheque::ImprimeDatos();
    cout << "Cargo por rechazo: " << Cargo << endl;
}

class Banco
{
private:
    Pila<Cheque> Cheques;
    Pila<ChequeRechazado> ChequesRe;

public:
    Banco() {}
    ~Banco() {}
    void ProcesarCheque();
    void ProcesarChequeR();
    void RegistroCheque(Cheque);
    void RegistroChequeR(ChequeRechazado);
};

void Banco::ProcesarCheque()
{
    if (!Cheques.PilaVacia())
    {
        Cheque ChequeCli;
        Cheques - &ChequeCli;
        cout << "\nCheque procesado: ";
        ChequeCli.ImprimeDatos();
    }
    else
    {
        cout << "\nNo hay cheques por procesar.\n";
    }
}

void Banco::ProcesarChequeR()
{
    if (!ChequesRe.PilaVacia())
    {
        ChequeRechazado ChequeCli;
        ChequesRe - &ChequeCli;
        cout << "\nCheque rechazado procesado: ";
        ChequeCli.ImprimeDatos();
    }
    else
    {
        cout << "\nNo hay cheques rechazados por procesar.\n";
    }
}

void Banco::RegistroCheque(Cheque ChequeCli)
{
    if (!Cheques.PilaLlena())
    {
        cout << "\nRegistrando el cheque: ";
        ChequeCli.ImprimeDatos();
        Cheques + ChequeCli;
    }
    else
    {
        cout << "\nNo se pudo registrar el cheque por falta de espacio.\n";
    }
}

void Banco::RegistroChequeR(ChequeRechazado ChequeCli)
{
    if (!ChequesRe.PilaLlena())
    {
        cout << "\nRegistrando el cheque rechazado: ";
        ChequeCli.ImprimeDatos();
        ChequesRe + ChequeCli;
    }
    else
    {
        cout << "\nNo se pudo registrar el cheque rechazado por falta de espacio.\n";
    }
}

int main()
{
    Cheque Uno(1718, (char *)"Banamex", 14418, 18000.00);
    Cheque Dos(1105, (char *)"Bancomer", 13200, 12319.62);

    ChequeRechazado Tres(1816, (char *)"Banorte", 12850, 14000.00);
    ChequeRechazado Cuatro(1905, (char *)"Bancomer", 13468, 50000.00);

    Banco MiBanco;

    MiBanco.RegistroCheque(Uno);
    MiBanco.RegistroCheque(Dos);
    MiBanco.RegistroChequeR(Tres);
    MiBanco.RegistroChequeR(Cuatro);

    MiBanco.ProcesarCheque();
    MiBanco.ProcesarChequeR();
    MiBanco.ProcesarCheque();
    MiBanco.ProcesarChequeR();

    MiBanco.ProcesarCheque();
    MiBanco.ProcesarChequeR();

    return 0;
}