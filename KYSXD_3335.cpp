//"""
//#KYSXD - Problema 3335
//Dr. B - Tree II
//"""
//Status:
//"""

#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
#include <stdio.h>

using namespace std;

typedef unsigned long long ulong;

int paridad(int n) {
    return (n%2 == 0) ? 0 : 1;
}

int objetos(int total, int contados){
    return contados - paridad(total);
}

ulong int potencia(int a, int p){
    ulong int resultado = 1;
    for (int i = 0; i < p; i++) {
        resultado = (resultado*a)%1000000007;
    }
    return resultado;
}

ulong int elevar(int a, int p){
    if (p == 0) return 1;
    return a*potencia(a, p-1);
}

ulong int combinaciones(int n, int k) {
    if (k == 0) return 1;
    return (n * combinaciones(n - 1, k - 1)) / k;
}

int restantes(int n, int r){
    return n - 2*r + paridad(n);
}

int main() {
    int caso, n, r;
    ulong int total;
    scanf("%d", &caso);
    for (int i = 1; i <= caso; i++) {
      scanf("%d %d", &n, &r);
        if (n < r || int(n/2) + paridad(n) < r) {
            printf("%d\n", 0);
        }
        else {
            total = combinaciones(int(n/2), objetos(n,r)) % 1000000007;
            total = (total*potencia(10, r)) % 1000000007;
            total = (total*potencia(10, restantes(n,r)/2)) % 1000000007;
            total = (total*potencia(9, restantes(n,r)/2)) % 1000000007;
            printf("%lld\n",total);
        }
    }
    return 0;
}