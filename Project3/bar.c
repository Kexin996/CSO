
#include <stdio.h>

long bar ( long a, long b ); 

long bar ( long a, long b ) { 
    long d = a;
    long x = 0;
    long c = 11*a;

    a = 16*b;
    c = c+2*b;
    c = c-a+1;
    while (d <= b)
    {
        d += 1;
        x += c;
    }

    return x;
}
