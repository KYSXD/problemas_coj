//"""
//#KYSXD - Problema 3375
//Naebbirac Phrases
//"""
//Status:
//"""

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int cases, diff;

    string A, B;
    cin >> cases;
 
    for(int i = 0; i < cases; i++) {
        diff = 0;
        cin >> A >> B;

        for(int j = 0; j < min(A.length(), B.length()); j++) {
            if(A[j] != B[j]) {
                diff++;
            }
        }
        cout << diff << endl;
    }
    return 0;
}