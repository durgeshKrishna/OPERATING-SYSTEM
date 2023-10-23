#include <stdio.h>

void implimentFirstFit(int blockSize[], int blocks, int processSize[], int processes)
{
    int allocate[processes];
    int occupied[blocks];
    for(int i = 0; i < processes; i++)
	{
		allocate[i] = -1;
	}
	for(int i = 0; i < blocks; i++){
        occupied[i] = 0;
    }
	for (int i = 0; i < processes; i++)
    {
        for (int j = 0; j < blocks; j++) 
        { 
        if (!occupied[j] && blockSize[j] >= processSize[i])
            {
                // allocate block j to p[i] process
                allocate[i] = j;
                occupied[j] = 1;
 
                break;
            }
        }
    }

    printf("\nProcess No.\tProcess Size\tBlock no.\n");
    for (int i = 0; i < processes; i++)
    {
        printf("%d \t\t\t %d \t\t\t", i+1, processSize[i]);
        if (allocate[i] != -1)
            printf("%d\n",allocate[i] + 1);
        else
            printf("Not Allocated\n");
    }
}
void main()
{
    int blockSize[100], processSize[100] ,m,n;
    printf("\n ----- FIRST FIT -----");
    printf("\n Enter the number of process ");
    scanf("%d",&m);
    for(int i=0;i<m;i++){
        scanf("%d",&processSize[i]);
     }
     printf("\n Enter the number of blocks ");
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        scanf("%d",&blockSize[i]);
     }
    implimentFirstFit(blockSize, m, processSize, n);
}
