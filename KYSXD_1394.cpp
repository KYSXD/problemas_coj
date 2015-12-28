//"""
//#KYSXD - Problema 1394
//An Inductively-Defined Function
//"""

#include <iostream>
#include <stdio.h>

using namespace std;

unsigned long long int f_n(unsigned long long int n){
	if(n == 1) return 1;
	else if(n%2 == 0){
		return n/2;
	}
	else return f_n( (n-1)/2 ) + f_n( ((n-1)/2) + 1);
}

int main (){
	unsigned long long int val;
	while (cin >> val) {
		if(val == -1) break;
		cout << "f(" << val << ") = " << f_n(val) << endl;
	}
	return 0;
}