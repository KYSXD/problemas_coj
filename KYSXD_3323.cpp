//"""
//#KYSXD - Problema 3323
//Even Number of Divisors
//"""
//Status:
//"""

#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;

long long int cuentaCuadrados(long long int primero, long long int ultimo) {
    long double raiz_primero = sqrt(primero);
    long double raiz_ultimo = sqrt(ultimo);
    if (int(raiz_primero) == int(raiz_ultimo)){
        return (int(raiz_primero) == raiz_primero) ? 1 : 0;
    }
    else {
        long long int cant_cuadrados = int(raiz_ultimo) - int(raiz_primero);
        cant_cuadrados += (int(raiz_primero) == raiz_primero) ? 1 : 0;
        return cant_cuadrados;
    }
}

int main()
{
    long long int inicio, fin, resultado;
    while (scanf("%lld %lld", &inicio, &fin)) {
        if (inicio == 0 && fin == 0)
            break;
        else
            resultado = ((fin - inicio) + 1) - cuentaCuadrados(inicio, fin);
        printf("%lld\n",resultado);
    }
    return 0;
}