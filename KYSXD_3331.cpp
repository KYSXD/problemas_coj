//"""
//#KYSXD - Problema 3331
//Bob and Solitary Kings
//"""

#include <iostream>
#include <stdio.h>

using namespace std;

int main(){
	long long int row, col, total;

	while(scanf("%lld %lld", &row, &col)) {
		if(row == 0 && col == 0) break;

		total = row*col;
		total = total*(total-1);

		total -= (row > 1 &&  col > 1 ? 12 : (row > 1 || col > 1 ? 2 : 0));

		total -= (row > 2 ? (col > 1 ? (row - 2)*10 : (row - 2)*2) : 0);
		total -= (col > 2 ? (row > 1 ? (col - 2)*10 : (col - 2)*2) : 0);

		total -= (row > 2 && col > 2 ? (row-2)*(col-2)*8 : 0);

		printf("%lld\n", total);
	}

	return 0;	
}