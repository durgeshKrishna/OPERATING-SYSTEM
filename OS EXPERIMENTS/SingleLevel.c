#include<stdio.h>
#include<string.h>
int main()
{
	int nf=0,i=0,j=0,ch;
	char mdname[10],fname[10][10],name[10];
	printf("\n Enter the directory name:");
	scanf("%s",mdname);
	printf("\n Enter the number of files:");
	scanf("%d",&nf);
	for(int k=0;k<nf;k++)
		{
			printf("Enter file name to be created:");
			scanf("%s",name);
			for(i=0;i<nf;i++)
			{
				if(!strcmp(name,fname[i]))
				{
					    nf++;
						break;
				}
		    }
		if(i==nf)
			{
				strcpy(fname[j++],name);
				//nf++;	
			}
		else
		printf("There is already %s\n",name);
		
		}
printf("\n Directory name is:%s\n",mdname);
printf("\nFiles names are:");
	for(i=0;i<j;i++)
		printf("\n%s",fname[i]);
	return 0;
}


