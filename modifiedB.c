#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include<pthread.h>

int a = 1;
int b = 0;
int c = 1;
int d = 0;
int e = 0;
int A=0, B=0;
void* philosopherA(void *arg){
    int temp;
    while(1){
    if (temp!=a)
    {
        temp = a;
        A = 1;
        printf("A is eating with forks m3 and m4 and bowl 1\n");
        sleep(5);
        printf("A is thinking\n");
        A = 0;
        b++;
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
        B = 1;
        printf("B is eating with forks m4 and m5 and bowl 2\n");
        sleep(5);
        printf("B is thinking\n");
        B = 0;
        c++;
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
        printf("C is eating with forks m1 and m5 and bowl 2\n");
        sleep(5);
        printf("C is thinking\n");
        d++;
    }
    }
    return NULL;
}
void* philosopherD(void *arg){
    int temp, local;
    while(1){
    if (temp!=d)
    {
        temp = d;
        usleep(100000);
        while(1){
        if (A==1)
        {
            local = 2;
            break;
        }
        if(B==1)
        {
            local = 1;
            break;
        }
        }
        printf("D is eating with forks m1 and m2 and bowl %d\n",local);
        usleep(4900000);
        printf("D is thinking\n");
        e++;
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
        printf("E is eating with forks m2 and m3 and bowl 1\n");
        sleep(5);
        printf("E is thinking\n");
        a++;
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