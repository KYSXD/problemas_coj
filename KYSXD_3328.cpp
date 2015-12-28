//"""
//#KYSXD - Problema 3328
//Circles in the Angle
//"""

#include <iostream>
#include <stdio.h>
#include <cmath>
#include <iomanip>

using namespace std;

int main (){
    double x, r1, r2, r3 = 1, a, my_cos, area, pi = 3.14159265359;

    while(scanf("%lf %lf", &r1, &r2)) {
        if(r1 == 0 && r2 == 0) break;

        r3 = 1;
        a = acos( (r1-r2)/(r1+r2) );
        my_cos = (r1-r2)/(r1+r2);
        x = r1/my_cos;
        area = x*r1*sin(a);
        area = area - a*r1*r1;
        area = area - (pi*r2*r2);


        while(r3 > 0.00000001) {
            r3 = (x-(2*r2)-r1)*my_cos/(1+my_cos);
            area = area -pi*r3*r3;
            x = x-r1-r2;
            r1 = r2;
            r2 = r3;
        }

        printf("%lf\n", area);
    }
    return 0;
}