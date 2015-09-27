//"""
//#KYSXD - Problema 3335
//"""

#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
#include <stdio.h>

using namespace std;

int espar(int n) {
    return (n%2 == 0) ? 0 : 1;
}

int objetos(int total, int contados){
    return contados - espar(total);
}

unsigned long long int potencia(int a, int p){
    unsigned long long int resultado = 1;
    for (int i = 0; i < p; i++) {
        resultado = (resultado*a)%1000000007;
    }
    return resultado;
}

unsigned long long int elevar(int a, int p){
    if (p == 0) return 1;
    return a*potencia(a, p-1);
}

unsigned long long int combinaciones(int n, int k) {
    if (k == 0) return 1;
    return (n * combinaciones(n - 1, k - 1)) / k;
}

int restantes(int n, int r){
    return n - 2*r + espar(n);
}

int main()
{
    int caso, n, r;
    unsigned long long int total;
    scanf("%d", &caso);
//    cin >> caso;
    for (int i = 1; i <= caso; i++) {
      scanf("%d %d", &n, &r);
//        cin >> n >> r;
        if (n < r || int(n/2) + espar(n) < r) {
//            cout << 0 << endl;
            printf("%d\n", 0);
        }
        else {
            total = combinaciones(int(n/2), objetos(n,r)) % 1000000007;
            total = (total*potencia(10, r))%1000000007;
            total = (total*potencia(10, restantes(n,r)/2))%1000000007;
            total = (total*potencia(9, restantes(n,r)/2))%1000000007;
            printf("%lld\n",total);
//            cout << total << endl;
        }
    }
    return 0;
}