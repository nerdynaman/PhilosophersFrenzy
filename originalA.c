#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include<semaphore.h>
#include<fcntl.h>
#include<pthread.h>

sem_t *m1, *m2, *m3, *m4, *m5;

void* philosopherA(void *arg){
    printf("in process a\n");
    while(1){
        if(sem_wait(m3)<0){
            perror("error in sem_wait");
        };
        if(sem_wait(m4)<0){
            perror("error in sem_wait");
        };
        printf("A is eating with forks m3 and m4\n");
        sleep(5);
        if(sem_post(m3)<0){
            perror("error in sem_post");
        };
        if(sem_post(m4)<0){
            perror("error in sem_post");
        };
        printf("A is thinking\n");
        sleep(5);   
    }

    return NULL;
}
void* philosopherB(void *arg){
    printf("in process b\n");
    // printf("in process b: d %d e %d\n", d, e);
    while (1)
    {
        if(sem_wait(m4)<0){
            perror("error in sem_wait");
        };
        if(sem_wait(m5)<0){
            perror("error in sem_wait");
        };
        printf("B is eating with forks m4 and m5\n");
        sleep(5);
        if(sem_post(m4)<0){
            perror("error in sem_post");
        };
        if(sem_post(m5)<0){
            perror("error in sem_post");
        };
        printf("B is thinking\n");
        sleep(5);
    }
    
    return NULL;
}
void* philosopherC(void *arg){
    printf("in process c\n");
    // printf("in process c: e %d a %d\n", e, a);
    while (1)
    {
        if(sem_wait(m5)<0){
            perror("error in sem_wait");
        };
        if(sem_wait(m1)<0){
            perror("error in sem_wait");
        };
        printf("C is eating with forks m1 and m5\n");
        sleep(5);
        if(sem_post(m5)<0){
            perror("error in sem_post");
        };
        if(sem_post(m1)<0){
            perror("error in sem_post");
        };
        printf("C is thinking\n");
        sleep(5);
    }
    return NULL;
}
void* philosopherD(void *arg){
    printf("in process d\n");
    // printf("in process d: a %d b %d\n", a, b);
    while (1)
    {
        if(sem_wait(m1)<0){
            perror("error in sem_wait");
        };
        if(sem_wait(m2)<0){
            perror("error in sem_wait");
        };
        printf("D is eating with forks m1 and m2\n");
        sleep(5);
        if(sem_post(m1)<0){
            perror("error in sem_post");
        };
        if(sem_post(m2)<0){
            perror("error in sem_post");
        };
        printf("D is thinking\n");
        sleep(5);
    }
    return NULL;
}
void* philosopherE(void *arg){
    printf("in process e\n");
    // printf("in process e: b %d c %d\n", b, c);
    while (1)
    {
        if(sem_wait(m2)<0){
            perror("error in sem_wait");
        };
        if(sem_wait(m3)<0){
            perror("error in sem_wait");
        };
        printf("E is eating with forks m2 and m3\n");
        sleep(5);
        if(sem_post(m2)<0){
            perror("error in sem_post");
        };
        if(sem_post(m3)<0){
            perror("error in sem_post");
        };
        printf("E is thinking\n");
        sleep(5);
    }
    return NULL;
}

int main(){
    // m{1,2,3,4,5} are the semaphores file descriptors(fork) used by the philosophers.
    // m1 is the semaphore for the fork between A and B and so on.
    int a = sem_unlink("m1");
    if(a<0){
        perror("error in sem_unlink");
    }
    a = sem_unlink("m2");
    if(a<0){
        perror("error in sem_unlink");
    }
    a = sem_unlink("m3");
    if(a<0){
        perror("error in sem_unlink");
    }
    a = sem_unlink("m4");
    if(a<0){
        perror("error in sem_unlink");
    }
    a = sem_unlink("m5");
    if(a<0){
        perror("error in sem_unlink");
    }
    m1 = sem_open("m1", O_CREAT, 0644, 1);
    m2 = sem_open("m2", O_CREAT, 0644, 1);
    m3 = sem_open("m3", O_CREAT, 0644, 1);
    m4 = sem_open("m4", O_CREAT, 0644, 1);
    m5 = sem_open("m5", O_CREAT, 0644, 1);
    if (m1 == SEM_FAILED || m2 == SEM_FAILED || m3 == SEM_FAILED || m4 == SEM_FAILED || m5 == SEM_FAILED)
    {
        perror("error in sem_open");
        exit(1);
    }
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