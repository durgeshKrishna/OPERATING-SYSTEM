                                                                             seq_cont.c                                                                                                 #include<stdio.h>
#include<stdlib.h>

//SEQ--ALLOCATION:

void main(){
        int file=0,f[50],i,count,len,st_blk,ch;
        for(i=0; i<50; i++)
                f[50] = 0;
        a:
        printf("Enter the Length of file %d : ",++file);
        scanf("%d",&len);
        printf("Enter the Starting Block : ");
        scanf("%d",&st_blk);
        count = 0;
        //check
        for(i=st_blk; i<(st_blk+len); i++){
                if(f[i] == 0)
                        count++;
        }
        //count == len:
        if(count == len){
                for(i = st_blk; i<st_blk+len; i++){
                        f[i] = 1;
                        printf("%dth Block<->AllocatedFile %d\n",i,file);
                }
        }
        else{
                printf("Not Allocated\n");
        }
        printf("Want to continue : "); scanf("%d",&ch);
        if(ch != -1)
                goto a;
        else
                exit(-1);
}