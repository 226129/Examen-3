#include <iostream>
using namespace std;

int factorial(int n)
{
    if (n <= 1)
    {
        return 1;
    }
    else
    {
        return n * factorial(n - 1);
    }
}

int main()
{
    int numero;

    cout << "Introduce un número para calcular su factorial: ";
    cin >> numero;

    cout << "El factorial de " << numero << " es " << factorial(numero) << endl;

    return 0;
}
