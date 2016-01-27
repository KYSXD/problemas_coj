//"""
//#KYSXD - Problema 3327
//How Many Numbers
//"""
//Status:
//"""

#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
#include <stdio.h>

using namespace std;

long long int elevar_a_p(int a, int p) {
    if (p == 0) return 1;
    return a*elevar_a_p(a, p-1);
}

long long int comb_n_r(int n, int r) {
    if (r == 0) return 1;
    return (n * comb_n_r(n - 1, r - 1)) / r;
}

long long int casos(int p, int i) {
	long long int total = 0;
	if (i > 0) {
		total += comb_n_r(p +i - 1 , i - 1) * elevar_a_p(5, p) * elevar_a_p(5, i);
	}
	if (p > 0) {
		total += 4 * comb_n_r( p + i - 1 , p - 1) * elevar_a_p(5,p-1) * elevar_a_p(5, i);
	}
	return total;
}

int main(){
	int pares, impares;
	long long int total;
	while (cin >> pares >> impares) {
		if (pares == 0 && impares == 0) break;
		else
			total = 2*casos(pares, impares);
		cout << total << endl;
	}
	return 0;
}