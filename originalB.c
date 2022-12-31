#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include<pthread.h>

int a = 1;
int b = 0;
int c = 1;
int d = 0;
int e = 0;

void* philosopherA(void *arg){
    int temp;
    while(1){
    if (temp!=a)
    {
        temp = a;
        printf("A is eating with forks m3 and m4\n");
        sleep(5);
        b++;
        printf("A is thinking\n");
    }
    }

    return NULL;
}
void* philosopherB(void *arg){
    int temp;
    while(1){
    if (temp!=b)
    {
        temp = b;
        printf("B is eating with forks m4 and m5\n");
        sleep(5);
        c++;
        printf("B is thinking\n");
    }
    }
    return NULL;
}
void* philosopherC(void *arg){
    int temp;
    while(1){
    if (temp!=c)
    {
        temp = c;
        printf("C is eating with forks m1 and m5\n");
        sleep(5);
        d++;
        printf("C is thinking\n");
    }
    }
    return NULL;
}
void* philosopherD(void *arg){
    int temp;
    while(1){
    if (temp!=d)
    {
        temp = d;
        printf("D is eating with forks m1 and m2\n");
        sleep(5);
        e++;
        printf("D is thinking\n");
    }
    }
    return NULL;
}
void* philosopherE(void *arg){
    int temp;
    while(1){
    if (temp!=e)
    {
        temp = e;
        printf("E is eating with forks m2 and m3\n");
        sleep(5);
        a++;
        printf("E is thinking\n");
    }
    }
    return NULL;
}

int main(){
    pthread_t thread1, thread2, thread3, thread4, thread5;
    pthread_create(&thread1, NULL, philosopherA, NULL);
    pthread_create(&thread2, NULL, philosopherB, NULL);
    pthread_create(&thread3, NULL, philosopherC, NULL);
    pthread_create(&thread4, NULL, philosopherD, NULL);
    pthread_create(&thread5, NULL, philosopherE, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);
    pthread_join(thread4, NULL);
    pthread_join(thread5, NULL);
    return 0;
}