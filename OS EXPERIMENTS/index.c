//GNU nano 6.2    
#include<stdio.h>                                                                                                                                                                     Indexed_alloc.c                                                                                                                                                                                  #include<stdio.h>
#include<stdlib.h>
//INDEXED ALLOCATION:

void main(){
        int count,ch,f[50],file=0,i,block,index[50],tot_b;
        for(i=0; i<50; i++)
                f[i] = 0;
        a:
        printf("Index Block of file %d: ",++file); scanf("%d",&block);
        if(f[block] == 0){
                printf("Enter the No.of Blocks : ");
                scanf("%d",&tot_b);
        }
        else{
                printf("File Not Allocated\n");
                --file;
                goto a;
        }
        //check:
        b:
        count=0;
        printf("Enter %d Blocks : ",tot_b);
        for(i=0; i<tot_b; i++){
                //printf("Block %d : ",i+1);
                scanf("%d",&index[i]);
                if(f[index[i]] == 0)
                        count++;
        }
        //count == len/n
        if(count == tot_b){
                for(i=0; i<tot_b; i++){
                        f[index[i]] = 1;
                        printf("BLOCK:%d ----> File:%d\n",index[i],file);
                }
        }
        else{
                printf("File Not Allocated\n");
                goto b;
        }
        printf("Want to continue : ");
        scanf("%d",&ch);
        if(ch != -1)
                goto a;
        else
                exit(-1);

}