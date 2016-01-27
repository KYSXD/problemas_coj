//"""
//#KYSXD - Problema 1394
//An Inductively-Defined Function
//"""
//Status:
//"""

#include <iostream>
#include <stdio.h>

using namespace std;

int main () {
	long long int val;
	while (scanf("%lld", &val)) {
		if(val == -1) break;
		printf("f(%lld) = %lld\n\n", val, (val+1)>>1);
	}
	return 0;
}
