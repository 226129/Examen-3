#include <iostream>
using namespace std;

int factorial(int n);
struct Cuenta
{
    /**Estructura para la cuenta del usuario */
    double efectivo = 20000;
} cuenta1;

void consultar_cuenta(const Cuenta &cuenta);
void retirar_efectivo(Cuenta &cuenta);

int main()
{
    /**Despliega un menu de dos opciones que son calcular un factorial y hacer calculos en una cuenta bancaria */
    int opc = 1;
    int opc_banco = 1;
    int numero;

    do
    {
        cout << endl
             << "Ingrese la opcion a realizar" << endl
             << "1. Calcular el factorial de un numero" << endl
             << "2. Ingresar a la cuenta bancaria" << endl
             << "0. Salir" << endl
             << "Opcion: ";
        cin >> opc;

        if (opc == 1)
        {
            cout << "Introduce un numero para calcular su factorial: ";
            cin >> numero;
            cout << "El factorial de " << numero << " es " << factorial(numero) << endl;
            system("pause");
        }
        else if (opc == 2)
        {
            do
            {
                cout << endl
                     << "Seleccione una opcion" << endl
                     << "1. Consultar efectivo" << endl
                     << "2. Retirar efectivo" << endl
                     << "0. Salir" << endl
                     << "Opcion: ";
                cin >> opc_banco;

                if (opc_banco == 1)
                {
                    consultar_cuenta(cuenta1);
                }
                else if (opc_banco == 2)
                {
                    retirar_efectivo(cuenta1);
                }
                else if (opc_banco == 0)
                {
                    cout << endl
                         << "Saliendo del banco..." << endl;
                    system("pause");
                }
            } while (opc_banco != 0);
        }
        else if (opc == 0)
        {
            cout << endl
                 << "Saliendo del programa" << endl;
        }
    } while (opc != 0);

    cout << endl
         << "Presione enter para terminar" << endl;
    system("pause");
    return 0;
}

int factorial(int n)
{
    /**Recibe un numero y calcula su factorial */
    if (n <= 1)
    {
        return 1;
    }
    else
    {
        return n * factorial(n - 1);
    }
}

void consultar_cuenta(const Cuenta &cuenta)
{
    /**Imprime el estado actual de la cuenta */
    cout << endl
         << "Saldo de la cuenta: " << cuenta.efectivo << endl;
}

void retirar_efectivo(Cuenta &cuenta)
{
    /**Pide un monto a retirar y actualiza la cuenta en base a ello */
    double retiro;
    cout << endl
         << "Ingrese el monto a retirar: ";
    cin >> retiro;
    while (retiro == 0 || retiro > cuenta.efectivo)
    {
        cout << endl
             << "Ingrese un monto adecuado: ";
        cin >> retiro;
    }
    cuenta.efectivo -= retiro;
    cout << endl
         << "Saldo de la cuenta: " << cuenta.efectivo << endl;
}
