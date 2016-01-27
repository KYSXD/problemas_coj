//"""
//#KYSXD - Problema 3392
//Factory of Painted Wooden Toys
//"""
//Status:
//"""

#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
    long long int n;
    while(scanf("%lld", &n)) {
    	if (n == 0) break;
        (n == 1 ? printf("0\n") : printf("%lld\n", (n-2)*12));
    }
    return 0;
}