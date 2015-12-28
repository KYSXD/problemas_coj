//"""
//#KYSXD - Problema 3375
//Naebbirac Phrases
//"""

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    int n = 100;
    int casos, cambios;

    string A, B;
    cin >> casos;
 
    for(int i = 0; i < casos; i++){
        cambios = 0;
        cin >> A >> B;

        for(int j = 0; j < min(A.length(), B.length()); j++){
            if(A[j] != B[j]) {
                cambios++;
            }
        }
        cout << cambios << endl;
    }
    return 0;
}