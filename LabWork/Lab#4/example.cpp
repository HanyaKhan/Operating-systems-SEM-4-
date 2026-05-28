#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
void* evenNumber(void* arg){
for(int i=0;i<=10;i+=2){
printf("Even Thread :%d\n",i);
sleep(1);
}
return NULL;
}
void * oddNumber(void*arg){
for(int i=1;i<10;i+=2){
printf("Odd number : %d\n",i);
sleep(1);
}
return NULL;
}

int main(){
pthread_t thread1,thread2;
pthread_create(&thread1,NULL,evenNumber,NULL);
pthread_create(&thread2,NULL,oddNumber,NULL);

pthread_join(thread1,NULL);
pthread_join(thread2,NULL);

printf("Main Thread");
}
