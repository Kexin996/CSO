// implement your program here
#include <stdio.h>
#include <string.h>

int main()
{
    int length = 0;
    int j;
    // we first scan the number of date
    scanf("%d",&length);
    getchar();

    for (j = 0;j < length;j++)
    {
        // then we scan the date continuously
        int invalid = 0;
        char input[15];
        scanf("%[^\n]",input);
        getchar();
        
        int length = sizeof(input)/sizeof(char);
        int i,days;
        int ans = 0;
        int move = 0;
        
        for (i = 1; i < length-2; i+= 3)
        {
            // we get the number of digits in ones and tens
            int ones = input[length-(i+1)]-'0';
          
            int tens = input[length-(i+2)]-'0';

            // we use temp to check validity
            int temp = 10*tens +ones;
      
            // check for minutes and seconds
            if (i < 7)
            {
                //  0 <= minutes / seconds < 60
                if (temp >= 60 || temp < 0)
                {

                    invalid = 1;
                    break;
                }
            }
            
            // check for the hours
            if (i == 7)
            {
                // 0 <= hours < 24
                if (temp >= 24 || temp < 0)
                {
                    
                    invalid = 1;
                    break;
                }
            }
            
            // check for the day
            
            if (i > 7)
            {
                // two situations
                // first, we don't care about whether the month contains 30 or 31 days

                // we just need 1 <= month <= 31
                if (temp > 31 || temp <= 0 )
                {
                    
                    invalid = 1;
                    break;
                }
                days = temp;
                
            }
            int combined = tens << 4 | ones;
            if (i < 7)
            {
                // we merge valid numbers
                ans = combined << move | ans;
                move += 7;
            }
            else
            {
                ans = combined << move | ans;
                move += 6;
            }
        }
        // we use the month for checking whether the number of days should be 30 or 31 days
        int month_ones = (int)input[length-(i+1)]-48;
        int month_tens = (int)input[length-(i+2)]-48;
        if (invalid == 1)
        {
            // we first jump over the invalid ones
            printf("INVALID\n");
        }
        else
        {

            int month_temp = 10*month_tens+month_ones;
            int month_combined = month_tens << 4 | month_ones;
            int final_ans =  month_combined << move | ans;
            // if the month_temp not in months
            // the largest number of days in a month can only be 30
            int months[] = {4,6,9,11};
            int l = 0;
            for (; l < 7; l++)
            {
                if (months[l]== month_temp && days == 31)
                {
                    
                    invalid = 1;
                    break;
                }
            }
            // we assume the largest number of days in Feb is 28
            if ((month_temp == 2 && days >= 29))
            {
                invalid = 1;
            }
            // check for invalid months
            // 1 <= months <= 12
            else if (month_temp < 1 || month_temp > 12)
            {
               
                invalid = 1;
            }
            
            if (invalid == 1)
            {
                printf("INVALID\n");
            }
            else
            {
                printf("%d\n",final_ans);
            }
        }
    }
}
