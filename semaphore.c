#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h> //semaphore를 쓰기위해 추가

typedef struct __lock_t {
    int value;
    sem_t sem ;
} lock_t;

unsigned int loop_cnt;
lock_t counter;

//초기화 함수
void init(lock_t *c, int initial) {
    c->value = 0;
    sem_init(&c->sem,0,initial);
}

void increment(lock_t *c) {
    sem_wait(&c->sem); //감소, 값이 0이면 대기
    c->value++;
    sem_post(&c->sem); //세마포어의 값을 증가시킴
}

void decrement(lock_t *c) {
    sem_wait(&c->sem); 
    c->value--;
    sem_post(&c->sem);
}

int get(lock_t *c) {
    sem_wait(&c->sem);
    int rc = c->value;
    sem_post(&c->sem);
    return rc;
}

void *mythread(void *arg)
{
    char *letter = arg;
    int i;

    printf("%s: begin\n", letter);
    for (i = 0; i < loop_cnt; i++) {
        increment(&counter);
    }
    printf("%s: done\n", letter);
    return NULL;
}

int main(int argc, char *argv[])
{                    
    loop_cnt = atoi(argv[1]);
    int initial= 1; //초기값을 1로 줌(이진 세마포어)

    init(&counter,initial);

    pthread_t p1, p2;
    printf("main: begin [counter = %d]\n", get(&counter));
    pthread_create(&p1, NULL, mythread, "A"); 
    pthread_create(&p2, NULL, mythread, "B");
    // join waits for the threads to finish
    pthread_join(p1, NULL); 
    pthread_join(p2, NULL); 
    printf("main: done [counter: %d] [should be: %d]\n", get(&counter), loop_cnt * 2);
    return 0;
}
