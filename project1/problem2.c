// implement your program here

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char toHex(int);
char toHex(int num)
{
	// we use this method to change the number into heximal numbers
    char ans;
    if (num < 10)
    {
        ans = num+'0';
    }
    else
    {
        ans = (num-10)+'a';
        
    }
    return ans;
}
int main(int argc, char *argv[])
{
	// we read the number of RGB colors 
	int length = 0;
	int j;

    scanf("%d",&length);
    getchar();

	for (j = 0;j < length;j++)
	{		
		// get the three numbers
	    char testcase[30];
	    scanf("%[^\n]",testcase);
	    getchar();

	    // we use token to split it
		char *token = strtok(testcase, " ,");
	    char ans[8] = {"#"};
	    int invalid = 0;
	    int i = 1;

	    while (token != NULL) 
	    {
	    	// we split the RGB numbers
	    	// and check for validity
	        int temp = atoi(token);
	        if (temp > 255 || temp < 0)
	        {
	            invalid = 1;
	            break;
	        }

	        // we divide the 'temp'
	        // and mod it in order to change them to 
	        // hexadecimal
	        int first = temp / 16;
	        int second = temp % 16;

	        ans[i] = toHex(first);
	        ans[i+1] = toHex(second);
	        i = i+2;
	        token = strtok(NULL, " ,");
	    }
	    
	    // if invalid, we show it to the user
	    if (!invalid)
	    {
	        printf("%s\n",ans);
	    }
	    else
	    {
	        printf("INVALID\n");
	    }
	}
}