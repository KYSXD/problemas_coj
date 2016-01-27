//"""
//#KYSXD - Problema 3334
//Dr. B - Tree I
//"""
//Status:
//"""

#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
    int val_a, val_b, last = 0, temp = 0, times = 0;
    char word_a[100000], word_b[100000];

    scanf("%d %s %d %s", &val_a, word_a, &val_b, word_b);

    for (int i = 0; i < val_a; i++) {
        if (word_a[i] == word_b[last]) {
            if (last + 1 == val_b) times++;
            last = (last+1)%val_b;
        }
        else temp++;
    }

    printf("%d\n", (times ? temp + last : -1));
    return 0;
}