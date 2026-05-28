#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void* t1(void* arg){
    for(int i=0;i<5;i++){
        printf("Thread A is printing \n");
        sleep(1);
    }
    return NULL;
}

void* t2(void* arg){
    for(int i=0;i<5;i++){
        printf("Thread B is printing \n");
        sleep(1);
    }
    return NULL;
}

void* t3(void* arg){
    for(int i=0;i<5;i++){
        printf("Thread C is printing \n");
        sleep(1);
    }
    return NULL;
}

int main(){
    pthread_t thread1, thread2, thread3;

    pthread_create(&thread1, NULL, t1, NULL);
    pthread_create(&thread2, NULL, t2, NULL);
    pthread_create(&thread3, NULL, t3, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);

    printf("Main Thread: All threads finished.\n");
    return 0;
}

