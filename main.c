#include <stdio.h>
// multiply
unsigned int
multiply (unsigned int factor1, unsigned int factor2) 
{
  
int product = 0;
    while (factor2 > 0)
    
    {
      
	// If second number becomes odd, add the first number to result 
	if (factor2 & 1)
	
product = product + factor1;
      
 
	// Double the first number and halve the second number 
	factor1 = factor1 << 1;
      
factor2 = factor2 >> 1;
    
}
  
return product;

}


 
int
divide (int dividend, int divisor)
{
  int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
    dividend = dividend;
    divisor = divisor;
    int quotient = 0;
while (dividend >= divisor)
    {
      
dividend -= divisor;
      
++quotient;
    
}
  
int mpsignquotient = multiply (sign, quotient);
  
return mpsignquotient;

}


// Interpolate for y 2 at x2
  unsigned int
Interpolate (unsigned int x_1, unsigned int x_2, unsigned int x_3,
	     unsigned int y_1, unsigned int y_3) 
{
  
unsigned int y_2 = 0;	// initialize y_2 for calc
  unsigned int dx21 = x_2 - x_1;	//calc delta x_2 to x_1
  unsigned int dx31 = x_3 - x_1;
  
unsigned int dy31 = y_3 - y_1;
  
y_2 = divide (multiply (dx21, dy31), (dx31)) + y_1;
  
return y_2;

}


 
int
main () 
{
  
unsigned int x_1 = 100, x_2 = 300, x_3 = 500, y_1 = 31415, y_3 = 161111;
double integ = Interpolate (x_1, x_2, x_3, y_1, y_3);
printf ("%d", integ);
  
 
return 0;

}
