
/* DO NOT MODIFY THIS FILE */ 

/* This is the signature for the function 
 * that you need to implement. 
 */ 
long foo ( long a, long b ) ; 

long foo ( long a, long b ) 
{
   long t1 = 52*a;
   long t2 = 3*b;
   long t3 = 32*t2;
   t3 -= t2;
   t1+=t3;
   b -= a;
   t3 =95*b;
   t1 += t3;
  
   return t1;
}
