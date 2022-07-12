#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "float.h"

// in the test case there is a ssign "|" after "-inf"
// in order to make the program to run, I just delete this small bug

int is_special ( float f ) {

	// we check whether the number is in some special cases
	// e.g. the number is nan or infinity
    return isnan(f)|| isinf(f);
}


float get_M  ( float f ) {
	// we check for special case
	// for the conditions in problem2
	if (isnan(f))
	{
		return 0.5;
	} 
	if (isinf(f))
	{
		return 0;
	}

	// we use the aboslute value of the float number
	f = fabs(f);

	// we get the matisse
	// by calling to the function get_E
	float E = pow(2,get_E(f));
	f = f / E;
	return f;
}


int get_s ( float f ) {
	// we check whether the number is positive or not
	// if it is, return 1
	// else, return -1
	
	if (signbit(f) == 0)
	{
		return 1;
	}
	else
	{
		return -1;
	}
}



int get_E ( float f ) 
{
	// we first check for the normal number
	if (isnormal(f))
	{
		int ans = 0;
		// we need the absolute value of the number
		f = fabs(f);
		// if the number >= 1
		// we need to divide it by 2 to get E
		// and use ans to keep track of it
		// until it is smaller than 2
		if (f >= 1)
		{
			while (f >= 2 )
			{
				f = f/2.0f;
				ans++;
			}
		}
		// else, we just mulitply it by 2
		// until it is >= 1
		else
		{
			while (f < 1)
			{
				f = f*2.0f;
				ans--;
			}
		}
		return ans;
	}
	else
	{
		// if the number if nan or inf
		// we return 255
		if (isnan(f) || isinf(f))
		{
			return 255;
		}
		// if the number is subnormal 
		// E will be fixed to -126
		else
		{
			return -126;
		}
	}
}













      



    
    
