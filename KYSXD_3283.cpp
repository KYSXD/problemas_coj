//"""
//#KYSXD - Problema 3283
//Alice and Array in Flames
//"""
//Status:
//"""

#include <iostream>
#include <stdio.h>

int arrPos[] = {
    0x1,
    0x2,
    0x4,
}

using namespace std;
int sol (int a, int b, int *arr, int *estado){
    int res = 2;
    for(int i=a; i<b;i++)
    {
        if(res =! 1 && arr[i] == arr[i+1]) {
            res = 1;
        }
        else if(arr[i] > arr[i+1]){
            return 0;
        }
    }
    return res;
}

int main() {
    int nums, cases;
    scanf("%d %d", &nums, &cases);
    int arreglo[nums];
    int estado[nums>>2]; //4 numbers array

    int aux = -1;
    for(int i = 0; i < nums; i++) {
        if(i%4 == 0) {
            estado[i>>2] = 0x0;
            aux++;
        }
        scanf("%d", &arreglo[i]);
        if(arreglo[i] == arreglo[i-1]) {
            estado[aux] |= arrPos[1];
        }
        else 
            estado[aux] |= arrPos[0];
    }
    int operacion, first, last;
    for(int i = 0; i < cases; i++) {
        scanf("%d %d %d", &operacion, &first, &last);
        if(operacion == 1) {
            int tempNum = first - 1;
            int tempArr = tempNum >> 2;

            arreglo[tempNum] = last;
            estado[tempArr] = 0x0;

            if(tempNum%4 == 0) {
                estado[tempArr - 1] = 0x0;
                int tempNum_Last = tempNum - 4;
                int tempArr_Last = tempArr - 1;
                for(int j = 0; j < 4; j++) {
                    if(arreglo[tempNum_Last + j] >= arreglo[tempNum_Last + j-1]) {
                        estado[tempArr_Last] |= arrPos[1];
                    }
                    else
                        estado[tempArr_Last] |= arrPos[0];
                }                
            }

            for(int j = 0; j < 4; j++) {
                if(arreglo[tempNum + j] >= arreglo[tempNum + j-1]) {
                    estado[tempArr] |= arrPos[1];
                }
                else
                    estado[tempArr] |= arrPos[0];
            }

            if(tempNum%4 == 3) {
                estado[tempArr + 1] = 0x0;
                int tempNum_Last = tempNum + 1;
                int tempArr_Last = tempArr + 1;
                for(int j = 0; j < 4; j++) {
                    if(arreglo[tempNum_Last + j] >= arreglo[tempNum_Last + j-1]) {
                        estado[tempArr_Last] |= arrPos[1];
                    }
                    else
                        estado[tempArr_Last] |= arrPos[0];
                }                
            }

        }
        else{
            printf("%d\n", sol(first-1, last-1, arreglo, estado));
        }
    }

    return 0;
}