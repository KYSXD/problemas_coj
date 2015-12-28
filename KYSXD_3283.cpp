//"""
//#KYSXD - Problema 3283
//Alice and Array in Flames
//"""

#include <iostream>
#include <stdio.h>

using namespace std;
int sol (int a, int b, int* arr){
    int res = 2;
    for(int i=a; i<b;i++) {
        if(res =! 1 && arr[i] == arr[i+1]) {
            res = 1;
        }
        else if(arr[i] > arr[i+1]){
            return 0;
        }
    }
    return res;
}

int main()
{
    int n,q;
    scanf("%d %d", &n,&q);
    int arreglo[n];

    for(int i=0; i<n; i++) {
        scanf("%d", &arreglo[i]);
    }
    int operacion, first, last;
    for(int i=0; i<q ;i++) {
        scanf("%d %d %d", &operacion, &first, &last);
        if(operacion == 1) {
            arreglo[first-1] = last;
        }
        else{
            printf("%d\n", sol(first-1,last-1,arreglo));
        }
    }
    return 0;
}