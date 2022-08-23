#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main()
{
	FILE *file;
	file = fopen("Project4Input.txt","r");

	// we check the null case
	if (file == NULL)
	{
		printf("Sorry, the table doesn't exist. Try again.");
		exit(1);
	}
	// we use three 2-d int arrays
	// which work as a simple dictionary
	// for safety, I set the maximum set number to be 4
	// the maximum number of tag to be 500
	// here is 500, but I will expalin it more in details in the following
	int tlb[4][1000];
	int tlb_progress[100][2];
	

	int cache[17][6];
	int cache_i = 0;
	int cache_j = 0;

	int page[100][3];
	int page_i = 0;

	// tell the users that we begin to load input file
	printf("Begin to load input file...\n\n");
	

	// we read the table line by line
	// by using dynamically memory
	char *line = malloc(sizeof(char *));
	while (fgets(line,256,file))
	{
		char *temp = strdup(line);
		char *token = strtok(temp, ",");

		char *new_line[10];
		int i = 0;
		while (token != NULL)
		{
			new_line[i] = malloc(sizeof(token));
			new_line[i] = token;
	
			// and we create a new 
			new_line[i++] = token;
			
			token = strtok(NULL, ","); 
		}

		// we check which array to put data in
		char *type = new_line[0];
		if (strcmp(type,"TLB") == 0)
		{
			// if the type is TLB, we define:
			// tlb[i][j], i ---> the set index
			// j: the index of tag
			// j+1: the index of PPN
		
			int tlb_i = (int)strtol(new_line[1], NULL, 16);
			int tlb_j = tlb_progress[tlb_i][0];
			tlb[tlb_i][tlb_j] = (int)strtol(new_line[2], NULL, 16);
      		tlb[tlb_i][tlb_j+1] = (int)strtol(new_line[3], NULL, 16);
      		tlb_j = tlb_j + 2;
      		tlb_progress[tlb_i][0] = tlb_j; // we record the last tag and ppn of the current set
      		
      		
		}
		else if (strcmp(type,"Page") == 0)
		{
			// if the type is Page, we define:
			// page[i] ---> i: vpn
			// page[i][0] ---> j: ppn
			// page[i][1] ---> if it exists (we care about the case if vpn is 0 / ppn is 0), it will
			// become 999
			page_i = (int)strtol(new_line[1], NULL, 16);
			page[page_i][0] = (int)strtol(new_line[2], NULL, 16);
			page[page_i][1] = 999;

		}
		else if (strcmp(type,"Cache") == 0)
		{
			// if it is cache, we just use the index i as the index
			// and tag, offset will follow the j index
			cache_i = (int)strtol(new_line[1], NULL, 16);
			cache[cache_i][0] = (int)strtol(new_line[2], NULL, 16); // record tag
			cache[cache_i][1] = (int)strtol(new_line[3], NULL, 16); // offset 0
			cache[cache_i][2] = (int)strtol(new_line[4], NULL, 16); // offset 1
			cache[cache_i][3] = (int)strtol(new_line[5], NULL, 16); // offset 2
			cache[cache_i][4] = (int)strtol(new_line[6], NULL, 16); // offset 3
		}
		else
		{
			// that shows that we should end our loop
			// we have entered mode 4
			break;
		}
		
	}
	free(line); // we free the dynamic memory as we have finished its use

	printf("... Finish loading input files.\n");
	// now we can ask the user for the virtual address he wants to check
	int answer;
	printf("Enter Virtual Address: ");
	scanf("%x", &answer); 

    // now we begin to slice it in its binary form


	
	// here, tlbi is the index
	int offset = answer & 0b11;
	int tlbi = (answer >> 6) & 0b11;
	int tlbt = answer >>8;
	int vpn = answer >> 6;

	int ppn_ans;
	int found = 0;
	// first, we search in TLB
	int k = 0;
	for (k = 0; k < tlb_progress[tlbi][0];k += 2) // +=2: we only chec tags
	{
		if (tlb[tlbi][k] == tlbt) // that means we have found the tag
		{
			
			ppn_ans = tlb[tlbi][k+1];
			// we change the flag for finding the ppn
			found = 1;
			break;
		}
	}

	// we check the case that we don't find
	if (!found)
	{
		// we check page table
		if (page[vpn][1] == 999)
		{
			// that means we have found it in page table
			ppn_ans = page[vpn][0];
			found = 1;
		}
	}

	if (found) // if we still don't find it, we tell the user the input is invalid.
	{ 
		

	// we output the address in hex
	int final = 0;

	for (k = 0; k < 16; k++)
	{
		// we have found the tag
		if (cache[k][0] == ppn_ans)
		{
			final = cache[k][offset];
			break;
		}
	}
	// tell the user the hex physical address
	printf("The physical address is: %x\n",final);
	}
	else
	{
		printf("The address you input is not valid. Try again!\n");
		exit(0);
	}



	
	

	

}