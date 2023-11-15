#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <semaphore.h>
#include <pthread.h>
#include <unistd.h>
sem_t chopstick[5];
void *philos(void *);
void eat(int);
void main(){
 int i,n[5];
 pthread_t T[5];
 for(i=0;i<5;i++)
 sem_init(&chopstick[i],0,1);
 for(i=0;i<5;i++){
 n[i] = i;
 pthread_create(&T[i],NULL,philos,(void *)&n[i]);
 }
 for(i=0;i<5;i++)
 pthread_join(T[i],NULL);
	exit(1);
}
void *philos(void * n){
 int ph = *(int *)n;
 printf("Philosopher ->%d wants to eat\n",ph+1);
 printf("Philosopher ->%d tries to pickup left chopstick\n",ph+1);
 sem_wait(&chopstick[ph]);
 printf("Philosopher ->%d picks left chopstick\n",ph+1);
printf("Philosopher ->%d tries to pickup right chopstick\n",ph+1);
 sem_wait(&chopstick[(ph+1)%5]);
 printf("Philosopher ->%d picks right chopstick\n",ph+1);
 eat(ph+1);
 sleep(1); //critical section
 printf("Philosopher ->%d finished eating\n",ph+1);
 sem_post(&chopstick[(ph+1)%5]);
 printf("Philosopher ->%d leaves right chopstick\n",ph+1);
 sem_post(&chopstick[ph]);
 printf("Philosopher ->%d leaves left chopstick\n",ph+1);
}
void eat(int num){ printf("Philosopher ->%d begins eating\n",num); }
	
