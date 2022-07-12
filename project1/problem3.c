// implement your program here
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num = 0;

    // in this way we continuously get the number

    while (scanf("%d",&num) != EOF)
    {
    	
    	getchar();

	    int a = 0; 
	    int b =0;
	    // we use change to switch
	    int change = 0;
	    // we use track to do bitwise operation
	    // that is, to make sure how many bites we shoud move
	    int track = 0;

	    
	    while (num > 0)
	    {
	    	// if we find 1
	        if ((num & 1) == 1)
	        {
	        	// if we can add it to 'a'
	            if (change == 0)
	            {
	            	// in this way, we 'add' 1 in the beginning of 'a'
	                a = (1<<track)|a;
	         		// we switch
	                change = 1;
	            }
	            else
	            {
	            	// we add it to 'b'
	                b = (1<<track)|b;
	                change = 0;
	            }
	        }
	        // we update track and num
	        // when num = 0, we stop
	        track++;
	        num = num>>1;
	    }
	    // just like in the sample output,
	    // for 0, we have no output
	    if (a != 0 || b !=0)
	    {
		    printf("%d ",a);
		    printf("%d\n",b);
		}
		
	}
    
}