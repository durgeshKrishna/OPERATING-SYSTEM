#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct
{
    char dname[10],fname[10][10];
    int fcnt;
}dir[10];
void main()
{
    int i,ch,dcnt,k,flag=1;
    char f[30], d[30];
    // clrscr();
    dcnt=0;
    printf("\n TWO LEVEL DIRECTORY ");
    while(1)
    {
        printf("\n1. Create Directory\n2. Create File\n3. Delete File");
        printf("\n4. Search File\n5. Display\n6. Exit\nEnter your choice --");
        scanf("%d",&ch);
    switch(ch)
    {
        case 1: 
        	b:
        	printf("\nEnter name of directory -- ");
                if(dcnt==0){
                scanf("%s", dir[dcnt].dname);
                dir[dcnt].fcnt=0;
               
            }
            else{
            	scanf("%s",d);
            	for(int i=0;i<dcnt;i++){
            		if(strcmp(d, dir[i].dname)==0){
                        		flag=0;break;
                        	}
                        	else{
                        		flag=1;
                        	}
            	}
            	if(flag) strcpy(dir[dcnt].dname,d);
                else{
                	printf("\n DIRECTORY ALREADY EXIST\n");
                        	goto b;
                }
            }
            printf("Directory created");
            dcnt++;
            break;

        case 2: printf("\nEnter name of the directory -- ");
                scanf("%s",d);
                for(i=0;i<dcnt;i++)
                    if(strcmp(d,dir[i].dname)==0)
                    {
                        a:
                        printf("Enter name of the file -- ");
                        scanf("%s",f);
                        for(int y=0;y< dir[i].fcnt;y++){
                        	if(strcmp(f, dir[i].fname[k])==0){
                        		flag=0;break;
                        	}
                        	else{
                        		flag=1;
                        	}
                        }
                        if(flag) strcpy(dir[i].fname[dir[i].fcnt],f);
                        else 
                        {
                            printf("\n FILE ALREADY  EXIST\n");
                        	goto a;
                        }
                        dir[i].fcnt++;
                        printf("File created");
                        break;
                    }
                if(i==dcnt)
                    printf("Directory %s not found",d);
                break;

        case 3: printf("\nEnter name of the directory -- ");
                scanf("%s",d);
                for(i=0;i<dcnt;i++)
                {
                    if(strcmp(d,dir[i].dname)==0)
                    {
                        printf("Enter name of the file -- ");
                        scanf("%s",f);
                        for(k=0;k<dir[i].fcnt;k++)
                        {
                            if(strcmp(f, dir[i].fname[k])==0)
                            {
                                printf("File %s is deleted ",f);
                                dir[i].fcnt--;
                                strcpy(dir[i].fname[k],dir[i].fname[dir[i].fcnt]);
                                goto jmp;
                            }
                        }

                    printf("File %s not found",f);
                    goto jmp;
                }
                }

                printf("Directory %s not found",d);
                jmp : break;

        case 4: printf("\nEnter name of the directory -- ");
                scanf("%s",d);
                for(i=0;i<dcnt;i++)
                {
                    if(strcmp(d,dir[i].dname)==0)
                    {
                        printf("Enter the name of the file -- ");
                        scanf("%s",f);
                        for(k=0;k<dir[i].fcnt;k++)
                        {
                            if(strcmp(f, dir[i].fname[k])==0)
                            {
                                printf("File %s is found ",f);
                                goto jmp1;
                            }
                        }
                        printf("File %s not found",f);
                        goto jmp1;
                    }
                }
                printf("Directory %s not found",d);
                jmp1: break;
        case 5: if(dcnt==0)
                    printf("\nNo Directory's ");
                else
                {
                    printf("\nDirectory\tFiles");
                    for(i=0;i<dcnt;i++)
                    {
                        printf("\n%s\t\t",dir[i].dname);
                        for(k=0;k<dir[i].fcnt;k++)
                        printf("\t%s",dir[i].fname[k]);
                    }
                }
                break;
        default:exit(0);
    }
}
// getch();
}